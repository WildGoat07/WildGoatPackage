#include "JSON.hpp"

using namespace wp::JSON;

std::string JSONParser::getValueString(Value* value) const
{
    if (value == nullptr)
        return "";
    uint8_t type = value->getType();
    std::string res;
    if (type == Value::NUMBER_TYPE)
    {
        res = wp::Various::doubleToString(value->interpret<Number>()->value);
    }
    else if (type == Value::BOOLEAN_TYPE)
    {
        if (value->interpret<Boolean>()->value)
            res = "true";
        else
            res = "false";
    }
    else if (type == Value::STRING_TYPE)
    {
        res = "\"" + value->interpret<String>()->value + "\"";
    }
    else if (type == Value::NULL_TYPE)
    {
        res = "null";
    }
    else if (type == Value::ARRAY_TYPE)
    {
        Array* var = value->interpret<Array>();
        res = "[ ";

        for (Array::valueType::iterator it = var->values.begin();it!=var->values.end();it++)
        {
            res += getValueString(it->get());
            {
                Array::valueType::iterator tmp = it;
                tmp++;
                if (tmp != var->values.end())
                    res +=", ";
            }
        }
        res += " ]";
    }
    else if (type == Value::OBJECT_TYPE)
    {
        Object* var = value->interpret<Object>();
        res = "{ ";

        for (Object::valueType::iterator it = var->values.begin();it!=var->values.end();it++)
        {
            res += "\"" + it->first + "\" : ";
            res += getValueString(it->second.get());
            {
                Object::valueType::iterator tmp = it;
                tmp++;
                if (tmp != var->values.end())
                    res +=", ";
            }
        }
        res += " }";
    }



    return res;
}

std::string const& JSONParser::getJSONString() const
{
    if (m_content != nullptr)
        m_buff = getValueString(m_content.get());
    else
        m_buff = "";
    return m_buff;
}
void JSONParser::parseJSON(std::string const& str)
{
    size_t cursor = 0;
    pushCurs(str, cursor);
    m_content = getValueFromString(str, cursor);
}
shared_ptr<Value> JSONParser::getValue() const
{
    return m_content;
}
void JSONParser::setContent(shared_ptr<Value> val)
{
    m_content = val;
}
bool JSONParser::pushCurs(std::string const& str, size_t& curs) const
{
    bool fin = false;
    while( !fin)
    {
        char car = str[curs];
        if (car != ' ' && car != '\n')
        {
            fin = true;
        }
        else
        {
            curs++;
            if (curs >= str.size())
                return false;
        }
    }
    return true;
}
shared_ptr<Value> JSONParser::getValueFromString(std::string const& str, size_t& curs) const
{
    char car = str[curs];

    if (car == '"')
    {
        curs++;
        if (curs >= str.size())
            return shared_ptr<Value>();
        shared_ptr<String> val(new String());
        bool fin = false;
        while (!fin)
        {
            car = str[curs];
            if (car == '"')
                fin = true;
            else if (car == '\\')
            {
                curs++;
                if (curs >= str.size())
                    return shared_ptr<Value>();
                car = str[curs];
                if (car == '"')
                    ;
                else if (car == 'n')
                    car = '\n';
                else if (car == '\\')
                    car = '\\';
                else if (car == '/')
                    car = '/';
                else if (car == 'b')
                    car = '\b';
                else if (car == 'n')
                    car = '\n';
                else if (car == 'r')
                    car = '\r';
                else if (car == 't')
                    car = '\t';
            }
            if (!fin)
            val->value += car;
            curs++;
            if (curs >= str.size() && !fin)
                return shared_ptr<Value>();
        }
        return val;
    }
    else if (car == '[')
    {
        shared_ptr<Array> val(new Array);
        curs++;
        if (curs >= str.size())
            return shared_ptr<Value>();
        while (true)
        {
            pushCurs(str, curs);
            if (curs >= str.size())
                return shared_ptr<Value>();
            if (str[curs] == ']')
            {
                curs++;
                return val;
            }
            val->values.push_back(getValueFromString(str, curs));
            pushCurs(str, curs);
            if (curs >= str.size())
                return shared_ptr<Value>();
            if (str[curs] == ',')
                curs++;
        }
    }
    else if (car == '{')
    {
        shared_ptr<Object> val(new Object);
        curs++;
        if (curs >= str.size())
            return shared_ptr<Value>();
        while (true)
        {
            std::string tmp;
            pushCurs(str, curs);
            if (curs >= str.size())
                return shared_ptr<Value>();
            if (str[curs] == '}')
            {
                curs++;
                return val;
            }
            shared_ptr<Value> tmp2 = getValueFromString(str, curs);
            if (tmp2->getType() == Value::STRING_TYPE)
                tmp = tmp2->interpret<String>()->value;
            else
                return shared_ptr<Value>();
            pushCurs(str, curs);
            if (curs >= str.size())
                return shared_ptr<Value>();
            if (str[curs] == ':')
                curs++;
            else
                return shared_ptr<Value>();
            pushCurs(str, curs);
            if (curs >= str.size())
                return shared_ptr<Value>();
            val->values[tmp] = getValueFromString(str, curs);
            pushCurs(str, curs);
            if (curs >= str.size())
                return shared_ptr<Value>();
            if (str[curs] == ',')
                curs++;
        }
    }
    else if (car == '-' || (car >= '0' && car <= '9'))
    {
        shared_ptr<Number> val(new Number());
        std::string tmpString;
        int level = 1;
        if (car == '-')
        {
            tmpString += car;
            curs++;
            if (curs >= str.size())
                return shared_ptr<Value>();
        }
        while (true)
        {
            if (level == 1)
            {
                car = str[curs];
                if (car >= '0' && car <= '9')
                {
                    tmpString += car;
                }
                else if (car == '.')
                {
                    tmpString += car;
                    level = 2;
                }
                else if (car == 'e' || car == 'E')
                {
                    tmpString += car;
                    level = 3;
                }
                else
                {
                    val->value = wp::Various::stringToDouble(tmpString);
                    return val;
                }
            }
            else if (level == 2)
            {
                car = str[curs];
                if (car >= '0' && car <= '9')
                {
                    tmpString += car;
                }
                else if (car == 'e' || car == 'E')
                {
                    tmpString += car;
                    level = 3;
                }
                else
                {
                    val->value = wp::Various::stringToDouble(tmpString);
                    return val;
                }
            }
            else if (level == 3)
            {
                car = str[curs];
                if (car == '+' || car == '-')
                {
                    tmpString += car;
                }
                else if (car >= '0' && car <= '9')
                {
                    level = 4;
                }
                else
                {
                    val->value = wp::Various::stringToDouble(tmpString);
                    return val;
                }
            }
            if (level == 4)
            {
                car = str[curs];
                if (car >= '0' && car <= '9')
                {
                    tmpString += car;
                }
                else
                {
                    val->value = wp::Various::stringToDouble(tmpString);
                    return val;
                }
            }
            curs++;
            if (curs >= str.size())
            {
                val->value = wp::Various::stringToDouble(tmpString);
                return val;
            }
        }
    }
    else if (car == 't' || car == 'f')
    {
        shared_ptr<Boolean> val(new Boolean());
        std::string tmpString;
        char nextCar = 0;
        if (car == 't')
        {
            val->value = true;
            tmpString += car;
            curs++;
            if (curs >= str.size())
                return shared_ptr<Value>();
            while (true)
            {
                if (car == 't')
                    nextCar = 'r';
                if (car == 'r')
                    nextCar = 'u';
                if (car == 'u')
                    nextCar = 'e';
                car = str[curs];
                if (car == nextCar)
                {
                    if (car == 'e')
                    {
                        curs++;
                        return val;
                    }
                }
                else
                    return shared_ptr<Value>();
                curs++;
                if (curs >= str.size())
                    return shared_ptr<Value>();
            }
        }
        else if (car == 'f')
        {
            val->value = false;
            tmpString += car;
            curs++;
            if (curs >= str.size())
                return shared_ptr<Value>();
            while (true)
            {
                if (car == 'f')
                    nextCar = 'a';
                if (car == 'a')
                    nextCar = 'l';
                if (car == 'l')
                    nextCar = 's';
                if (car == 's')
                    nextCar = 'e';
                car = str[curs];
                if (car == nextCar)
                {
                    if (car == 'e')
                    {
                        curs++;
                        return val;
                    }
                }
                else
                    return shared_ptr<Value>();
                curs++;
                if (curs >= str.size())
                    return shared_ptr<Value>();
            }
        }
    }
    else if (car == 'n')
    {
        shared_ptr<Null> val(new Null());
        std::string tmpString;
        char nextCar = 0;
        tmpString += car;
        int count = 0;
        curs++;
        if (curs >= str.size())
            return shared_ptr<Value>();
        while (true)
        {
            if (car == 'n')
                nextCar = 'u';
            if (car == 'u')
                nextCar = 'l';
            car = str[curs];
            if (car == nextCar)
            {
                count ++;
            }
            else
                return shared_ptr<Value>();
            if (count == 3)
            {
                curs++;
                return val;
            }
            curs++;
            if (curs >= str.size())
                return shared_ptr<Value>();
        }
    }
    else
    {
        return shared_ptr<Value>();
    }
}

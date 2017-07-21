#include "Data.hpp"

using namespace wp;


Data::Value::Value(long long v)
{
    setInt(v);
}
Data::Value::Value(long double v)
{
    setDouble(v);
}
Data::Value::Value(std::string const& v)
{
    setString(v);
}
std::shared_ptr<Data::Value> Data::append(std::string const& ID)
{
    if (m_data.find(ID) == m_data.end())
    {
        m_requestUpdate = true;
        m_data[ID] = std::shared_ptr<Data::Value>(new Data::Value());
        m_data[ID]->m_parent = this;
    }
    return get(ID);
}
void Data::append(std::string const& ID, std::shared_ptr<Data::Value> v)
{
    if (m_data.find(ID) == m_data.end())
    {
        m_requestUpdate = true;
        m_data[ID] = v;
        m_data[ID]->m_parent = this;
    }
}
std::string const& Data::getString() const
{
    if (m_requestUpdate)
    {
        m_requestUpdate = false;
        m_render = "";
        for (Data::const_iterator it = begin();it!=end();it++)
        {
            const std::string* head = &it->first;
            const std::string* dat = &it->second->getString();
            if (it != begin())
                m_render += "\\0";
            for (int i = 0;i<head->size();i++)
            {
                char charactere = (*head)[i];
                m_render += charactere;
                if (charactere == '\\')
                    m_render += '\\';
            }
            m_render += "\\0";
            for (int i = 0;i<dat->size();i++)
            {
                char charactere = (*dat)[i];
                m_render += charactere;
                if (charactere == '\\')
                    m_render += '\\';
            }
        }
    }
    return m_render;
}
void Data::load(std::string const& str)
{
    m_data.clear();
    size_t cursor = 0;
    bool fin = false;
    while(!fin)
    {
        std::string head;
        std::string dat;
        bool fin2 = false;
        while(!fin2)
        {
            char charactere = str[cursor];
            cursor++;
            if (charactere == '\\')
            {
                charactere = str[cursor];
                cursor++;
                if (charactere == '0')
                    fin2 = true;
                else
                    head += charactere;
            }
            else
                head += charactere;
        }
        fin2 = false;
        while(!fin2)
        {
            if (cursor != str.size())
            {
                char charactere = str[cursor];
                cursor++;
                if (charactere == '\\')
                {
                    charactere = str[cursor];
                    cursor++;
                    if (charactere == '0')
                        fin2 = true;
                    else
                        dat += charactere;
                }
                else
                    dat += charactere;
            }
            else
            {
                fin2 = true;
                fin = true;
            }
        }
        append(head)->setString(dat);
    }
}

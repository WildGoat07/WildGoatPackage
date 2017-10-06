#include "RichText.hpp"
#include <iostream>
#include "Various.hpp"

using namespace wp;

RichText::Part::Part(std::string const& str, sf::Color col1, sf::Uint32 st, sf::Color col2, float th)
{
    m_return = false;
    text = str;
    fillColor = col1;
    outlineColor = col2;
    outlineThickness = th;
    style = st;
}
RichText::RichText()
{
    m_textWrapping = 0;
    m_font = nullptr;
    m_size = 0;
}
void RichText::addPart(Part const& p)
{
    std::vector<Part> subList;
    Part tmp = p;
    tmp.m_index = m_index;
    m_index++;
    tmp.text = "";
    for (int i = 0;i<p.text.size();i++)
    {
        if (p.text[i] == '\n')
        {
            tmp.m_return = true;
            subList.push_back(tmp);
            tmp.text = "";
            tmp.m_return = false;
        }
        else
        {
            tmp.text += p.text[i];
        }
    }
    if (tmp.text.size() > 0)
        subList.push_back(tmp);
    for (int i = 0;i<subList.size();i++)
        m_parts.push_back(subList[i]);
}
void RichText::nextWord(std::string const& str, int& curs) const
{
    char oldChar = str[curs];
    for (int i = curs+1;i<str.size();i++)
    {
        char newChar = str[i];
        if ((oldChar == ' ' || oldChar == '\n' || oldChar == '\t') && (newChar != ' ' && newChar != '\n' && newChar != '\t'))
        {
            curs = i;
            i = str.size();
            return;
        }
        oldChar = newChar;
    }
    curs = str.size();
}
void RichText::generate()
{
    sf::Vector2f offset;
    m_buffer.clear();
    float decal = 9999999;
    float currLength = 0;
    for (int i = 0;i<m_parts.size();i++)
    {
        if (m_textWrapping != 0)
        {
            std::vector<std::string> strs;
            std::vector<bool> subReturn;
            std::string currString;
            int curs = 0;
            bool fin = false;
            bool endOfText = false;
            while (!fin)
            {
                std::shared_ptr<sf::Text> tmp(new sf::Text());
                std::string currWord;
                int currPos = curs;
                nextWord(m_parts[i].text, curs);
                currWord = m_parts[i].text.substr(currPos, curs - currPos);
                if (currPos == m_parts[i].text.size())
                {
                    endOfText = true;
                }



                tmp->setString(currWord);
                tmp->setFillColor(m_parts[i].fillColor);
                tmp->setOutlineColor(m_parts[i].outlineColor);
                tmp->setOutlineThickness(m_parts[i].outlineThickness);
                tmp->setStyle(m_parts[i].style);
                tmp->setFont(*m_font);
                tmp->setCharacterSize(m_size);
                currLength += tmp->getGlobalBounds().width;
                if (currLength > m_textWrapping)
                {
                    if (currString.size() > 0)
                        curs = currPos;
                    else
                        currString = currWord;
                    currLength = tmp->getGlobalBounds().width;
                    strs.push_back(currString);
                    currString = "";
                    subReturn.push_back(true);
                }
                else
                {
                    currString += currWord;
                }
                if (endOfText)
                {
                    subReturn.push_back(false);
                    strs.push_back(currString);
                    fin = true;
                }
            }
            for (int j = 0;j<strs.size();j++)
            {
                std::shared_ptr<sf::Text> tmp(new sf::Text());
                tmp->setString(strs[j]);
                tmp->setFillColor(m_parts[i].fillColor);
                tmp->setOutlineColor(m_parts[i].outlineColor);
                tmp->setOutlineThickness(m_parts[i].outlineThickness);
                tmp->setStyle(m_parts[i].style);
                tmp->setFont(*m_font);
                tmp->setPosition(offset);
                tmp->setCharacterSize(m_size);
                if (decal > tmp->getLocalBounds().top)
                    decal = tmp->getLocalBounds().top;
                m_buffer.push_back(tmp);
                m_indexs.push_back(m_parts[i].m_index);
                offset = tmp->findCharacterPos(m_parts[i].text.size());
                if (m_parts[i].m_return || subReturn[j])
                {
                    offset.x = 0;
                    offset.y += m_size;
                }
            }
        }
        else
        {
            std::shared_ptr<sf::Text> tmp(new sf::Text());
            tmp->setString(m_parts[i].text);
            tmp->setFillColor(m_parts[i].fillColor);
            tmp->setOutlineColor(m_parts[i].outlineColor);
            tmp->setOutlineThickness(m_parts[i].outlineThickness);
            tmp->setStyle(m_parts[i].style);
            tmp->setFont(*m_font);
            tmp->setPosition(offset);
            tmp->setCharacterSize(m_size);
            if (decal > tmp->getLocalBounds().top)
                decal = tmp->getLocalBounds().top;
            m_buffer.push_back(tmp);
            offset = tmp->findCharacterPos(m_parts[i].text.size());
            if (m_parts[i].m_return)
            {
                offset.x = 0;
                offset.y += m_size;
            }
        }
    }
    for (int i = 0;i<m_buffer.size();i++)
        m_buffer[i]->move(0, -decal);
}
void RichText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    for (int i = 0;i<m_buffer.size();i++)
        target.draw(*m_buffer[i], states);
}
sf::FloatRect RichText::getLocalBounds() const
{
    sf::FloatRect box;
    sf::Vector2f tmp;
    sf::FloatRect tmp2;
    for (int i = 0;i<m_buffer.size();i++)
    {
        tmp2 = m_buffer[i]->getGlobalBounds();
        tmp.x = tmp2.left + tmp2.width;
        tmp.y = tmp2.top + tmp2.height;

        if (box.width < tmp.x)
            box.width = tmp.x;
        if (box.height < tmp.y)
            box.height = tmp.y;
    }
    return box;
}
bool RichText::nextValidChar(sf::Uint16& curs, std::string const& str, sf::Uint16& row, sf::Uint16& column) const
{
    if (curs == str.size())
        return false;
    while (str[curs] == ' ' || str[curs] == '\n' || str[curs] == '\t')
    {
        if (str[curs] == '\n')
        {
            row++;
            column = 0;
        }
        curs++;
        column++;
        if (curs == str.size())
            return false;
    }
    return true;
}
bool RichText::loadJSON(std::string const& str)
{
    clear();
    sf::Uint16 cursor = 0;
    sf::Uint16 row = 1;
    sf::Uint16 column = 1;
    if (!nextValidChar(cursor, str, row, column))
    {
        std::cerr << "error : no starting\n";
        return false;
    }
    if (str[cursor] != '[')
    {
        std::cerr << "error : character '" << str[cursor] << "', expected '[' at line " << row << " and column " << column << '\n';
        return false;
    }
    cursor++;
    column++;
    if (!nextValidChar(cursor, str, row, column))
    {
        std::cerr << "error : no ending\n";
        return false;
    }
    bool end = false;
    while (!end)
    {
        Part tmp;
        if (str[cursor] != '{')
        {
            std::cerr << "error : character '" << str[cursor] << "', expected '{' at line " << row << " and column " << column << '\n';
            return false;
        }
        cursor++;
        column++;
        if (!nextValidChar(cursor, str, row, column))
        {
            std::cerr << "error : no ending\n";
            return false;
        }
        bool end2 = false;
        while (!end2)
        {
            if (str[cursor] != '"' && str[cursor] != '}')
            {
                std::cerr << "error : character '" << str[cursor] << "', expected '\"' or '}' at line " << row << " and column " << column << '\n';
                return false;
            }
            if (str[cursor] == '}')
                end2 = true;
            if (str[cursor] == '"')
            {
                std::string param;
                std::string value;
                cursor++;
                column++;
                if (cursor == str.size())
                {
                    std::cerr << "error : no ending\n";
                    return false;
                }
                while (str[cursor] != '"' && str[cursor] != '\n')
                {
                    param += str[cursor];
                    cursor++;
                    column++;
                    if (cursor == str.size())
                    {
                        std::cerr << "error : no ending\n";
                        return false;
                    }
                }
                cursor++;
                column++;
                if (!nextValidChar(cursor, str, row, column))
                {
                    std::cerr << "error : no ending\n";
                    return false;
                }
                if (str[cursor] != ':')
                {
                    std::cerr << "error : character '" << str[cursor] << "', expected ':' at line " << row << " and column " << column << '\n';
                    return false;
                }
                cursor++;
                column++;
                if (!nextValidChar(cursor, str, row, column))
                {
                    std::cerr << "error : no ending\n";
                    return false;
                }
                bool stringValue = true;
                if (str[cursor] != '"')
                {
                    stringValue = false;
                    if ((str[cursor] >= '0' && str[cursor] <= '9') || str[cursor] == '-')
                    {
                        while ((str[cursor] >= '0' && str[cursor] <= '9') || str[cursor] == '.' || str[cursor] == 'e' || str[cursor] == 'E' || str[cursor] == '+' || str[cursor] == '-')
                        {
                            value += str[cursor];
                            cursor++;
                            column++;
                            if (cursor == str.size())
                            {
                                std::cerr << "error : no ending\n";
                                return false;
                            }
                        }
                        cursor--;
                        column--;
                    }
                    else if (str.substr(cursor, 5) == "false")
                    {
                        value = wp::Various::intToString(0);
                        cursor += 4;
                        column += 4;
                    }
                    else if (str.substr(cursor, 4) == "true")
                    {
                        value = wp::Various::intToString(1);
                        cursor += 3;
                        column += 3;
                    }
                    else
                    {
                        std::cerr << "error : character '" << str[cursor] << "', expected '\"' at line " << row << " and column " << column << '\n';
                        return false;
                    }
                }
                else
                {
                    cursor++;
                    column++;
                    if (cursor == str.size())
                    {
                        std::cerr << "error : no ending\n";
                        return false;
                    }
                    while (str[cursor] != '"' && str[cursor] != '\n')
                    {
                        value += str[cursor];
                        cursor++;
                        column++;
                        if (cursor == str.size())
                        {
                            std::cerr << "error : no ending\n";
                            return false;
                        }
                    }
                }
                cursor++;
                column++;
                if (!nextValidChar(cursor, str, row, column))
                {
                    std::cerr << "error : no ending\n";
                    return false;
                }
                if (str[cursor] != ',' && str[cursor] != '}')
                {
                    std::cerr << "error : character '" << str[cursor] << "', expected ',' or '}' at line " << row << " and column " << column << '\n';
                    return false;
                }
                if (str[cursor] == '}')
                    end2 = true;
                cursor++;
                column++;
                if (!nextValidChar(cursor, str, row, column))
                {
                    std::cerr << "error : no ending\n";
                    return false;
                }
                if ((param == "text" || param == "tx") && stringValue)
                {
                    std::string res;
                    int resCur = 0;
                    for (int i = 0;i<value.size();i++)
                    {
                        char c = value[i];
                        if (c == '\\')
                        {
                            i++;
                            if (i == value.size())
                            {
                                std::cerr << "error : incomplete '\\' character in the value of the parameter \"" << param << "\"\n";
                            }
                            else
                            {
                                char cToAdd;
                                if (value[i] == '\\')
                                    cToAdd = '\\';
                                else if (value[i] == 'n')
                                    cToAdd = '\n';
                                else if (value[i] == 't')
                                    cToAdd = '\t';
                                else if (value[i] == 'b')
                                {
                                    cToAdd = '\r';
                                    if ((res.size() == resCur))
                                        res.erase(resCur-1, 1);
                                    else
                                        res.erase(resCur, 1);
                                    resCur--;
                                }
                                else if (value[i] == '"')
                                    cToAdd = '"';
                                else if (value[i] == '/')
                                    cToAdd = '/';
                                else if (value[i] == 'r')
                                {
                                    cToAdd = '\r';
                                    resCur = 0;
                                }
                                else
                                {
                                    cToAdd = '\r';
                                    std::cerr << "error : unknown character '\\" << value[i] << "'\n";
                                    i = value.size()-1;
                                }
                                if (cToAdd != '\r')
                                {
                                    if ((res.size() == resCur))
                                        res += cToAdd;
                                    else
                                        res[resCur] = cToAdd;
                                    resCur++;
                                }
                            }
                        }
                        else
                        {
                            if (res.size() == resCur)
                                res += c;
                            else
                                res[resCur] = c;
                            resCur++;
                        }
                    }
                    tmp.text = res;
                }
                else if (param == "fillColor" || param == "fc")
                {
                    sf::Uint32 colorCode;
                    bool hex = false;
                    if (value.size() == 10)
                    {
                        if (value.substr(0, 2) == "0x" && stringValue)
                        {
                            hex = true;
                            colorCode = wp::Various::hexToDec(value.substr(2, 8));
                        }
                        if (value.substr(0, 2) == "0x" && !stringValue)
                        {
                            std::cerr << "error : invalid format : \"" << value << "\" is a number, add '\"' around it\n";
                            end2 = true;
                        }
                    }
                    if (!hex && !stringValue)
                        colorCode = wp::Various::stringToDouble(value);
                    if (!hex && stringValue)
                    {
                        std::cerr << "error : invalid format : \"" << value << "\" is a string, remove the '\"'\n";
                        end2 = true;
                    }
                    tmp.fillColor = sf::Color(colorCode);
                }
                else if (param == "outlineColor" || param == "oc")
                {
                    sf::Uint32 colorCode;
                    bool hex = false;
                    if (value.size() == 10)
                    {
                        if (value.substr(0, 2) == "0x" && stringValue)
                        {
                            hex = true;
                            colorCode = wp::Various::hexToDec(value.substr(2, 8));
                        }
                        if (value.substr(0, 2) == "0x" && !stringValue)
                        {
                            std::cerr << "error : invalid format : \"" << value << "\" is a number, add '\"' around it\n";
                            end2 = true;
                        }
                    }
                    if (!hex && !stringValue)
                        colorCode = wp::Various::stringToDouble(value);
                    if (!hex && stringValue)
                    {
                        std::cerr << "error : invalid format : \"" << value << "\" is a string, remove the '\"'\n";
                        end2 = true;
                    }
                    tmp.outlineColor = sf::Color(colorCode);
                }
                else if ((param == "outlineThickness" || param == "ot") && !stringValue)
                {
                    tmp.outlineThickness = wp::Various::stringToDouble(value);
                }
                else if ((param == "bold" || param == "bo") && !stringValue)
                {
                    bool res = wp::Various::stringToDouble(value);
                    if (res)
                        tmp.style |= sf::Text::Bold;
                }
                else if ((param == "italic" || param == "it") && !stringValue)
                {
                    bool res = wp::Various::stringToDouble(value);
                    if (res)
                        tmp.style |= sf::Text::Italic;
                }
                else if ((param == "underlined" || param == "ul") && !stringValue)
                {
                    bool res = wp::Various::stringToDouble(value);
                    if (res)
                        tmp.style |= sf::Text::Underlined;
                }
                else if ((param == "strikeThrough" || param == "st") && !stringValue)
                {
                    bool res = wp::Various::stringToDouble(value);
                    if (res)
                        tmp.style |= sf::Text::StrikeThrough;
                }
                else
                {
                    std::cerr << "error : parameter \"" << param << "\" not found or the value is in an invalid format\n";
                }
            }
        }
        addPart(tmp);
        if (str[cursor] != ',' && str[cursor] != ']')
        {
            std::cerr << "error : character '" << str[cursor] << "', expected ',' or ']' at line " << row << " and column " << column << '\n';
            return false;
        }
        if (str[cursor] == ']')
            end = true;
        if (str[cursor] == ',')
        {
            cursor++;
            column++;
            if (!nextValidChar(cursor, str, row, column))
            {
                std::cerr << "error : no ending\n";
                return false;
            }
        }
    }
    return true;
}
void RichText::setTextWrappingSize(float s)
{
    m_textWrapping = s;
}
float RichText::getTextWrappingSize() const
{
    return m_textWrapping;
}
int RichText::getPointedPart(sf::Vector2f pt) const
{
    pt = getInverseTransform().transformPoint(pt);
    for (int i = 0;i<m_buffer.size();i++)
    {
        if (m_buffer[i]->getGlobalBounds().contains(pt))
            return m_indexs[i];
    }
    return -1;
}

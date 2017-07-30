#include "RichText.hpp"
#include <iostream>

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
    m_font = nullptr;
    m_size = 0;
}
void RichText::addPart(Part const& p)
{
    std::vector<Part> subList;
    Part tmp = p;
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
void RichText::generate()
{
    sf::Vector2f offset;
    m_buffer.clear();
    float decal = 9999999;
    for (int i = 0;i<m_parts.size();i++)
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

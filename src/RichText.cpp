#include "RichText.hpp"

using namespace wp;

RichText::Part::Part(std::string const& str, sf::Color col1, sf::Uint32 st, sf::Color col2, float th)
{
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
    m_parts.push_back(&p);
}
void RichText::clear()
{
    m_parts.clear();
    m_buffer.clear();
}
void RichText::setFont(sf::Font const& f)
{
    m_font = &f;
}
sf::Font const& RichText::getFont() const
{
    return *m_font;
}
void RichText::setSize(sf::Uint32 s)
{
    m_size = s;
}
sf::Uint32 RichText::getSize() const
{
    return m_size;
}
void RichText::generate()
{
    float offset = 0;
    m_buffer.clear();
    for (int i = 0;i<m_parts.size();i++)
    {
        std::shared_ptr<sf::Text> tmp(new sf::Text());
        tmp->setString(m_parts[i]->text);
        tmp->setFillColor(m_parts[i]->fillColor);
        tmp->setOutlineColor(m_parts[i]->outlineColor);
        tmp->setOutlineThickness(m_parts[i]->outlineThickness);
        tmp->setStyle(m_parts[i]->style);
        tmp->setFont(*m_font);
        tmp->setCharacterSize(m_size);
        tmp->setPosition(offset, -tmp->getLocalBounds().top);
        m_buffer.push_back(tmp);
        offset += tmp->getLocalBounds().width;
    }
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
sf::FloatRect RichText::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}

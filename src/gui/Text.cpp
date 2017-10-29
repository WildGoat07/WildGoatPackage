#include "Text.hpp"

using namespace wp;
using namespace gui;

Text::Text(Resource& res)
{
    m_res = &res;
    m_textBuff.setFont(m_res->font);
    m_textBuff.setCharacterSize(m_res->textSize);
    m_textBuff.setFillColor(textColor);
    m_handle = &res.handle;
}
sf::FloatRect Text::_getHitbox() const
{
    sf::FloatRect rect = getLocalBounds();
    rect.left += m_padding.x;
    rect.top += m_padding.y;
    rect.width -= 2*m_padding.x;
    rect.height -= 2*m_padding.y;
    return rect;
}
sf::FloatRect Text::getLocalBounds() const
{
    sf::FloatRect rect;
    rect.width = m_textBuff.getGlobalBounds().width + m_padding.x*2;
    rect.height = m_textBuff.getGlobalBounds().height + m_padding.y*2;

    return rect;
}
void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::View view = target.getView();
    target.setView(sf::View(sf::FloatRect(0, 0, target.getSize().x, target.getSize().y)));
    sf::Transform tr = getTransform();
    target.draw(m_textBuff, tr);
    target.setView(view);
}
void Text::setText(std::string const& text)
{
    m_textBuff.setString(text);
}
void Text::_implUpdate()
{
    sf::Vector2f size;
    size.x = m_textBuff.getGlobalBounds().width;
    size.y = m_textBuff.getGlobalBounds().height;
    size += m_padding*2;
    m_textBuff.setPosition(m_padding);
    m_textBuff.move(0, -m_textBuff.getLocalBounds().top);
}


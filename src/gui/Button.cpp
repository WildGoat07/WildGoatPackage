#include "Button.hpp"

using namespace wp;
using namespace gui;

Button::Button(Resource& res)
{
    m_res = &res;
    m_textBuff.setFont(m_res->font);
    m_textBuff.setCharacterSize(m_res->textSize);
    m_lines.setPrimitiveType(sf::Lines);
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_lines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_lines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_lines.append(sf::Vertex(sf::Vector2f(), altBorder));
}
void Button::_implUpdate()
{
    sf::Vector2f size;
    size.x = m_textBuff.getGlobalBounds().width + m_res->textSize*0.8;
    size.y = m_res->textSize*1.8;

    if (m_imgTexture != nullptr)
    {
        float ratio = (float)m_imgTexture->getSize().x/m_imgTexture->getSize().y;
        m_img.setSize(sf::Vector2f(m_res->textSize*ratio*1.4, m_res->textSize*1.4));
        size.x += m_res->textSize*(ratio + 0.2)*1.4;
    }

    size.x = (int)size.x;
    size.y = (int)size.y;
    m_rectangle.setSize(size);
    m_rectangle.setPosition(m_padding);
    sf::Vector2f off = sf::Vector2f(m_res->textSize*0.4, m_res->textSize*0.4) + m_padding;

    m_img.setPosition(sf::Vector2f(m_res->textSize*0.2, m_res->textSize*0.2) + m_padding);
    if (m_imgTexture != nullptr)
        off.x += m_res->textSize*((float)m_imgTexture->getSize().x/m_imgTexture->getSize().y + 0.2)*1.4;

    off.x = (int)off.x;
    off.y = (int)off.y;
    m_lines[0].position = sf::Vector2f(0.5, 0.5) + m_padding;
    m_lines[1].position = sf::Vector2f(size.x - 0.5, 0.5) + m_padding;
    m_lines[2].position = sf::Vector2f(0.5, 0.5) + m_padding;
    m_lines[3].position = sf::Vector2f(0.5, size.y-0.5) + m_padding;

    m_lines[4].position = sf::Vector2f(size.x - 0.5, 0.5) + m_padding;
    m_lines[5].position = sf::Vector2f(size.x - 0.5, size.y-0.5) + m_padding;
    m_lines[6].position = sf::Vector2f(0.5, size.y-0.5) + m_padding;
    m_lines[7].position = sf::Vector2f(size.x - 0.5, size.y-0.5) + m_padding;
    m_textBuff.setPosition(off);
    m_textBuff.move(0, -m_textBuff.getLocalBounds().top);
    if (m_pressed)
    {
        m_rectangle.setFillColor(altBackground);
        m_textBuff.setFillColor(altTextColor);
        m_lines[0].color = altBorder;
        m_lines[1].color = altBorder;
        m_lines[2].color = altBorder;
        m_lines[3].color = altBorder;

        m_lines[4].color = border;
        m_lines[5].color = border;
        m_lines[6].color = border;
        m_lines[7].color = border;
    }
    else
    {
        m_rectangle.setFillColor(background);
        m_textBuff.setFillColor(textColor);
        m_lines[0].color = border;
        m_lines[1].color = border;
        m_lines[2].color = border;
        m_lines[3].color = border;

        m_lines[4].color = altBorder;
        m_lines[5].color = altBorder;
        m_lines[6].color = altBorder;
        m_lines[7].color = altBorder;
    }
}
void Button::_implEvent(sf::Event const& ev, Event& newEv, sf::View const&)
{
    if (m_validClic && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        m_pressed = true;
    else
        m_pressed = false;
}
sf::FloatRect Button::_getHitbox() const
{
    sf::FloatRect rect = getLocalBounds();
    rect.left += m_padding.x;
    rect.top += m_padding.y;
    rect.width -= 2*m_padding.x;
    rect.height -= 2*m_padding.y;
    return rect;
}
sf::FloatRect Button::getLocalBounds() const
{
    sf::FloatRect rect;
    rect.width = m_rectangle.getSize().x + m_padding.x*2;
    rect.height = m_rectangle.getSize().y + m_padding.y*2;

    return rect;
}
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::View view = target.getView();
    target.setView(sf::View(sf::FloatRect(0, 0, target.getSize().x, target.getSize().y)));
    sf::Transform tr = getTransform();
    target.draw(m_rectangle, tr);
    target.draw(m_lines, tr);
    if (m_imgTexture != nullptr)
        target.draw(m_img, tr);
    target.draw(m_textBuff, tr);
    target.setView(view);
}
void Button::setText(std::string const& text)
{
    m_textBuff.setString(text);
}
void Button::setImage(sf::Texture const* tex)
{
    m_imgTexture = tex;
    m_img.setTexture(tex);
}

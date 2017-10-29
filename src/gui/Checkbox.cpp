#include "Checkbox.hpp"

using namespace wp;
using namespace gui;

Checkbox::Checkbox(Resource& res)
{
    m_res = &res;
    m_textBuff.setFont(m_res->font);
    m_textBuff.setCharacterSize(m_res->textSize);
    m_lines.setPrimitiveType(sf::Lines);
    m_lines.append(sf::Vertex(sf::Vector2f(), background));
    m_lines.append(sf::Vertex(sf::Vector2f(), background));
    m_lines.append(sf::Vertex(sf::Vector2f(), background));
    m_lines.append(sf::Vertex(sf::Vector2f(), background));
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), border));

    m_innerRectangle.setFillColor(foreground);
    m_textBuff.setFillColor(textColor);
    m_handle = &res.handle;
}
void Checkbox::_implUpdate()
{
    int txSize = m_res->textSize*1.2;
    m_rectangle.setSize(sf::Vector2f(txSize, txSize));
    m_innerRectangle.setSize(0.5*sf::Vector2f(txSize, txSize));
    m_lines[0].position = sf::Vector2f(0.5, 0.5) + m_padding;
    m_lines[1].position = sf::Vector2f(txSize - 0.5, 0.5) + m_padding;
    m_lines[2].position = sf::Vector2f(0.5, 0.5) + m_padding;
    m_lines[3].position = sf::Vector2f(0.5, txSize-0.5) + m_padding;

    m_lines[4].position = sf::Vector2f(txSize - 0.5, 0.5) + m_padding;
    m_lines[5].position = sf::Vector2f(txSize - 0.5, txSize-0.5) + m_padding;
    m_lines[6].position = sf::Vector2f(0.5, txSize-0.5) + m_padding;
    m_lines[7].position = sf::Vector2f(txSize - 0.5, txSize-0.5) + m_padding;
    m_textBuff.setPosition(m_padding);
    m_rectangle.setPosition(m_padding);
    m_innerRectangle.setPosition(m_padding + 0.25*sf::Vector2f(txSize, txSize));
    if (m_pressed)
        m_rectangle.setFillColor(altBackground);
    else
        m_rectangle.setFillColor(background);
    m_textBuff.move((int)(txSize * 1.2), -m_textBuff.getLocalBounds().top + (int)(txSize - m_textBuff.getGlobalBounds().height)/2);
}
void Checkbox::_implEvent(sf::Event const& ev, Event& newEv, sf::View const& view)
{
    if (m_validClic && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        m_pressed = true;
    else
        m_pressed = false;
    if (newEv == MOUSE_LEFT_CLIC)
    {
        m_checked = !m_checked;
        newEv += CHECKBOX_CHANGED;
        if (m_checked)
            newEv += CHECKBOX_CHECKED;
        else
            newEv += CHECKBOX_UNCHECKED;
    }
}
sf::FloatRect Checkbox::_getHitbox() const
{
    sf::FloatRect rect = getLocalBounds();
    rect.left += m_padding.x;
    rect.top += m_padding.y;
    rect.width -= 2*m_padding.x;
    rect.height -= 2*m_padding.y;
    return rect;
}
sf::FloatRect Checkbox::getLocalBounds() const
{
    sf::FloatRect rect;
    rect.width = m_textBuff.getGlobalBounds().width + m_padding.x*2 + m_res->textSize*1.2*1.2;
    rect.height = m_res->textSize*1.2 + m_padding.y*2;

    return rect;
}
void Checkbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::View view = target.getView();
    target.setView(sf::View(sf::FloatRect(0, 0, target.getSize().x, target.getSize().y)));
    sf::Transform tr = getTransform();
    target.draw(m_rectangle, tr);
    if (m_checked)
        target.draw(m_innerRectangle, tr);
    target.draw(m_lines, tr);
    target.draw(m_textBuff, tr);
    target.setView(view);
}
void Checkbox::setText(std::string const& text)
{
    m_textBuff.setString(text);
}
void Checkbox::setChecked(bool c)
{
    m_checked = true;
}
bool Checkbox::isChecked() const
{
    return m_checked;
}

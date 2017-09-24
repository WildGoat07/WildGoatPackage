#include "Gauge.hpp"

using namespace wp;
using namespace gui;

Gauge::Gauge(Resource& res)
{
    m_res = &res;
    m_lines.setPrimitiveType(sf::Lines);
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), border));
    m_lines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_lines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_lines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_lines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_rectangle.setFillColor(foreground);
    m_backLine.setFillColor(background);
}
void Gauge::_implUpdate()
{
    sf::Vector2f cursPos;
    sf::Vector2f size;
    if (m_orientation == HORIZONTAL)
    {
        size.y = m_res->textSize*1.2;
        size.x = m_res->textSize*0.6;

        cursPos.x = Various::linearInter(0, m_length-m_res->textSize*0.6, m_perc) + m_padding.x;
        cursPos.y = m_padding.y;

        m_backLine.setSize(sf::Vector2f(m_length - m_res->textSize*0.6, m_res->textSize*0.3));
        m_backLine.setPosition(m_padding + sf::Vector2f(m_res->textSize*0.3, m_res->textSize*0.45));
    }
    if (m_orientation == VERTICAL)
    {
        size.x = m_res->textSize*1.2;
        size.y = m_res->textSize*0.6;

        cursPos.y = Various::linearInter(m_length-m_res->textSize*0.6, 0, m_perc) + m_padding.y;
        cursPos.x = m_padding.x;

        m_backLine.setSize(sf::Vector2f(m_res->textSize*0.3, m_length - m_res->textSize*0.6));
        m_backLine.setPosition(m_padding + sf::Vector2f(m_res->textSize*0.45, m_res->textSize*0.3));
    }
    size.x = (int)size.x;
    size.y = (int)size.y;
    cursPos.x = (int)cursPos.x;
    cursPos.y = (int)cursPos.y;
    m_rectangle.setSize(size);
    m_rectangle.setPosition(cursPos);
    m_lines[0].position = sf::Vector2f(0.5, 0.5) + cursPos;
    m_lines[1].position = sf::Vector2f(size.x - 0.5, 0.5) + cursPos;
    m_lines[2].position = sf::Vector2f(0.5, 0.5) + cursPos;
    m_lines[3].position = sf::Vector2f(0.5, size.y-0.5) + cursPos;

    m_lines[4].position = sf::Vector2f(size.x - 0.5, 0.5) + cursPos;
    m_lines[5].position = sf::Vector2f(size.x - 0.5, size.y-0.5) + cursPos;
    m_lines[6].position = sf::Vector2f(0.5, size.y-0.5) + cursPos;
    m_lines[7].position = sf::Vector2f(size.x - 0.5, size.y-0.5) + cursPos;
}
void Gauge::_implEvent(sf::Event const& ev, Event& newEv, sf::View const& view)
{
    if (newEv == MOUSE_BUTTON_LEFT_DOWN)
        m_pressed = true;
    if (ev.type == sf::Event::MouseButtonReleased && ev.mouseButton.button == sf::Mouse::Left)
        m_pressed = false;
    sf::Vector2f mousePos = getInverseTransform().transformPoint(m_handle->mapPixelToCoords(sf::Mouse::getPosition(*m_handle), view)) - m_padding;
    if (m_pressed)
    {
        float perc;
        if (m_orientation == HORIZONTAL)
        {
            perc = Various::percent(m_res->textSize*0.3, m_length - m_res->textSize*0.3, mousePos.x);
            if (perc < 0)
                perc = 0;
            if (perc > 1)
                perc = 1;
        }
        if (m_orientation == VERTICAL)
        {
            perc = Various::percent(m_res->textSize*0.3, m_length - m_res->textSize*0.3, mousePos.y);
            if (perc < 0)
                perc = 0;
            if (perc > 1)
                perc = 1;
            perc = 1 - perc;
        }
        m_perc = perc;
    }
}
sf::FloatRect Gauge::_getHitbox() const
{
    sf::FloatRect rect = getLocalBounds();
    rect.left += m_padding.x;
    rect.top += m_padding.y;
    rect.width -= 2*m_padding.x;
    rect.height -= 2*m_padding.y;
    return rect;
}
sf::FloatRect Gauge::getLocalBounds() const
{
    sf::FloatRect rect;
    if (m_orientation == HORIZONTAL)
    {
        rect.width = m_length + m_padding.x*2;
        rect.height = m_res->textSize*1.2 + m_padding.y*2;
    }
    if (m_orientation == VERTICAL)
    {
        rect.width = m_res->textSize*1.2 + m_padding.x*2;
        rect.height = m_length + m_padding.y*2;
    }

    return rect;
}
void Gauge::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::View view = target.getView();
    target.setView(sf::View(sf::FloatRect(0, 0, target.getSize().x, target.getSize().y)));
    sf::Transform tr = getTransform();
    target.draw(m_backLine, tr);
    target.draw(m_rectangle, tr);
    target.draw(m_lines, tr);
    target.setView(view);
}
void Gauge::setPerc(float perc)
{
    m_perc = perc;
}
void Gauge::setOrientation(int ori)
{
    m_orientation = ori;
}
void Gauge::setLength(float l)
{
    m_length = l;
}
float Gauge::getPerc() const
{
    return m_perc;
}

#include "Separator.hpp"

using namespace wp;
using namespace gui;

Separator::Separator(Resource& res)
{
    m_res = &res;
    m_line.setPrimitiveType(sf::Lines);
    m_line.append(sf::Vertex(sf::Vector2f(), background));
    m_line.append(sf::Vertex(sf::Vector2f(), background));
    m_handle = &res.handle;
}
void Separator::_implUpdate()
{
    m_line[0].position = m_padding + sf::Vector2f(0.5, 0.5);
    m_line[1].position = m_padding + sf::Vector2f(-0.5, 0.5);
    if (m_orientation == HORIZONTAL)
        m_line[1].position.x += m_length;
    if (m_orientation == VERTICAL)
        m_line[1].position.x += m_length;
}
sf::FloatRect Separator::_getHitbox() const
{
    sf::FloatRect rect = getLocalBounds();
    rect.left += m_padding.x;
    rect.top += m_padding.y;
    rect.width = 2*m_padding.x;
    rect.height -= 2*m_padding.y;
    return rect;
}
sf::FloatRect Separator::getLocalBounds() const
{
    sf::FloatRect rect;
    if (m_orientation == VERTICAL)
    {
        rect.width = 1 + m_padding.x*2;
        rect.height = m_length + m_padding.y*2;
    }
    if (m_orientation == HORIZONTAL)
    {
        rect.height = 1 + m_padding.y*2;
        rect.width = m_length + m_padding.x*2;
    }

    return rect;
}
void Separator::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::View view = target.getView();
    target.setView(sf::View(sf::FloatRect(0, 0, target.getSize().x, target.getSize().y)));
    sf::Transform tr = getTransform();
    target.draw(m_line, tr);
    target.setView(view);
}
void Separator::setLength(float l)
{
    m_length = std::max((float)0, l);
}
void Separator::setOrientation(int o)
{
    m_orientation = o;
}

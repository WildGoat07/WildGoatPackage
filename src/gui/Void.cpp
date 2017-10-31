#include "Void.hpp"

using namespace wp;
using namespace gui;

Void::Void(Resource& res)
{
    m_res = &res;
}
sf::FloatRect Void::_getHitbox() const
{
    sf::FloatRect rect = getLocalBounds();
    rect.left += m_padding.x;
    rect.top += m_padding.y;
    rect.width -= 2*m_padding.x;
    rect.height -= 2*m_padding.y;
    return rect;
}
sf::FloatRect Void::getLocalBounds() const
{
    sf::FloatRect rect;
    rect.width = m_size.x + m_padding.x*2;
    rect.height = m_size.y + m_padding.y*2;

    return rect;
}
void Void::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
void Void::setSize(sf::Vector2f s)
{
    m_size = s;
}

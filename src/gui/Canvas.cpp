#include "Canvas.hpp"

using namespace wp;
using namespace gui;

Canvas::Canvas(Resource& res)
{
    m_res = &res;
    m_handle = &res.handle;
}
sf::FloatRect Canvas::_getHitbox() const
{
    sf::FloatRect rect = getLocalBounds();
    rect.left += m_padding.x;
    rect.top += m_padding.y;
    rect.width -= 2*m_padding.x;
    rect.height -= 2*m_padding.y;
    return rect;
}
sf::FloatRect Canvas::getLocalBounds() const
{
    sf::FloatRect rect;
    rect.width = m_texture->getSize().x + m_padding.x*2;
    rect.height = m_texture->getSize().y + m_padding.y*2;

    return rect;
}
void Canvas::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::View view = target.getView();
    target.setView(sf::View(sf::FloatRect(0, 0, target.getSize().x, target.getSize().y)));
    sf::Transform tr = getTransform();
    tr.translate(m_padding);
    target.draw(sf::Sprite(*m_texture), tr);
    target.setView(view);
}
void Canvas::setTexture(sf::Texture const& tex)
{
    m_texture = &tex;
}

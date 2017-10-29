#include "ProgressBar.hpp"

using namespace wp;
using namespace gui;

Progressbar::Progressbar(Resource& res)
{
    m_res = &res;
    m_outerLines.setPrimitiveType(sf::Lines);
    m_outerLines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_outerLines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_outerLines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_outerLines.append(sf::Vertex(sf::Vector2f(), altBorder));
    m_outerLines.append(sf::Vertex(sf::Vector2f(), border));
    m_outerLines.append(sf::Vertex(sf::Vector2f(), border));
    m_outerLines.append(sf::Vertex(sf::Vector2f(), border));
    m_outerLines.append(sf::Vertex(sf::Vector2f(), border));
    m_innerLines.setPrimitiveType(sf::Lines);
    m_innerLines.append(sf::Vertex(sf::Vector2f(), border_c));
    m_innerLines.append(sf::Vertex(sf::Vector2f(), border_c));
    m_innerLines.append(sf::Vertex(sf::Vector2f(), border_c));
    m_innerLines.append(sf::Vertex(sf::Vector2f(), border_c));
    m_innerLines.append(sf::Vertex(sf::Vector2f(), altBorder_c));
    m_innerLines.append(sf::Vertex(sf::Vector2f(), altBorder_c));
    m_innerLines.append(sf::Vertex(sf::Vector2f(), altBorder_c));
    m_innerLines.append(sf::Vertex(sf::Vector2f(), altBorder_c));
    m_innerRectangle.setFillColor(altForeground_c);
    m_outerRectangle.setFillColor(altBackground);
    m_handle = &res.handle;
}
void Progressbar::_implUpdate()
{
    sf::Vector2f size;
    if (m_orientation == HORIZONTAL)
    {
        size.y = m_res->textSize*1.2;
        size.x = m_length;
    }
    if (m_orientation == VERTICAL)
    {
        size.x = m_res->textSize*1.2;
        size.y = m_length;
    }
    size.x = (int)size.x;
    size.y = (int)size.y;
    m_outerRectangle.setSize(size);
    m_outerRectangle.setPosition(m_padding);
    m_outerLines[0].position = sf::Vector2f(0.5, 0.5) + m_padding;
    m_outerLines[1].position = sf::Vector2f(size.x - 0.5, 0.5) + m_padding;
    m_outerLines[2].position = sf::Vector2f(0.5, 0.5) + m_padding;
    m_outerLines[3].position = sf::Vector2f(0.5, size.y-0.5) + m_padding;

    m_outerLines[4].position = sf::Vector2f(size.x - 0.5, 0.5) + m_padding;
    m_outerLines[5].position = sf::Vector2f(size.x - 0.5, size.y-0.5) + m_padding;
    m_outerLines[6].position = sf::Vector2f(0.5, size.y-0.5) + m_padding;
    m_outerLines[7].position = sf::Vector2f(size.x - 0.5, size.y-0.5) + m_padding;

    sf::Vector2f off = m_padding + sf::Vector2f(1,1);
    sf::Vector2f minSize = size - sf::Vector2f(2, 2);

    off.x = (int)off.x;
    off.y = (int)off.y;
    minSize.x = (int)minSize.x;
    minSize.y = (int)minSize.y;

    if (m_orientation == HORIZONTAL)
    {
        minSize.x *= m_perc;
        m_innerRectangle.setSize(minSize);
        m_innerRectangle.setPosition(off);
        m_innerLines[0].position = sf::Vector2f(0.5, 0.5) + off;
        m_innerLines[1].position = sf::Vector2f(minSize.x - 0.5, 0.5) + off;
        m_innerLines[2].position = sf::Vector2f(0.5, 0.5) + off;
        m_innerLines[3].position = sf::Vector2f(0.5, minSize.y-0.5) + off;

        m_innerLines[4].position = sf::Vector2f(minSize.x - 0.5, 0.5) + off;
        m_innerLines[5].position = sf::Vector2f(minSize.x - 0.5, minSize.y-0.5) + off;
        m_innerLines[6].position = sf::Vector2f(0.5, minSize.y-0.5) + off;
        m_innerLines[7].position = sf::Vector2f(minSize.x - 0.5, minSize.y-0.5) + off;
    }
    if (m_orientation == VERTICAL)
    {
        minSize.y *= m_perc;
        off = size - sf::Vector2f(1, 1) - minSize + m_padding;
        off.x = (int)off.x;
        off.y = (int)off.y;
        m_innerRectangle.setSize(minSize);
        m_innerRectangle.setPosition(off);
        m_innerLines[0].position = sf::Vector2f(0.5, 0.5) + off;
        m_innerLines[1].position = sf::Vector2f(minSize.x - 0.5, 0.5) + off;
        m_innerLines[2].position = sf::Vector2f(0.5, 0.5) + off;
        m_innerLines[3].position = sf::Vector2f(0.5, minSize.y-0.5) + off;

        m_innerLines[4].position = sf::Vector2f(minSize.x - 0.5, 0.5) + off;
        m_innerLines[5].position = sf::Vector2f(minSize.x - 0.5, minSize.y-0.5) + off;
        m_innerLines[6].position = sf::Vector2f(0.5, minSize.y-0.5) + off;
        m_innerLines[7].position = sf::Vector2f(minSize.x - 0.5, minSize.y-0.5) + off;
    }

}
sf::FloatRect Progressbar::_getHitbox() const
{
    sf::FloatRect rect = getLocalBounds();
    rect.left += m_padding.x;
    rect.top += m_padding.y;
    rect.width -= 2*m_padding.x;
    rect.height -= 2*m_padding.y;
    return rect;
}
sf::FloatRect Progressbar::getLocalBounds() const
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
void Progressbar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::View view = target.getView();
    target.setView(sf::View(sf::FloatRect(0, 0, target.getSize().x, target.getSize().y)));
    sf::Transform tr = getTransform();
    target.draw(m_outerRectangle, tr);
    target.draw(m_outerLines, tr);
    target.draw(m_innerRectangle, tr);
    target.draw(m_innerLines, tr);
    target.setView(view);
}
void Progressbar::setPerc(float perc)
{
    m_perc = perc;
}
void Progressbar::setOrientation(int ori)
{
    m_orientation = ori;
}
void Progressbar::setLength(float l)
{
    m_length = l;
}

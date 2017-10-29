#include "Radiogroup.hpp"

using namespace wp;
using namespace gui;

Radiogroup::Radiogroup(Resource& res)
{
    m_res = &res;
    m_handle = &res.handle;
}
void Radiogroup::_implUpdate()
{
    float txSize = m_res->textSize*1.2;
    for (int i = 0;i<m_choices.size();i++)
    {
        Part* curr = &m_choices[i];
        float off = (txSize + m_interSpace)*i;
        curr->circle.setRadius(txSize/2);
        curr->innerCircle.setRadius(txSize/4);
        curr->textBuff.setPosition(m_padding  + sf::Vector2f(0, off));
        curr->circle.setPosition(m_padding  + sf::Vector2f(0, off));
        curr->innerCircle.setPosition(m_padding + 0.25*sf::Vector2f(txSize, txSize)  + sf::Vector2f(0, off));
        if (curr->pressed)
            curr->circle.setFillColor(altBackground);
        else
            curr->circle.setFillColor(background);
        curr->textBuff.move((int)(txSize * 1.2), (int)(-curr->textBuff.getLocalBounds().top + (int)(txSize - curr->textBuff.getGlobalBounds().height)/2));
    }
}
void Radiogroup::_implEvent(sf::Event const& ev, Event& newEv, sf::View const& view)
{
    sf::Vector2f mousePos = getInverseTransform().transformPoint(m_handle->mapPixelToCoords(sf::Mouse::getPosition(*m_handle), view));
    for (int i = 0;i<m_choices.size();i++)
    {
        sf::FloatRect hitbox;
        hitbox.top = i*m_res->textSize*1.2 + m_padding.y + i*m_interSpace;
        hitbox.height = m_res->textSize*1.2;
        hitbox.left = m_padding.x;
        hitbox.width = m_choices[i].textBuff.getGlobalBounds().left + m_choices[i].textBuff.getGlobalBounds().width;

        sf::FloatRect tmp = _getHitbox();
        if (hitbox.contains(mousePos))
        {
            if (m_validClic && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                m_choices[i].pressed = true;
            else
                m_choices[i].pressed = false;
            if (newEv == MOUSE_LEFT_CLIC)
            {
                setSelection(i);
                newEv += RADIOGROUP_CHANGED;
            }
        }
    }
}
sf::FloatRect Radiogroup::_getHitbox() const
{
    sf::FloatRect rect = getLocalBounds();
    rect.left += m_padding.x;
    rect.top += m_padding.y;
    rect.width -= 2*m_padding.x;
    rect.height -= 2*m_padding.y;
    return rect;
}
sf::FloatRect Radiogroup::getLocalBounds() const
{
    sf::Vector2f max;
    for (int i = 0;i<m_choices.size();i++)
    {
        float tmp = m_choices[i].textBuff.getGlobalBounds().width;
        if (max.x < tmp)
            max.x = tmp;
    }
    max.x += m_res->textSize*1.2*1.2;
    max.y = m_choices.size()*m_res->textSize*1.2;
    if (m_choices.size() > 1)
        max.y += (m_choices.size()-1)*m_interSpace;
    max += 2*m_padding;
    return sf::FloatRect(sf::Vector2f(), max);
}
void Radiogroup::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::View view = target.getView();
    target.setView(sf::View(sf::FloatRect(0, 0, target.getSize().x, target.getSize().y)));
    sf::Transform tr = getTransform();
    for (int i = 0;i<m_choices.size();i++)
    {
        target.draw(m_choices[i].circle, tr);
        if (m_choices[i].selected)
            target.draw(m_choices[i].innerCircle, tr);
        target.draw(m_choices[i].textBuff, tr);
    }
    target.setView(view);
}
void Radiogroup::setSelection(unsigned int sel)
{
    for (int i = 0;i<m_choices.size();i++)
    {
        m_choices[i].selected = false;
        if (i == sel)
            m_choices[i].selected = true;
    }
}
void Radiogroup::addChoice(std::string const& str)
{
    Part tmp;
    tmp.circle.setPointCount(10);
    tmp.innerCircle.setPointCount(10);
    tmp.innerCircle.setFillColor(foreground);
    tmp.pressed = false;
    tmp.selected = false;
    tmp.textBuff.setCharacterSize(m_res->textSize);
    tmp.textBuff.setFillColor(textColor);
    tmp.textBuff.setFont(m_res->font);
    tmp.textBuff.setString(str);
    m_choices.push_back(tmp);
}
unsigned int Radiogroup::getSelection() const
{
    return m_selection;
}
size_t Radiogroup::size() const
{
    return m_choices.size();
}
void Radiogroup::deleteChoice(unsigned int choice)
{
    m_choices.erase(m_choices.begin() + choice);
}
void Radiogroup::setText(std::string const& str, unsigned int selec)
{
    m_choices[selec].textBuff.setString(str);
}
void Radiogroup::setInterSpace(float inter)
{
    m_interSpace = inter;
}

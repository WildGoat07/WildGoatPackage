#include "BaseWidget.hpp"


using namespace wp;
using namespace wp::gui;

void BaseWidget::update()
{
    if (m_relativeTo != nullptr)
    {
        sf::Vector2f newPos = m_relativePos + sf::Vector2f(m_relativeTo->getGlobalBounds().left, m_relativeTo->getGlobalBounds().top);
        if (m_relativeMode == TOP_RIGHT)
            newPos.x += m_relativeTo->getGlobalBounds().width;
        if (m_relativeMode == BOT_LEFT)
            newPos.y += m_relativeTo->getGlobalBounds().height;
        if (m_relativeMode == BOT_RIGHT)
        {
            newPos.x += m_relativeTo->getGlobalBounds().width;
            newPos.y += m_relativeTo->getGlobalBounds().height;
        }
        setPosition(newPos);
    }
    _implUpdate();
}
void BaseWidget::_implUpdate()
{

}
void BaseWidget::_implEvent(sf::Event const&, Event&, sf::View const&)
{

}

Event const& BaseWidget::getEvent() const
{
    return m_ownEvent;
}

void BaseWidget::handleEvent(sf::Event const& ev)
{
    sf::View view(sf::FloatRect(sf::FloatRect(0, 0, m_handle->getSize().x, m_handle->getSize().y)));
    Event newEv;
    sf::Vector2f mousePos = m_handle->mapPixelToCoords(sf::Mouse::getPosition(*m_handle), view);
    sf::Vector2f relativeMousePos = getInverseTransform().transformPoint(mousePos);
    if (_getHitbox().contains(relativeMousePos))
    {
        newEv += MOUSE_ON_WIDGET;
        if (m_ownEvent != MOUSE_ON_WIDGET)
            newEv += MOUSE_ENTERED;
        if (ev.type == sf::Event::MouseButtonPressed)
        {
            if (ev.mouseButton.button == sf::Mouse::Left)
            {
                newEv += MOUSE_BUTTON_LEFT_DOWN;
                m_validClic = true;
            }
            if (ev.mouseButton.button == sf::Mouse::Right)
            {
                newEv += MOUSE_BUTTON_RIGHT_DOWN;
                m_validClic = true;
            }
            if (ev.mouseButton.button == sf::Mouse::Middle)
            {
                newEv += MOUSE_BUTTON_MIDDLE_DOWN;
                m_validClic = true;
            }
            if (ev.mouseButton.button == sf::Mouse::XButton1)
            {
                newEv += MOUSE_BUTTON_X1_DOWN;
                m_validClic = true;
            }
            if (ev.mouseButton.button == sf::Mouse::XButton2)
            {
                newEv += MOUSE_BUTTON_X2_DOWN;
                m_validClic = true;
            }
        }
        if (ev.type == sf::Event::MouseButtonReleased)
        {
            if (ev.mouseButton.button == sf::Mouse::Left)
                newEv += MOUSE_BUTTON_LEFT_UP;
            if (ev.mouseButton.button == sf::Mouse::Right)
                newEv += MOUSE_BUTTON_RIGHT_UP;
            if (ev.mouseButton.button == sf::Mouse::Middle)
                newEv += MOUSE_BUTTON_MIDDLE_UP;
            if (ev.mouseButton.button == sf::Mouse::XButton1)
                newEv += MOUSE_BUTTON_X1_UP;
            if (ev.mouseButton.button == sf::Mouse::XButton2)
                newEv += MOUSE_BUTTON_X2_UP;

            if (m_validClic)
            {
                if (ev.mouseButton.button == sf::Mouse::Left)
                    newEv += MOUSE_LEFT_CLIC;
                if (ev.mouseButton.button == sf::Mouse::Right)
                    newEv += MOUSE_RIGHT_CLIC;
                if (ev.mouseButton.button == sf::Mouse::Middle)
                    newEv += MOUSE_MIDDLE_CLIC;
                if (ev.mouseButton.button == sf::Mouse::XButton1)
                    newEv += MOUSE_X1_CLIC;
                if (ev.mouseButton.button == sf::Mouse::XButton2)
                    newEv += MOUSE_X2_CLIC;
                m_validClic = false;
            }
        }
        if (ev.type == sf::Event::MouseWheelMoved)
        {
            if (ev.mouseWheel.delta > 0)
                newEv += MOUSE_WHEEL_UP;
            if (ev.mouseWheel.delta < 0)
                newEv += MOUSE_WHEEL_DOWN;
        }
    }
    else
    {
        m_validClic = false;
        if (m_ownEvent == MOUSE_ON_WIDGET)
            newEv += MOUSE_LEAVED;
    }

    _implEvent(ev, newEv, view);
    m_ownEvent = newEv;
}
sf::FloatRect BaseWidget::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}
void BaseWidget::setRelativeTo(BaseWidget const* widg, sf::Vector2f pos, int mode)
{
    m_relativePos = pos;
    m_relativeTo = widg;
    m_relativeMode = mode;
}
void BaseWidget::setHandle(sf::RenderWindow& handle)
{
    m_handle = &handle;
}
void BaseWidget::setPadding(sf::Vector2f pad)
{
    m_padding = pad;
}

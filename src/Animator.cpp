#include "Animator.hpp"

using namespace wp;

void Animator::setFunction(Function* f, Filter param)
{
    if (ROTATION & param)
        m_functionRotation = f;
    if (SCALE_X & param)
        m_functionScaleX = f;
    if (SCALE_Y & param)
        m_functionScaleY = f;
    if (MOTION_X & param)
        m_functionMoveX = f;
    if (MOTION_Y & param)
        m_functionMoveY = f;
}
void Animator::start()
{
    m_finish = false;
    m_started = true;
    m_ticks = 0;
    if (m_mode == TIME)
        m_clock.restart();
}
void Animator::pause()
{
    m_started = false;
    if (m_mode == TIME)
        m_clock.pause();
}
void Animator::play()
{
    m_started = true;
    if (m_mode == TIME)
        m_clock.play();
}
void Animator::update()
{
    if (m_started && m_mode == TICKS)
        m_ticks++;
    if (m_mode == TICKS)
    {
        if (m_ticks == m_ticksMax)
        {
            if (!m_looped)
            {
                m_finish = true;
                pause();
            }
            else
                start();
        }
    }
    if (m_mode == TIME)
    {
        if (m_clock.getElapsedTime() >= m_time)
        {
            if (!m_looped)
            {
                m_finish = true;
                pause();
                m_clock.setTime(m_time);
            }
            else
                start();
        }
    }
}
sf::Transformable Animator::getTransformable() const
{
    double perc;
    if (m_mode == TICKS)
        perc = wp::Various::percent(0, m_ticksMax, m_ticks);
    if (m_mode == TIME)
        perc = wp::Various::percent(0, m_time.asSeconds(), m_clock.getElapsedTime().asSeconds());
    sf::Transformable tr;
    if (m_functionMoveX != nullptr && m_functionMoveY != nullptr)
        tr.setPosition(m_move.getValue((*m_functionMoveX)(perc)).x, m_move.getValue((*m_functionMoveY)(perc)).y);
    else if (m_functionMoveX == nullptr && m_functionMoveY != nullptr)
        tr.setPosition(m_move.getValue(perc).x, m_move.getValue((*m_functionMoveY)(perc)).y);
    else if (m_functionMoveX != nullptr && m_functionMoveY == nullptr)
        tr.setPosition(m_move.getValue((*m_functionMoveX)(perc)).x, m_move.getValue(perc).y);
    else if (m_functionMoveX == nullptr && m_functionMoveY == nullptr)
        tr.setPosition(m_move.getValue(perc).x, m_move.getValue(perc).y);
    if (m_functionRotation != nullptr)
        tr.setRotation(wp::Various::linearInter(m_startRotation, m_finalRotation, (*m_functionRotation)(perc)));
    else
        tr.setRotation(wp::Various::linearInter(m_startRotation, m_finalRotation, perc));
    sf::Vector2f scale;
    if (m_functionScaleX != nullptr)
        scale.x = wp::Various::linearInter(m_startScale.x, m_finalScale.x, (*m_functionScaleX)(perc));
    else
        scale.x = wp::Various::linearInter(m_startScale.x, m_finalScale.x, perc);
    if (m_functionScaleY != nullptr)
        scale.y = wp::Various::linearInter(m_startScale.y, m_finalScale.y, (*m_functionScaleY)(perc));
    else
        scale.y = wp::Various::linearInter(m_startScale.y, m_finalScale.y, perc);
    tr.setScale(scale);
    return tr;
}

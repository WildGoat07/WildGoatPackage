#include "AdvancedClock.hpp"

using namespace wp;


void AdvancedClock::update() const
{
    if (!m_paused)
        m_time += static_cast<float>(m_factor)*m_chrono.restart();
    else
        m_chrono.restart();
}

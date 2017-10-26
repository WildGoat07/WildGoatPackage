#include "AdvancedClock.hpp"

using namespace wp;


void AdvancedClock::update() const
{
    if (!m_paused)
        m_time += m_factor*m_chrono.restart();
    else
        m_chrono.restart();
}

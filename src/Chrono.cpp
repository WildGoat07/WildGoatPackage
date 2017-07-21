#include "Chrono.hpp"

using namespace wp;

void Chrono::update() const
{
    if (!m_paused)
        m_time += m_chrono.restart();
    else
        m_chrono.restart();
}

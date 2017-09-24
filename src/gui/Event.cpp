#include "Event.hpp"

using namespace wp;
using namespace wp::gui;

Event::Event()
{
    for (int i = 0;i<256;i++)
        m_code[i] = false;
}
Event::Event(Event const& copy)
{
    for (int i = 0;i<256;i++)
        m_code[i] = copy.m_code[i];
}
Event::Event(unsigned int index) :
    Event()
{
    m_code[index] = true;
}
void Event::operator+=(Event const& right)
{
    for (int i = 0;i<256;i++)
        m_code[i] = m_code[i] || right.m_code[i];
}
void Event::operator=(Event const& right)
{
    for (int i = 0;i<256;i++)
        m_code[i] = right.m_code[i];
}
bool Event::equal(Event const& right) const
{
    bool res = false;
    for (int i = 0;i<256;i++)
    {
        if (m_code[i] == right.m_code[i])
        {
            if (m_code[i] == true)
                res = true;
        }
    }
    return res;
}
bool operator==(Event const& left, Event const& right)
{
    return left.equal(right);
}
bool operator!=(Event const& left, Event const& right)
{
    return !(left == right);
}

Event operator+(Event const& left, Event const& right)
{
    Event tmp = left;
    tmp += right;
    return tmp;
}

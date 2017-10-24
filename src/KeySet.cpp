#include "KeySet.hpp"

using namespace wp;

KeySet::operator uint64_t() const
{
    uint64_t code;
    code = m_code;
    if (m_mouse)
        code += sf::Keyboard::KeyCount;
    if (m_ctrl)
        code += sf::Keyboard::KeyCount*2;
    if (m_shift)
        code += sf::Keyboard::KeyCount*4;
    if (m_alt)
        code += sf::Keyboard::KeyCount*8;
    return code;
}

void KeySet::create(uint64_t code)
{
    m_code = code%sf::Keyboard::KeyCount;
    if (code >= sf::Keyboard::KeyCount*8)
    {
        code -= sf::Keyboard::KeyCount*8;
        m_alt = true;
    }
    else
        m_alt = false;
    if (code >= sf::Keyboard::KeyCount*4)
    {
        code -= sf::Keyboard::KeyCount*4;
        m_shift = true;
    }
    else
        m_shift = false;
    if (code >= sf::Keyboard::KeyCount*2)
    {
        code -= sf::Keyboard::KeyCount*2;
        m_ctrl = true;
    }
    else
        m_ctrl = false;
    if (code >= sf::Keyboard::KeyCount)
    {
        code -= sf::Keyboard::KeyCount;
        m_mouse = true;
    }
    else
        m_mouse = false;
}
void KeySet::createKey(uint16_t code, bool ctrl, bool shift, bool alt)
{
    m_code = code;
    m_ctrl = ctrl;
    m_shift = shift;
    m_alt = alt;
    m_mouse = false;
}void KeySet::createMouseKey(uint16_t code, bool ctrl, bool shift, bool alt)
{
    m_code = code;
    m_ctrl = ctrl;
    m_shift = shift;
    m_alt = alt;
    m_mouse = true;
}
bool KeySet::ctrl() const
{
    return m_ctrl;
}
bool KeySet::shift() const
{
    return m_shift;
}
bool KeySet::alt() const
{
    return m_alt;
}
bool KeySet::isMouse() const
{
    return m_mouse;
}
uint16_t KeySet::sfCode() const
{
    return m_code;
}

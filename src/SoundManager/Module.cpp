#include "Module.hpp"
#include "Channel.hpp"

using namespace wp::snd;

void Module::setPitch(float pitch)
{
    m_pitch = pitch;
}
void Module::setVolume(float vol)
{
    m_volume = vol;
}
shared_ptr<Module> Module::getPtr()
{
    return shared_from_this();
}
float Module::getPitch() const
{
    return m_pitch;
}
float Module::getVolume() const
{
    return m_volume;
}
float Module::getComputedPitch() const
{
    if (m_parent != nullptr)
        return m_pitch * m_parent->getComputedPitch();
    return m_pitch;
}
float Module::getComputedVolume() const
{
    if (m_parent != nullptr)
        return m_volume * m_parent->getComputedVolume();
    return m_volume;
}
void Module::resetParent()
{
    if (m_parent != nullptr)
        m_parent->erase(getPtr());
}
void Module::setParent(shared_ptr<Channel> par)
{
    resetParent();
    par->add(getPtr());
}

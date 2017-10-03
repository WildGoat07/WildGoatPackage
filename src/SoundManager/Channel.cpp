#include "Channel.hpp"

using namespace wp::snd;

void Channel::update()
{
    for (std::list<shared_ptr<Module> >::iterator it = m_modules.begin();it!= m_modules.end();it++)
    {
        (*it)->update();
    }
}
bool Channel::_exist(shared_ptr<Module> mod)
{
    for (std::list<shared_ptr<Module> >::iterator it = m_modules.begin();it!= m_modules.end();it++)
    {
        if (mod == (*it)->getPtr())
            return true;
    }
    return false;
}
shared_ptr<Channel> Channel::create()
{
    return shared_ptr<Channel>(new Channel());
}
bool Channel::erase(shared_ptr<Module> mod)
{
    for (std::list<shared_ptr<Module> >::iterator it = m_modules.begin();it!= m_modules.end();it++)
    {
        if (mod == (*it)->getPtr())
        {
            m_modules.erase(it);
            mod->m_parent = nullptr;
            return true;
        }
    }
    return false;
}
shared_ptr<Module> Channel::add(shared_ptr<Module> mod)
{
    if (_exist(mod))
        return mod;
    m_modules.push_back(mod);
    mod->m_parent = this;
    return mod;
}
shared_ptr<Channel> Channel::newChannel()
{
    shared_ptr<Channel> tmp = Channel::create();
    add(tmp);
    return tmp;
}
shared_ptr<Sound> Channel::newSound()
{
    shared_ptr<Sound> tmp = Sound::create();
    add(tmp);
    return tmp;
}
shared_ptr<Music> Channel::newMusic()
{
    shared_ptr<Music> tmp = Music::create();
    add(tmp);
    return tmp;
}

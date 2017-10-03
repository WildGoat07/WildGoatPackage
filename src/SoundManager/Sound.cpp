#include "Sound.hpp"

using namespace wp::snd;

void Sound::update()
{
    m_sound.setVolume(getComputedVolume()*100);
    m_sound.setPitch(getComputedPitch());
}
shared_ptr<Sound> Sound::create()
{
    return shared_ptr<Sound>(new Sound());
}
sf::Sound& Sound::get()
{
    return m_sound;
}


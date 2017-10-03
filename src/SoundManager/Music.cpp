#include "Music.hpp"

using namespace wp::snd;

void Music::update()
{
    m_music.setVolume(getComputedVolume()*100);
    m_music.setPitch(getComputedPitch());
}
shared_ptr<Music> Music::create()
{
    return shared_ptr<Music>(new Music());
}
sf::Music& Music::get()
{
    return m_music;
}

#include "ImgSequence.hpp"

using namespace wp;

ImgSequence::ImgSequence()
{
    m_clock.stop();
}
bool ImgSequence::open(File const& file, uint16_t fps)
{
    m_fps = fps;
    m_streamed = true;
    m_imgs.clear();
    m_files.clear();
    if (!file.exist())
        return false;
    std::string base;
    std::string ext;
    uint16_t nbNum;
    uint16_t start;
    {
        std::string tmp = file.getName();
        nbNum = 0;
        for (int i = tmp.size()-1;i>=0;i--)
        {
            if (tmp[i] >= '0' && tmp[i] <= '9')
                nbNum++;
            else
                i = -1;
        }
        base = file.getPath() + tmp.substr(0, tmp.size()-nbNum);
        ext = file.getExt();
        start = wp::Various::stringToDouble(tmp.substr(tmp.size()-nbNum, nbNum));
    }
    m_buffer.loadFromFile(file.getFullPath());
    bool fin = false;
    uint16_t incr = start;
    while (!fin)
    {
        std::string generated;
        {
            std::string num = wp::Various::intToString(incr);
            std::string zero;
            for (int i = 0;i<nbNum - num.size();i++)
                zero += '0';
            generated = base + zero + num + "." + ext;
        }
        wp::File new_f(generated);
        if (!new_f.exist())
            fin = true;
        else
            m_files.push_back(new_f);
        incr++;
    }
    return true;
}

bool ImgSequence::load(File const& file, uint16_t fps)
{
    m_fps = fps;
    m_streamed = false;
    m_imgs.clear();
    m_files.clear();
    if (!file.exist())
        return false;
    std::string base;
    std::string ext;
    uint16_t nbNum;
    uint16_t start;
    {
        std::string tmp = file.getName();
        nbNum = 0;
        for (int i = tmp.size()-1;i>=0;i--)
        {
            if (tmp[i] >= '0' && tmp[i] <= '9')
                nbNum++;
            else
                i = -1;
        }
        base = file.getPath() + tmp.substr(0, tmp.size()-nbNum);
        ext = file.getExt();
        start = wp::Various::stringToDouble(tmp.substr(tmp.size()-nbNum, nbNum));
    }
    m_buffer.loadFromFile(file.getFullPath());
    bool fin = false;
    uint16_t incr = start;
    while (!fin)
    {
        std::string generated;
        {
            std::string num = wp::Various::intToString(incr);
            std::string zero;
            for (int i = 0;i<nbNum - num.size();i++)
                zero += '0';
            generated = base + zero + num + "." + ext;
        }
        wp::File new_f(generated);
        if (!new_f.exist())
            fin = true;
        else
        {
            shared_ptr<sf::Image> img(new sf::Image());
            if (!img->loadFromFile(generated))
                return false;
            m_imgs.push_back(img);
        }
        incr++;
    }
    return true;
}
void ImgSequence::play()
{
    m_clock.play();
    m_finished = false;
}
void ImgSequence::pause()
{
    m_clock.pause();
}
sf::Time ImgSequence::getOffset() const
{
    return m_clock.getElapsedTime();
}
void ImgSequence::setOffset(sf::Time t)
{
    m_clock.setTime(t);
}
void ImgSequence::setFactor(float f)
{
    m_clock.setFactor(f);
}
float ImgSequence::getFactor() const
{
    return m_clock.getFactor();
}
sf::Texture const& ImgSequence::getTexture() const
{
    return m_buffer;
}
void ImgSequence::setSmooth(bool s)
{
    m_buffer.setSmooth(s);
}
bool ImgSequence::isSmooth() const
{
    return m_buffer.isSmooth();
}
bool ImgSequence::isFinished() const
{
    return m_finished;
}
void ImgSequence::setLoop(bool l)
{
    m_looped = l;
}
bool ImgSequence::getLoop() const
{
    return m_looped;
}
void ImgSequence::update()
{
    int nbFrames;
    if (m_streamed)
        nbFrames = m_files.size();
    else
        nbFrames = m_imgs.size();
    if ((float)nbFrames/m_fps < m_clock.getElapsedTime().asSeconds())
    {
        if (m_looped)
            m_clock.restart();
        else
        {
            m_clock.stop();
            m_finished = true;
        }
    }
    int selectedFrame = m_clock.getElapsedTime().asSeconds()*m_fps;
    if (m_streamed)
    {
        sf::Image tmp;
        tmp.loadFromFile(m_files[selectedFrame].getFullPath());
        m_buffer.update(tmp);
    }
    else
        m_buffer.update(*m_imgs[selectedFrame]);
}

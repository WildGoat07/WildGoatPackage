#include "StandardStream.hpp"

using namespace wp;

void StandardInputStream::setStream(std::istream& stream, size_t size, size_t offset)
{
    m_offset = offset;
    m_stream = &stream;
    m_streamSize = size;
}

std::istream& StandardInputStream::getStream()
{
    return *m_stream;
}
sf::Int64 StandardInputStream::read(void* ptr, sf::Int64 size)
{
    sf::Int64 bytesRead = 0;
    for (sf::Int64 i = 0;i<size;i++)
    {
        char carac;
        if (m_stream->get(carac))
        {
            ((char*)ptr)[bytesRead] = carac;
            bytesRead++;
        }
        else
            return bytesRead;
    }
    return bytesRead;
}
sf::Int64 StandardInputStream::seek(sf::Int64 position)
{
    m_stream->seekg(position + m_offset);
    return m_stream->tellg();
}
sf::Int64 StandardInputStream::tell()
{
    return m_stream->tellg() - m_offset;
}
sf::Int64 StandardInputStream::getSize()
{
    return m_streamSize;
}
StandardInputStream::StandardInputStream() :
    InputStream()
{

}
StandardInputStream::StandardInputStream(std::istream& stream, size_t size, size_t offset) :
    InputStream()
{
    setStream(stream, size, offset);
}

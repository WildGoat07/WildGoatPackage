#include "Archive.hpp"


using namespace wp;

void Archive::addFile(std::string const& file, uint64_t id)
{
    m_map[id] = file;
}
bool Archive::saveAs(std::string const& strFile)
{
    std::ofstream file(strFile, std::ios_base::binary);
    if (file.bad())
        return false;
    {
        uint64_t size = m_map.size();
        file.write((char*)(&size), 4);
    }
    for (std::map<uint64_t, std::string>::iterator it = m_map.begin();it!=m_map.end();it++)
    {
        wp::File tmp(it->second);
        if (!tmp.isFolder())
        {
            uint64_t id = it->first;
            file.write((char*)(&id), 4);
            uint64_t size = tmp.size();
            file.write((char*)(&size), 4);
        }
    }
    for (std::map<uint64_t, std::string>::iterator it = m_map.begin();it!=m_map.end();it++)
    {
        wp::File tmp(it->second);
        if (!tmp.isFolder())
        {
            std::ifstream inputFile(it->second, std::ios_base::binary);
            char carac;
            while (inputFile.get(carac))
                file.write(&carac, 1);
        }
    }

    return true;
}


bool Extractor::open(std::string const& strFile)
{
    m_file.open(strFile, std::ios_base::binary);
    uint64_t nbFiles;
    m_file.read((char*)(&nbFiles), 4);
    for (uint64_t i = 0;i<nbFiles;i++)
    {
        uint64_t id, size;
        m_file.read((char*)(&id), 4);
        m_file.read((char*)(&size), 4);
        m_map[id] = size;
    }
}
bool Extractor::select(uint64_t id)
{
    uint64_t start = 4 + 8*m_map.size();
    for (std::map<uint64_t, uint64_t>::iterator it = m_map.begin();it!=m_map.end();it++)
    {
        if (it->first == id)
        {
            if (size != nullptr)
            *size = it->second;
            m_file.seekg(start);
            m_offset = start;
            m_selection = id;
            return true;
        }
        else
            start += it->second;
    }
    return false;
}
sf::Int64 Extractor::read(void* ptr, sf::Int64 size)
{
    sf::Int64 bytesRead = 0;
    for (sf::Int64 i = 0;i<size;i++)
    {
        char carac;
        if (m_file->get(carac))
        {
            ((char*)ptr)[bytesRead] = carac;
            bytesRead++;
        }
        else
            return bytesRead;
    }
    return bytesRead;
}
sf::Int64 Extractor::seek(sf::Int64 position)
{
    m_file->seekg(position + m_offset);
    return m_file->tellg();
}
sf::Int64 Extractor::tell()
{
    return m_file->tellg() - m_offset;
}
sf::Int64 Extractor::getSize()
{
    return m_map[m_selection];
}
uint64_t Extractor::getSelectedFile() const
{
    return m_selection;
}

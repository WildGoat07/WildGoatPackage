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
std::istream& Extractor::getFile(uint64_t id, uint64_t* size)
{
    uint64_t start = 4 + 8*m_map.size();
    for (std::map<uint64_t, uint64_t>::iterator it = m_map.begin();it!=m_map.end();it++)
    {
        if (it->first == id)
        {
            if (size != nullptr)
            *size = it->second;
            m_file.seekg(start);
            return m_file;
        }
        else
            start += it->second;
    }
}
StandardInputStream Extractor::getFileAsSfStream(uint64_t id)
{
    uint64_t size;
    std::istream& tmp(this->getFile(id, &size));
    StandardInputStream stream(tmp, size, tmp.tellg());
    return stream;
}

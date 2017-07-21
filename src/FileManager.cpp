#include "FileManager.hpp"

namespace wp
{
    File const& FileManager::operator[](unsigned int index) const
    {
        return m_files[index];
    }
    size_t FileManager::size() const
    {
        return m_files.size();
    }
    std::string FileManager::getCurrentDirectory() const
    {
        return m_directory;
    }
    bool FileManager::setDirectory(std::string s)
    {
        m_directory = s;
        m_files.clear();
        DIR* rep = opendir(s.c_str());
        if (rep == nullptr)
        {
            m_directory = "";
            return false;
        }
        if (s[s.size()-1] != '\\' || s[s.size()-1] != '/')
            s += '\\';
        dirent* f;
        while ((f = readdir(rep)) != nullptr)
        {
            std::string name = f->d_name;
            if (name != "." && name != "..")
                m_files.push_back(File(s + name));
        }
        return true;
    }
    void FileManager::update()
    {
        setDirectory(m_directory);
    }
}

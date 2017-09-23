#include "File.hpp"

namespace wp
{
    File::File() {}

    File::File(std::string path)
    {
        if (path[path.size()-1] == '\\' || path[path.size()-1] == '/')
            path = path.substr(0, path.size()-1);
        int lastSlash = -1;
        for (int i = 0;i<path.size();i++)
        {
            if (path[i] == '\\' || path[i] == '/')
                lastSlash = i;
        }
        if (path.substr(0, 2) == "..")
        {
            m_name = "";
            m_path = path + "\\";
        }
        else if (lastSlash == -1)
        {
            m_path = "\\";
            m_name = path;
        }
        else
        {
            m_path = path.substr(0, lastSlash+1);
            m_name = path.substr(lastSlash+1, path.size()-lastSlash-1);
        }
    }
    std::string File::getPath() const
    {
        std::string m_tmp = m_path;
        if (m_tmp[1] != ':')
        {
            if (m_tmp[0] == '\\' || m_tmp[0] == '/')
                m_tmp = m_tmp.substr(1, m_tmp.size()-1);
        }
        return m_tmp;
    }
    std::string File::getFullPath() const
    {
        return getPath() + getFullName();
    }
    std::string File::getFullName() const
    {
        return m_name;
    }
    std::string File::getName() const
    {
        if (m_name == ".." || isFolder())
            return m_name;
        int lastPoint = -1;
        for (int i = 0;i<m_name.size();i++)
        {
            if (m_name[i] == '.')
                lastPoint = i;
        }
        if (lastPoint != -1)
            return m_name.substr(0, lastPoint);
        else
            return m_name;
    }
    std::string File::getExt() const
    {
        if (isFolder())
            return "";
        int lastPoint = 0;
        for (int i = 0;i<m_name.size();i++)
        {
            if (m_name[i] == '.')
                lastPoint = i;
        }
        if (lastPoint != 0)
            return m_name.substr(lastPoint+1, m_name.size()-lastPoint-1);
        else
            return "";
    }
    File File::getParent() const
    {
        if (m_path.size() == 1)
        {
            if (m_name == "")
                return File("..\\");
            else
                return File("\\");
        }
        int lastSlash = -1;
        for (int i = 0;i<m_path.size()-1;i++)
        {
            if (m_path[i] == '\\' || m_path[i] == '/')
                lastSlash = i;
        }
        if (m_path.substr(0, 2) == "..")
            return File("..\\" + m_path);
        if (lastSlash == -1)
            return File("\\" + m_path.substr(0, m_path.size()));
        return File(m_path.substr(0, m_path.size()-1));
    }
    bool File::exist() const
    {
        INT_PTR tmp = GetFileAttributesA(getFullPath().c_str());
        if ((int)tmp == -1)
            return false;
        else
            return true;
    }
    bool File::isFolder() const
    {
        if (!exist())
            return false;
        char buff[MAX_PATH];
        GetModuleFileName(nullptr, buff, MAX_PATH);
        File tmp(buff);
        struct stat buffer;
        if (getFullPath()[1] == ':')
            stat(getFullPath().c_str(), &buffer);
        else
            stat((tmp.getPath() + getFullPath()).c_str(), &buffer);
        if (buffer.st_mode & S_IFDIR)
            return true;
        else
            return false;
    }
    void File::rename(std::string newName)
    {
        m_name = newName;
    }
    std::string File::getAbsoluteDirectory() const
    {
        char buff[MAX_PATH];
        GetModuleFileName(nullptr, buff, MAX_PATH);
        File tmp(buff);
        if (getFullPath()[1] == ':')
            return getFullPath();
        else
            return tmp.getPath().substr(0, tmp.getPath().size()-1) + getFullPath();
    }
    long File::size() const
    {
        if (!exist())
             return -1;
        if (isFolder())
            return -1;
        std::ifstream tmp(getFullPath(), std::ios_base::binary);
        tmp.seekg(0, std::ios_base::end);
        return tmp.tellg();
    }
    File::Attributes File::getAttributes() const
    {
        Attributes tmp;
        INT_PTR res = GetFileAttributesA(getFullPath().c_str());
        tmp.archive = FILE_ATTRIBUTE_ARCHIVE & res;
        tmp.compressed = FILE_ATTRIBUTE_COMPRESSED & res;
        tmp.system = (FILE_ATTRIBUTE_DEVICE | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_VIRTUAL) & res;
        tmp.hidden = FILE_ATTRIBUTE_HIDDEN & res;
        tmp.readOnly = FILE_ATTRIBUTE_READONLY & res;
        tmp.temporary = FILE_ATTRIBUTE_TEMPORARY & res;
        return tmp;
    }
}

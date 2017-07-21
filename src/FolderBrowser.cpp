#include "FolderBrowser.hpp"

namespace wp
{
    FolderBrowser::FolderBrowser()
    {
        m_window = nullptr;
        m_displayFiles = false;
    }
    void FolderBrowser::setWindowBlock(sf::Window& w)
    {
        m_window = &w;
    }
    void FolderBrowser::displayFiles(bool b)
    {
        m_displayFiles = b;
    }
    void FolderBrowser::setTitle(std::string t)
    {
        m_title = t;
    }
    bool FolderBrowser::openFolder(File* f) const
    {
        BROWSEINFO param;

        if (m_window == nullptr)
            param.hwndOwner = nullptr;
        else
            param.hwndOwner = m_window->getSystemHandle();
        param.pidlRoot = nullptr;

        char buff[MAX_PATH];
        param.pszDisplayName = buff;

        param.lpszTitle = m_title.c_str();
        param.ulFlags = 0x2 | 0x40 | 0x10;
        if (m_displayFiles)
            param.ulFlags |= 0x4000;
        param.lpfn = nullptr;
        param.iImage = 0;
        LPITEMIDLIST pidl = SHBrowseForFolder(&param);
        if (pidl != 0)
        {
            char sPath[MAX_PATH], sBuffer[MAX_PATH];
            if (SHGetPathFromIDList(pidl, sPath))
            {
                *f = File(sPath);
                return true;
            }
            return false;
        }
        return false;
    }
}


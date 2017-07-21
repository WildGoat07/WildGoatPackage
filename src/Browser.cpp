#include "Browser.hpp"

namespace wp
{
    Browser::Browser()
    {
        m_multiSelect = false;
        m_window = nullptr;
    }
    void Browser::setInitialDirectory(File const& f)
    {
        m_initialFile = f;
    }
    void Browser::setInitialDirectory(std::string const& s)
    {
        m_initialFile = File(s);
    }
    void Browser::addExtension(Browser::Extension ext)
    {
        m_extensions.push_back(ext);
    }
    void Browser::setWindowBlock(sf::Window& w)
    {
        m_window = &w;
    }
    void Browser::allowMultiSelect(bool m)
    {
        m_multiSelect = m;
    }
    void Browser::setTitle(std::string t)
    {
        m_title = t;
    }
    bool Browser::openFile(std::vector<File>* f) const
    {
        OPENFILENAME ofn;
        char szFileName[MAX_PATH];
        std::string tmp = m_initialFile.getFullPath();
        for (int i = 0;i<tmp.size();i++)
            szFileName[i] = tmp[i];
        szFileName[tmp.size()] = '\0';

        ZeroMemory(&ofn, sizeof(ofn));

        ofn.lStructSize = sizeof(ofn);

        if (m_window == nullptr)
            ofn.hwndOwner = nullptr;
        else
            ofn.hwndOwner = m_window->getSystemHandle();
        char extensionsChar[500];
        unsigned int indexExtensions = 0;
        for (int i = 0;i<m_extensions.size();i++)
        {
            char tmp2[250];
            unsigned int indexTmp2 = 0;
            for (int j = 0;j<m_extensions[i].label.size();j++)
            {
                tmp2[indexTmp2] = m_extensions[i].label[j];
                indexTmp2++;
            }
            tmp2[indexTmp2] = '\0';
            indexTmp2++;
            for (int j = 0;j<m_extensions[i].values.size();j++)
            {
                tmp2[indexTmp2] = '*';
                indexTmp2++;
                tmp2[indexTmp2] = '.';
                indexTmp2++;
                for (int k = 0;k<m_extensions[i].values[j].size();k++)
                {
                    tmp2[indexTmp2] = m_extensions[i].values[j][k];
                    indexTmp2++;
                }
                if (j != m_extensions[i].values.size()-1)
                {
                    tmp2[indexTmp2] = ';';
                    indexTmp2++;
                }
            }
            tmp2[indexTmp2] = '\0';
            indexTmp2++;
            for (int j = 0;j<indexTmp2;j++)
            {
                extensionsChar[indexExtensions + j] = tmp2[j];
            }
            indexExtensions += indexTmp2;
        }
        extensionsChar[indexExtensions] = '\0';
        ofn.lpstrFilter = extensionsChar;
        ofn.lpstrFile = szFileName;
        ofn.nMaxFile = MAX_PATH;
        if (m_multiSelect)
            ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT;
        else
            ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
        ofn.lpstrInitialDir = nullptr;
        ofn.lpstrTitle = m_title.c_str();
        bool success = GetOpenFileName(&ofn);
        if (!success)
            return false;


        f->clear();

        bool end = false;
        std::string currentString;
        int index = 0;
        if (!m_multiSelect)
        {
            f->push_back(std::string(szFileName));
            end = true;
        }
        while (!end)
        {
            char data = szFileName[index];
            if (data == '\0')
            {
                if (szFileName[index+1] == 0)
                {
                    f->push_back(File(currentString));
                    currentString = "";
                    end = true;
                }
                else
                {
                    f->push_back(File(currentString));
                    currentString = "";
                }
            }
            else
                currentString += data;
            index++;
        }
        if (f->size() > 1)
        {
            std::vector<File> tmp;
            for (int i = 1;i<f->size();i++)
                tmp.push_back(File((*f)[0].getFullPath() + '/' + (*f)[i].getFullPath()));
            *f = tmp;
        }
        return true;
    }
    bool Browser::saveFile(File* f) const
    {
        OPENFILENAME ofn;
        char szFileName[MAX_PATH];
        std::string tmp = m_initialFile.getFullPath();
        tmp = tmp.substr(1);
        for (int i = 0;i<tmp.size();i++)
            szFileName[i] = tmp[i];
        szFileName[tmp.size()] = '\0';

        ZeroMemory(&ofn, sizeof(ofn));

        ofn.lStructSize = sizeof(ofn);

        if (m_window == nullptr)
            ofn.hwndOwner = nullptr;
        else
            ofn.hwndOwner = m_window->getSystemHandle();
        tmp = "";
        for (int i = 0;i<m_extensions.size();i++)
        {
            std::string tmp2 = m_extensions[i].label + "\t";
            for (int j = 0;j<m_extensions[i].values.size();j++)
            {
                tmp2 += "*." + m_extensions[i].values[j];
                if (j != m_extensions[i].values.size()-1)
                    tmp2 += ";";
            }
            tmp2 += "\t";
            tmp += tmp2;
        }
        char tmpString[MAX_PATH];
        for (int i = 0;i<tmp.size();i++)
        {
            tmpString[i] = tmp[i];
            if (tmpString[i] == '\t')
                tmpString[i] = '\0';
        }
        tmpString[tmp.size()] = '\0';
        ofn.lpstrFilter = tmpString;
        ofn.lpstrFile = szFileName;
        ofn.nMaxFile = MAX_PATH;
            ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
        ofn.lpstrInitialDir = nullptr;
        ofn.lpstrTitle = m_title.c_str();
        bool success = GetSaveFileName(&ofn);

        if (!success)
            return false;

        *f = File(szFileName);

        return success;
    }
}

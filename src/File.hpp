#ifndef DEF_FILE_HPP
#define DEF_FILE_HPP
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <windows.h>

namespace wp
{
    /** \brief Class for managing a file.
    *
    *   \class File
    *
    *   An user-friendly class to easily get informations from a file.
     */
    class File
    {
    private:
        std::string m_name;
        std::string m_path;
    public:
        /** \brief If the file exists.
        *
        *   Returns true if the file exists.
         *
         * \return bool : true if the file exists.
         *
         */
        bool exist() const;
        /** \brief Constructor.
         *
         *
         */
        File();
        /** \brief Constructor.
        *
        *   Constructs the file from its path or name. Doesn't modify the ROM.
         *
         * \param std::string : path or name.
         *
         */
        File(std::string);
        /** \brief Returns its full name.
        *
        *   Returns the full name of the file ("example.txt").
         *
         * \return std::string : the full name.
         *
         */
        std::string getFullName() const;
        /** \brief Returns its full path.
        *
        *   Returns the full path of the file ("folder/example.txt"), specified in the constructor or by rename().
         *
         * \return std::string : the full path.
         *
         */
        std::string getFullPath() const;
        /** \brief Returns its absolute directory
        *
        *   Returns the full path of the file ("C:/folder/example.txt"). May be wrong for files specified relatively.
         *
         * \return std::string : the full path.
         *
         */
        std::string getAbsoluteDirectory() const;
        /** \brief Returns its name.
        *
        *   Returns the name of the file ("example").
         *
         * \return std::string : the name.
         *
         */
        std::string getName() const;
        /** \brief Returns its path.
        *
        *   Returns the path only of the file ("folder").
         *
         * \return std::string : the path.
         *
         */
        std::string getPath() const;
        /** \brief Returns its extension.
        *
        *   Returns the extension of the file ("txt"). Returns an empty std::string if there is no extension.
         *
         * \return std::string : the extension.
         *
         */
        std::string getExt() const;
        /** \brief Returns its parent.
        *
        *   Returns the parent folder. If specified relatively, the next parents will be relatives.
         *
         * \return File : the parent.
         *
         */
        File getParent() const;
        /** \brief Renames the file.
        *
        *   Renames the file. Doesn't modify the ROM.
         *
         * \param std::string : the new name.
         * \return void
         *
         */
        void rename(std::string);
        /** \brief If the file is a folder.
        *
        *   Returns true if the file is a folder. Returns false if exist() failed.
         *
         * \return bool : true if the file is a folder.
         *
         */
        bool isFolder() const;
    };
}

#endif // DEF_FILE_HPP


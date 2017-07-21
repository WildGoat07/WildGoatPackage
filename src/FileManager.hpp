#ifndef DEF_FILE_MANAGER_HPP
#define DEF_FILE_MANAGER_HPP
#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>
#include "File.hpp"
namespace wp
{
    /** \brief Class FileManager
    *
    *   Explores files from a given path.
     */
    class FileManager
    {
        std::vector<File> m_files;
        std::string m_directory;
    public:
        /** \brief Sets the new Directory.
        *
        *   Sets the directory from where to search the files.
         *
         * \param std::string : path of the directory.
         * \return bool : return false if it failed.
         *
         */
        bool setDirectory(std::string);
        /** \brief Returns a file.
        *
        *   Returns the specified file.
         *
         * \param int unsigned : index of the file.
         * \return File const& : the specified File.
         *
         */
        File const& operator[](unsigned int) const;
        /** \brief Updates the directory.
        *
        *   Refreshes the directory from where to search the files.
         *
         * \return void
         *
         */
        void update();
        /** \brief Returns the size of the directory.
        *
        *   Returns the size of all the files and folders in the current directory. Doesn't include subfolders and subfiles.
         *
         * \return size_t : size of the directory.
         *
         */
        size_t  size() const;
        /** \brief Returns the current directory.
        *
        *   Returns the path of the current directory. Returns an empty std::string if no directory were specified or if setDirectory() failed.
         *
         * \return std::string : path to the current directory.
         *
         */
        std::string getCurrentDirectory() const;
    };
}

#endif // DEF_FILE_MANAGER_HPP

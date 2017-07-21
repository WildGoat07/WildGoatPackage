#ifndef DEF_FOLDER_BROWSER_HPP
#define DEF_FOLDER_BROWSER_HPP
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <SFML/Window.hpp>
#include <Windows.h>
#include <Commdlg.h>
#include <Shlobj.h>
#include "File.hpp"

namespace wp
{
    /** \brief Displays a folder browser window.
    *
    *   Displays the native window to search a folder.
    *   \class FolderBrowser
     */
    class FolderBrowser
    {
    private:
        sf::Window* m_window;
        std::string m_title;
        bool m_displayFiles;
    public:
        /** \brief Constructor.
         *
         *
         */
        FolderBrowser();
        /** \brief Displays the files.
        *
        *   Chose to display the file or not in the window.
         *
         * \param bool : true to display the files(Optional).
         * \return void
         *
         */
        void displayFiles(bool = true);
        /** \brief Blocks a window
        *
        *   Set a parent window that will be blocked by the folder browser window.
         *
         * \param sf::Window& : reference to the main window.
         * \return void
         *
         */
        void setWindowBlock(sf::Window&);
        /** \brief Sets a title.
        *
        *   Give your window a title.
         *
         * \param std::string : title of the window.
         * \return void
         *
         */
        void setTitle(std::string);
        /** \brief Opens the window.
        *
        *   Opens the window to search the folder.
         *
         * \param File* : pointer to a File containing the folder.
         * \return bool : false if it failed.
         *
         */
        bool openFolder(File*) const;
    };
}

#endif // DEF_FOLDER_BROWSER_HPP


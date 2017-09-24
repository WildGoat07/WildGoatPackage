#ifndef DEF_BROWSER_HPP
#define DEF_BROWSER_HPP
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <SFML/Window.hpp>
#include <Windows.h>
#include <Commdlg.h>
#include "File.hpp"

namespace wp
{
    /** \brief Class to select a file.
    *
    *   This class open the generic browser window to open/save (a) file(s). Note that this class require the library "libcomdlg32.a" linked.
    *
    *   \class Browser
     */
    class Browser
    {
    public:
        /** \brief Provides informations of an extension type.
        *
        *   \struct Extension
         */
        struct Extension
        {
            std::string label;/**< the label of the extension, what will be displayed on the window */
            std::vector<std::string> values;/**< the extensions (example : "txt" or "*" for any) */
        };
    private:
        bool m_multiSelect;
        sf::Window* m_window;
        std::vector<Extension> m_extensions;
        File m_initialFile;
        std::string m_title;
    public:
        /** \brief Constructor.
         *
         *
         */
        Browser();
        /** \brief Blocks a certain window when opened.
        *
        *   Forces the focus of the browser window instead of the sfml window.
         *
         * \param sf::Window& : window to block.
         * \return void
         *
         */
        void setWindowBlock(sf::Window&);
        /** \brief Sets a title to the window.
         *
         * \param std::string : title.
         * \return void
         *
         */
        void setTitle(std::string);
        /** \brief Adds an extension to the browser.
        *
        *   Adds an extension filter in the browser.
         *
         * \param Extension : extension type.
         * \return void
         *
         */
        void addExtension(Extension);
        /** \brief Sets the initial directory to start from.
        *
        *   (Optional).
         *
         * \param std::string const& : directory.
         * \return void
         *
         */
        void setInitialDirectory(std::string const&);
        /** \brief Sets the initial file to start from.
        *
        *   (Optional).
         *
         * \param File const& : file to start from.
         * \return void
         *
         */
        void setInitialDirectory(File const&);
        /** \brief Allows multi selection in browser.
        *
        *   If true, the user can chose many files instead of one.
         *
         * \param bool : true for multi selection.
         * \return void
         *
         */
        void allowMultiSelect(bool = true);
        /** \brief Opens the browser window as "open file".
        *
        *   Opens the browser window to open a file or many files.
         *
         * \param std::vector<File>* : pointer to the list of opened files.
         * \return bool : return false if failed.
         *
         */
        bool openFile(std::vector<File>*) const;
        /** \brief Opens the browser window as "save file".
        *
        *   Opens the browser window to save a file. The user can chose only one file, even if allowMultiSelect() was set as true.
         *
         * \param File* : pointer to the saved files.
         * \return bool : return false if failed.
         *
         */
        bool saveFile(File*) const;
    };
}

#endif // DEF_BROWSER_HPP


#ifndef DEF_CURSOR_HPP
#define DEF_CURSOR_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

namespace wp
{
    /** \brief Class that allows to change the cursor.
    *
    *   \class Cursor
     */
    class Cursor
    {
    public:
        static const uint8_t WAIT_LOADING = 1;/**< the busy cursor */
        static const uint8_t BACK_LOADING = 2;/**< the loading cursor with arrow */
        static const uint8_t ARROW = 3;/**< the basic arrow */
        static const uint8_t CROSS = 4;/**< the cross */
        static const uint8_t CLICK = 5;/**< the link clicker cursor */
        static const uint8_t HELP = 6;/**< the help arrow */
        static const uint8_t TEXT_SELECT = 7;/**< the text selector */
        static const uint8_t UNABLE = 8;/**< the unable cursor */
        static const uint8_t SIZE_ALL = 9;/**< the resize cursor in 4 directions */
        static const uint8_t SIZE_TOPLEFT_BOTRIGHT = 10;/**< the regular side way resize cursor */
        static const uint8_t SIZE_TOP_BOT = 11;/**< the vertical resize cursor */
        static const uint8_t SIZE_LEFT_RIGHT = 12;/**< the horizontal resize cursor */
        static const uint8_t SIZE_TOPRIGHT_BOTLEFT = 13;/**< the reversed side way resize cursor */
        static const uint8_t UP_ARROW = 14;/**< the UP arrow */
    private:
        HCURSOR curs;
    public:
        /** \brief loads a cursor.
        *
        *   Loads the Windows generic cursor by his ID.
         *
         * \param uint8_t : ID of the cursor.
         * \return void
         *
         */
        void setCursorID(uint8_t);
        /** \brief loads a cursor.
        *
        *   Loads the cursor from a .ico file.
         *
         * \param sf::String const& : file path.
         * \return void
         *
         */
        void setCursorFromFile(sf::String const&);
        /** \brief Applies the current cursor.
        *
        *   Applies the current cursor selected to a sfml window. Note : the negative based cursor (text selector or cross) and animated cursor are bugged for unknown reason.
         *
         * \param sf::Window& : window to display the cursor.
         * \return void
         *
         */
        void apply(sf::Window const&) const;
    };
}

#endif // DEF_CURSOR_HPP

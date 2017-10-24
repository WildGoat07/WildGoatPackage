#ifndef DEF_WP_KEY_SET_HPP
#define DEF_WP_KEY_SET_HPP
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

namespace wp
{
    /////////////////////////////////////////////////
        /// \brief Class to store a set of keys
    ///
    ///Can store a set of keys (e.g. CTRL + Z) and do operations on it.
    ///\class KeySet
    /////////////////////////////////////////////////
    class KeySet
    {
    private:
        bool m_shift;
        bool m_ctrl;
        bool m_alt;
        uint16_t m_code;
        bool m_mouse;

    public:
        /////////////////////////////////////////////////
                /// \brief Operator to a native code.
        ///
        ///Converts the set to a 64 bit integer for natives operations.
        ///
        /// \return operator
        ///
        /////////////////////////////////////////////////
        operator uint64_t() const;

        /////////////////////////////////////////////////
                /// \brief Creates a set of a keyboard key.
        ///
        /// \param uint16_t : keyboard key.
        /// \param bool : Ctrl key pressed (Optional).
        /// \param bool : Shift key pressed (Optional).
        /// \param bool : Alt key pressed (Optional).
        /// \return void
        ///
        /////////////////////////////////////////////////
        void createKey(uint16_t, bool = false, bool = false, bool = false);
        /////////////////////////////////////////////////
                /// \brief Creates a set of a mouse key.
        ///
        /// \param uint16_t : mouse key.
        /// \param bool : Ctrl key pressed (Optional).
        /// \param bool : Shift key pressed (Optional).
        /// \param bool : Alt key pressed (Optional).
        /// \return void
        ///
        /////////////////////////////////////////////////
        void createMouseKey(uint16_t, bool = false, bool = false, bool = false);
        /////////////////////////////////////////////////
                /// \brief Creates a set from a code.
        ///
        /// \param uint64_t : code of the set.
        /// \return void
        ///
        /////////////////////////////////////////////////
        void create(uint64_t);
        /////////////////////////////////////////////////
                /// \brief Returns true if Ctrl is pressed.
        ///
        /// \return bool : true if Ctrl is pressed.
        ///
        /////////////////////////////////////////////////
        bool ctrl() const;
        /////////////////////////////////////////////////
                /// \brief Returns true if Alt is pressed.
        ///
        /// \return bool : true if Alt is pressed.
        ///
        /////////////////////////////////////////////////
        bool alt() const;
        /////////////////////////////////////////////////
                /// \brief Returns true if Shift is pressed.
        ///
        /// \return bool : true if Shift is pressed.
        ///
        /////////////////////////////////////////////////
        bool shift() const;
        /////////////////////////////////////////////////
                /// \brief Returns true if the it's a mouse code.
        ///
        /// \return bool : true if it's a mouse code.
        ///
        /////////////////////////////////////////////////
        bool isMouse() const;
        /////////////////////////////////////////////////
                /// \brief Returns the SFML code of the key.
        ///
        /// \return uint16_t : code.
        ///
        /////////////////////////////////////////////////
        uint16_t sfCode() const;
    };
}

#endif // DEF_WP_KEY_SET_HPP

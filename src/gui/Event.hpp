#ifndef DEF_WP_GUI_EVENT_HPP
#define DEF_WP_GUI_EVENT_HPP
#include <iostream>


namespace wp
{
    namespace gui
    {

        /////////////////////////////////////////////////
                /// \brief Events of the widgets.
        ///It will contains all the events of its widget.
        /////////////////////////////////////////////////
        class Event
        {
            bool m_code[256];
        public:
            Event();
            Event(unsigned int);
            Event(Event const&);
            void operator=(Event const&);
            /////////////////////////////////////////////////
                        /// \brief += operator.
            ///Use this operator to add a triggered event.
            ///
            /// \param const& Event : event to add.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void operator+=(Event const&);
            /////////////////////////////////////////////////
                        /// \brief Returns true if equal.
            ///Returns true **only** if the second event contain **one** of the triggered events.
            ///
            /// \param const& Event
            /// \return bool
            ///
            /////////////////////////////////////////////////
            bool equal(Event const&) const;
        };
    }
}
/////////////////////////////////////////////////
/// \brief Same as wp::gui::Event::equal().
///
/// \param const& wp::gui::Event : event 1.
/// \param const& wp::gui::Event : event 2.
/// \return bool : true if equal.
///
/////////////////////////////////////////////////
bool operator==(wp::gui::Event const&, wp::gui::Event const&);
/////////////////////////////////////////////////
/// \brief Opposite of ==.
///
/// \param const& wp::gui::Event : event 1.
/// \param const& wp::gui::Event : event 2.
/// \return bool : false if equal.
///
/////////////////////////////////////////////////
bool operator!=(wp::gui::Event const&, wp::gui::Event const&);
/////////////////////////////////////////////////
/// \brief Same as wp::gui::Event::operator+=().
///
/// \param const& wp::gui::Event : event 1.
/// \param const& wp::gui::Event : event 2.
/// \return wp::gui::Event : new event.
///
/////////////////////////////////////////////////
wp::gui::Event operator+(wp::gui::Event const&, wp::gui::Event const&);


#endif // DEF_WP_GUI_EVENT_HPP

#ifndef DEF_WP_GUI_BASE_WIDGET
#define DEF_WP_GUI_BASE_WIDGET
#include <SFML/Graphics.hpp>
#include "Event.hpp"

namespace wp
{
    /////////////////////////////////////////////////
        /// \brief The gui module.
    ///
    ///The gui module provide multiple class to create fast and easily widgets.
    ///
    /// \namespace wp::gui
    ///
    /////////////////////////////////////////////////
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief base of all widget
        ///
        ///The base class of all widget. Provides basic events managing and the minimum required for every widget.
        ///
        ///\class BaseWidget
        /////////////////////////////////////////////////
        class BaseWidget : public sf::Transformable, public sf::Drawable
        {
        protected:
            Event m_ownEvent;
            BaseWidget const* m_relativeTo = nullptr;
            int m_relativeMode;
            sf::Vector2f m_relativePos;
            sf::RenderWindow* m_handle = nullptr;
            sf::Vector2f m_padding = sf::Vector2f(5, 5);
            bool m_dbClicDown = false;
            bool m_validClic = false;
            virtual void _implEvent(sf::Event const&, Event&, sf::View const&);
            virtual void _implUpdate();
            virtual sf::FloatRect _getHitbox() const = 0;
            int m_leftClic = 0;
        public:
            /////////////////////////////////////////////////
                        /// \brief Returns its own event.
            ///
            ///The event returned will be only effective for this instance of the widget ; every widget has its own events.
            ///
            /// \return Event const& : event.
            ///
            /////////////////////////////////////////////////
            Event const& getEvent() const;
            /////////////////////////////////////////////////
                        /// \brief Handles events.
            ///
            ///Update the event of the widget. Necessary to be called every loop and to be interactive.
            ///
            /// \param const& sf::Event : SFML event of the window.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void handleEvent(sf::Event const&);
            /////////////////////////////////////////////////
                        /// \brief Updates the visual part of the widget.
            ///
            ///Must be called every loop.
            ///
            /// \return void
            ///
            /////////////////////////////////////////////////
            void update();
            /////////////////////////////////////////////////
                        /// \brief Returns its global bounding box.
            ///
            /// \return sf::FloatRect : bounding box.
            ///
            /////////////////////////////////////////////////
            sf::FloatRect getGlobalBounds() const;
            /////////////////////////////////////////////////
                        /// \brief Returns its local bounding box.
            ///
            /// \return sf::FloatRect : bounding box.
            ///
            /////////////////////////////////////////////////
            virtual sf::FloatRect getLocalBounds() const = 0;
            /////////////////////////////////////////////////
                        /// \brief Sets the position relative to another widget.
            ///
            ///To stop the widget to be relative to another one, sets the second parameter to NULL.
            ///
            /// \param const* BaseWidget : relative to this widget (NULL to cancel).
            /// \param sf::Vector2f : offset position (Optional).
            /// \param int : the mode of relative position (bottom left by default) (Optional).
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setRelativeTo(BaseWidget const*, sf::Vector2f = sf::Vector2f(), int = 2);
            /////////////////////////////////////////////////
                        /// \brief Sets the window on which is drawn the widget.
            ///
            ///Should be set as soon as possible once the widget is created.
            ///
            /// \param sf::RenderWindow& : window.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setHandle(sf::RenderWindow&);
            /////////////////////////////////////////////////
                        /// \brief Sets the padding of the widget.
            ///
            ///The padding is the outer-space of the widget to separate 2 relatives widgets. Does not make the widget bigger.
            ///
            /// \param sf::Vector2f : padding (5,5 by default).
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setPadding(sf::Vector2f);
        };
        enum
        {
            TOP_LEFT = 0,///< position relative to the top left point
            TOP_RIGHT,///< position relative to the top right point
            BOT_LEFT,///< position relative to the bottom left point
            BOT_RIGHT///< position relative to the bottom right point
        };
        static const Event MOUSE_BUTTON_LEFT_DOWN = Event(0);
        static const Event MOUSE_BUTTON_LEFT_UP = Event(1);
        static const Event MOUSE_BUTTON_RIGHT_DOWN = Event(2);
        static const Event MOUSE_BUTTON_RIGHT_UP = Event(3);
        static const Event MOUSE_BUTTON_MIDDLE_DOWN = Event(4);
        static const Event MOUSE_BUTTON_MIDDLE_UP = Event(5);
        static const Event MOUSE_BUTTON_X1_DOWN = Event(6);
        static const Event MOUSE_BUTTON_X1_UP = Event(7);
        static const Event MOUSE_BUTTON_X2_DOWN = Event(8);
        static const Event MOUSE_BUTTON_X2_UP = Event(9);
        static const Event MOUSE_ENTERED = Event(10);
        static const Event MOUSE_LEAVED = Event(11);
        static const Event MOUSE_ON_WIDGET = Event(12);
        static const Event MOUSE_LEFT_CLIC = Event(13);
        static const Event MOUSE_RIGHT_CLIC = Event(14);
        static const Event MOUSE_X1_CLIC = Event(15);
        static const Event MOUSE_X2_CLIC = Event(16);
        static const Event MOUSE_WHEEL_UP = Event(17);
        static const Event MOUSE_WHEEL_DOWN = Event(18);
        static const Event MOUSE_MIDDLE_CLIC = Event(19);
    }
}

#endif // DEF_WP_GUI_BASE_WIDGET

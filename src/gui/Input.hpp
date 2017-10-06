#ifndef DEF_WP_GUI_INPUT_HPP
#define DEF_WP_GUI_INPUT_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief An input bar.
        ///\class Input
        /////////////////////////////////////////////////
        class Input : public BaseWidget
        {
            const sf::Time m_beamFreq = sf::milliseconds(1200);
            sf::VertexArray m_lines;
            sf::RectangleShape m_rectangle;
            Resource* m_res;
            sf::Text m_textBuff;
            bool m_numOnly = false;
            bool m_password = false;
            bool m_pressed = false;
            bool m_selected = false;
            bool m_clickDown = false;
            int m_cursPos;
            int m_startingCursPos;
            std::string m_text;
            std::string m_defaultText;
            float m_minLength;
            sf::Clock m_internClock;
            sf::RectangleShape m_beam;

            virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
            virtual sf::FloatRect _getHitbox() const override;
            virtual void _implUpdate() override;
            virtual void _implEvent(sf::Event const&, Event&, sf::View const&) override;
            float _getTextWidth(int) const;
        public:
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            /// \param Resource& : resources
            ///
            /////////////////////////////////////////////////
            Input(Resource&);
            virtual sf::FloatRect getLocalBounds() const override;
            /////////////////////////////////////////////////
                        /// \brief Sets its intern text.
            ///
            /// \param const& std::string : intern text.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setText(std::string const&);
            /////////////////////////////////////////////////
                        /// \brief Returns its intern text.
            ///
            /// \return std::string const& : intern text.
            ///
            /////////////////////////////////////////////////
            std::string const& getText() const;
            /////////////////////////////////////////////////
                        /// \brief Sets in password mode.
            ///
            ///The password mode will display only asterisks `*`.
            ///
            /// \param bool : true for password mode.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setPassword(bool);
            /////////////////////////////////////////////////
                        /// \brief Sets in numerical mode.
            ///
            ///The numerical mode allows only numeric values :
            ///* 0-9
            ///* .
            ///* + and -
            ///* e
            ///
            ///For example : -5.45e+12
            ///
            ///**But**, another (bad) example : eee45194849...+-+8
            ///
            /// \param bool : true for numerical mode.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setNumerical(bool);
            /////////////////////////////////////////////////
                        /// \brief Returns true if selected.
            ///
            ///When the bar is selected, it means it catches keyboard events.
            ///
            /// \return bool : true if selected.
            ///
            /////////////////////////////////////////////////
            bool isSelected() const;
            /////////////////////////////////////////////////
                        /// \brief Sets selected.
            ///
            ///When the bar is selected, it means it catches keyboard events.
            ///
            /// \param bool : true for selected.
            ///
            /////////////////////////////////////////////////
            void setSelected(bool);
            /////////////////////////////////////////////////
                        /// \brief Sets the minimum length.
            ///
            ///The minimum length is the minimum able length under which, the bar will be resized. Otherwise, the bar will be the same length as its text.
            ///
            /// \param float
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setMinimumLength(float);
            /////////////////////////////////////////////////
                        /// \brief Sets th default text which will be displayed.
            ///
            ///The default text is the one displayed when there is NO text entered.
            ///
            /// \param const& std::string : default text.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setDefauitText(std::string const&);
            /////////////////////////////////////////////////
                        /// \brief Get the highlighted text.
            ///
            ///The highlighted text is the selection with a *click & drag* move with the mouse.
            ///
            /// \return std::string : highlighted text.
            ///
            /////////////////////////////////////////////////
            std::string getHighlightedText() const;
            /////////////////////////////////////////////////
                        /// \brief Sets the position of the cursor.
            ///
            ///If the new position of the cursor is higher than the length of the text, it will be at the back of the text. You can set the second cursor (the one to highlight the text) to -1 to not cancel the selection.
            ///
            /// \param int unsigned : cursor position.
            /// \param int : highlight cursor position (Optional).
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setCursorPosition(unsigned int, int = -1);

        };
        static const Event INPUT_TEXT_CHANGED = Event(22);
        static const Event INPUT_TEXT_RETURNED = Event(23);
        static const Event INPUT_GOT_FOCUS = Event(24);
        static const Event INPUT_LOST_FOCUS = Event(25);
    }
}

#endif // DEF_WP_GUI_INPUT_HPP


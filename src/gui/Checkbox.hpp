#ifndef DEF_WP_GUI_CHECKBOX_HPP
#define DEF_WP_GUI_CHECKBOX_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief A check box
        ///\class Checkbox
        /////////////////////////////////////////////////
        class Checkbox : public BaseWidget
        {
            sf::VertexArray m_lines;
            sf::RectangleShape m_rectangle;
            sf::RectangleShape m_innerRectangle;
            Resource* m_res;
            sf::Text m_textBuff;
            bool m_pressed = false;
            bool m_checked = false;
            virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
            virtual sf::FloatRect _getHitbox() const override;
            virtual void _implUpdate() override;
            virtual void _implEvent(sf::Event const&, Event&, sf::View const&) override;
        public:
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            /// \param Resource& : resources.
            ///
            /////////////////////////////////////////////////
            Checkbox(Resource&);
            virtual sf::FloatRect getLocalBounds() const override;
            /////////////////////////////////////////////////
                        /// \brief Sets its text.
            ///
            /// \param const& std::string : text.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setText(std::string const&);
            /////////////////////////////////////////////////
                        /// \brief Sets its checked state.
            ///
            /// \param bool : true for checked.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setChecked(bool);
            /////////////////////////////////////////////////
                        /// \brief Returns its checked state.
            ///
            /// \return bool : true for checked.
            ///
            /////////////////////////////////////////////////
            bool isChecked() const;
        };
        static const Event CHECKBOX_CHANGED = Event(20);
        static const Event CHECKBOX_CHECKED = Event(26);
        static const Event CHECKBOX_UNCHECKED = Event(27);
    }
}

#endif // DEF_WP_GUI_CHECKBOX_HPP


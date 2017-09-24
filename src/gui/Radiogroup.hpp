#ifndef DEF_WP_GUI_RADIOGROUP_HPP
#define DEF_WP_GUI_RADIOGROUP_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief A group of radio buttons
        ///\class Radiogroup
        /////////////////////////////////////////////////
        class Radiogroup : public BaseWidget
        {
            struct Part
            {
                sf::CircleShape circle;
                sf::CircleShape innerCircle;
                sf::Text textBuff;
                bool selected;
                bool pressed;
            };
            unsigned int m_selection = 0;
            float m_interSpace = 5;
            Resource* m_res;
            std::vector<Part> m_choices;
            virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
            virtual sf::FloatRect _getHitbox() const override;
            virtual void _implUpdate() override;
            virtual void _implEvent(sf::Event const&, Event&, sf::View const&) override;
        public:
            /////////////////////////////////////////////////
                        /// \brief Constructor
            ///
            /// \param Resource& : resources.
            ///
            /////////////////////////////////////////////////
            Radiogroup(Resource&);
            virtual sf::FloatRect getLocalBounds() const override;
            /////////////////////////////////////////////////
                        /// \brief Adds a radio button.
            ///
            /// \param const& std::string : text of the button.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void addChoice(std::string const&);
            /////////////////////////////////////////////////
                        /// \brief Returns the selected choice.
            ///
            /// \return unsigned int : selected choice.
            ///
            /////////////////////////////////////////////////
            unsigned int getSelection() const;
            /////////////////////////////////////////////////
                        /// \brief Returns the number of choices.
            ///
            /// \return size_t : number of choices.
            ///
            /////////////////////////////////////////////////
            size_t size() const;
            /////////////////////////////////////////////////
                        /// \brief Deletes a choice.
            ///
            /// \param int unsigned : index of the choice.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void deleteChoice(unsigned int);
            /////////////////////////////////////////////////
                        /// \brief Change the selected choice.
            ///
            /// \param int unsigned : index of the choice.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setSelection(unsigned int);
            /////////////////////////////////////////////////
                        /// \brief Changes the text of a choice.
            ///
            /// \param const& std::string : text.
            /// \param int unsigned : index of the choice.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setText(std::string const&, unsigned int);
            /////////////////////////////////////////////////
                        /// \brief Sets the space between 2 choices.
            ///
            /// \param float : space (5 by default).
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setInterSpace(float);
        };

        static const Event RADIOGROUP_CHANGED = Event(21);
    }
}

#endif // DEF_WP_GUI_RADIOGROUP_HPP


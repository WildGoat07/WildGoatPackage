#ifndef DEF_WP_GUI_TEXT_HPP
#define DEF_WP_GUI_TEXT_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief A text
        ///\class Text
        /////////////////////////////////////////////////
        class Text : public BaseWidget
        {
            Resource* m_res;
            sf::Text m_textBuff;
            virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
            virtual sf::FloatRect _getHitbox() const override;
            virtual void _implUpdate() override;
        public:
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            /// \param Resource& : resources.
            ///
            /////////////////////////////////////////////////
            Text(Resource&);
            virtual sf::FloatRect getLocalBounds() const override;
            /////////////////////////////////////////////////
                        /// \brief Sets its text.
            ///
            /// \param const& std::string  :text.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setText(std::string const&);

        };
    }
}

#endif // DEF_WP_GUI_TEXT_HPP

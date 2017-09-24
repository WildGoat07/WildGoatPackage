#ifndef DEF_WP_GUI_BUTTON_HPP
#define DEF_WP_GUI_BUTTON_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief A button.
        ///\class Button
        /////////////////////////////////////////////////
        class Button : public BaseWidget
        {
            sf::VertexArray m_lines;
            sf::RectangleShape m_rectangle;
            Resource* m_res;
            sf::Text m_textBuff;
            sf::RectangleShape m_img;
            bool m_pressed = false;
            sf::Texture const* m_imgTexture = nullptr;
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
            Button(Resource&);
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
                        /// \brief Sets its image.
            ///
            ///The image will be sized to be contained in the button. Set it to NULL to cancel it.
            ///
            /// \param const* sf::Texture : texture of the image.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setImage(sf::Texture const*);

        };
    }
}

#endif // DEF_WP_GUI_BUTTON_HPP

#ifndef DEF_WP_GUI_CANVAS_HPP
#define DEF_WP_GUI_CANVAS_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief A Canvas.
        ///
        ///Used to draw a `sf::Texture` as a gui widget.
        ///\class Canvas
        /////////////////////////////////////////////////
        class Canvas : public BaseWidget
        {
            Resource* m_res;
            sf::Texture const* m_texture;
            virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
            virtual sf::FloatRect _getHitbox() const override;
        public:
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            /// \param Resource& : resources.
            ///
            /////////////////////////////////////////////////
            Canvas(Resource&);
            virtual sf::FloatRect getLocalBounds() const override;
            /////////////////////////////////////////////////
                        /// \brief Sets its text.
            ///
            /// \param const& std::string  :text.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setTexture(sf::Texture const&);

        };
    }
}

#endif // DEF_WP_GUI_CANVAS_HPP


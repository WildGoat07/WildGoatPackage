#ifndef DEF_WP_GUI_VOID_HPP
#define DEF_WP_GUI_VOID_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief An Invisible widget.
        ///Used for the basic widget interactions and events.
        ///\class Void
        /////////////////////////////////////////////////
        class Void : public BaseWidget
        {
            sf::Vector2f m_size;
            Resource* m_res;
            virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
            virtual sf::FloatRect _getHitbox() const override;
        public:
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            /// \param Resource& : resources.
            ///
            /////////////////////////////////////////////////
            Void(Resource&);
            virtual sf::FloatRect getLocalBounds() const override;
            void setSize(sf::Vector2f);
        };
    }
}

#endif // DEF_WP_GUI_VOID_HPP


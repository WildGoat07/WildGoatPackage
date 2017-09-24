#ifndef DEF_WP_GUI_EXTENDED_TEXT_HPP
#define DEF_WP_GUI_EXTENDED_TEXT_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"
#include "../RichText.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief An extended text.
        ///\class Extendedtext
        /////////////////////////////////////////////////
        class Extendedtext : public BaseWidget
        {
            Resource* m_res;
            RichText m_textBuff;
            virtual void draw(sf::RenderTarget&, sf::RenderStates) const override;
            virtual sf::FloatRect _getHitbox() const override;
            virtual void _implUpdate() override;
        public:
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            /// \param Resource& : resource.
            ///
            /////////////////////////////////////////////////
            Extendedtext(Resource&);
            virtual sf::FloatRect getLocalBounds() const override;
            /////////////////////////////////////////////////
                        /// \brief Adds a part to the wp::RichText.
            ///
            /// \param const& RichText::Part : part to add.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void addPart(RichText::Part const&);
            /////////////////////////////////////////////////
                        /// \brief Calls wp::RichText::generate().
            ///
            /// \return void
            ///
            /////////////////////////////////////////////////
            void generate();

        };
    }
}

#endif // DEF_WP_GUI_EXTENDED_TEXT_HPP


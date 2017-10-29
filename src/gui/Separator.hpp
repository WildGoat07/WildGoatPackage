#ifndef DEF_WP_GUI_SEPARATOR_HPP
#define DEF_WP_GUI_SEPARATOR_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief A Separator.
        ///\class Separator
        /////////////////////////////////////////////////
        class Separator : public BaseWidget
        {
            sf::VertexArray m_line;
            float m_length;
            int m_orientation = 1;
            Resource* m_res;
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
            Separator(Resource&);
            virtual sf::FloatRect getLocalBounds() const override;
            /////////////////////////////////////////////////
                        /// \brief Sets the length of the line.
            ///
            /// \param float : length.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setLength(float);
            /////////////////////////////////////////////////
                        /// \brief Sets the orientation of the separator.
            ///
            /// \param int : orientation.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setOrientation(int);

            static const int VERTICAL = 0;///< vertical orientation of the separator.
            static const int HORIZONTAL = 1;///< horizontal orientation of the separator.
        };
    }
}

#endif // DEF_WP_GUI_SEPARATOR_HPP


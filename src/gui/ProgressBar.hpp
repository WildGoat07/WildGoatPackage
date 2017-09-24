#ifndef DEF_WP_GUI_PROGRESSBAR_HPP
#define DEF_WP_GUI_PROGRESSBAR_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief A progress bar.
        ///\class Progressbar
        /////////////////////////////////////////////////
        class Progressbar : public BaseWidget
        {
            sf::VertexArray m_outerLines;
            sf::VertexArray m_innerLines;
            sf::RectangleShape m_outerRectangle;
            sf::RectangleShape m_innerRectangle;
            Resource* m_res;
            float m_perc;
            int m_orientation;
            float m_length;
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
            Progressbar(Resource&);
            virtual sf::FloatRect getLocalBounds() const override;
            /////////////////////////////////////////////////
                        /// \brief Sets its percentage of filling.
            ///
            /// \param float : percentage.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setPerc(float);
            /////////////////////////////////////////////////
                        /// \brief Sets the orientation of the bar.
            ///
            ///VERTICAL or HORIZONTAL are available.
            ///
            /// \param int : orientation.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setOrientation(int);
            /////////////////////////////////////////////////
                        /// \brief Sets the length of the bar.
            ///
            ///The size will depends of the orientation.
            ///
            /// \param float : length.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setLength(float);

            static const int HORIZONTAL = 0;
            static const int VERTICAL = 1;
        };
    }
}

#endif // DEF_WP_GUI_PROGRESSBAR_HPP


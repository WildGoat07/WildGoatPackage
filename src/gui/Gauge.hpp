#ifndef DEF_WP_GUI_GAUGE_HPP
#define DEF_WP_GUI_GAUGE_HPP
#include "BaseWidget.hpp"
#include "basicColors.hpp"
#include "Environnement.hpp"

namespace wp
{
    namespace gui
    {
        /////////////////////////////////////////////////
                /// \brief A gauge.
        ///\class Gauge
        /////////////////////////////////////////////////
        class Gauge : public BaseWidget
        {
            sf::VertexArray m_lines;
            sf::RectangleShape m_rectangle;
            sf::RectangleShape m_backLine;
            Resource* m_res;
            float m_perc;
            int m_orientation;
            float m_length;
            bool m_pressed = false;
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
            Gauge(Resource&);
            virtual sf::FloatRect getLocalBounds() const override;
            /////////////////////////////////////////////////
                        /// \brief Sets its percentage.
            ///
            /// \param float : the percentage.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setPerc(float);
            /////////////////////////////////////////////////
                        /// \brief Returns its percentage.
            ///
            /// \return float : percentage.
            ///
            /////////////////////////////////////////////////
            float getPerc() const;
            /////////////////////////////////////////////////
                        /// \brief Sets its orientation.
            ///
            ///VERTICAL or HORIZONTAL are available.
            ///
            /// \param int : orientation.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setOrientation(int);
            /////////////////////////////////////////////////
                        /// \brief Sets its length.
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

#endif // DEF_WP_GUI_GAUGE_HPP



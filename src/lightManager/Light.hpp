#ifndef DEF_WP_LIGHT_HPP
#define DEF_WP_LIGHT_HPP
#include "../Various.hpp"
#include "Wall.hpp"

namespace wp
{
    /////////////////////////////////////////////////
        /// \brief Includes the light module.
    ///
    ///Namespace that provide a light manager and light effects.
    ///
    /////////////////////////////////////////////////
    namespace light
    {
        class LightManager;

        /////////////////////////////////////////////////
                /// \brief A basic light.
        ///
        ///A light will light everything around it.
        ///\class PointLight
        /////////////////////////////////////////////////
        class PointLight
        {
        protected:
            friend LightManager;
            std::vector<shared_ptr<Wall> >* m_walls;
            sf::Vector2f m_position;
            float m_radius;
            sf::Color m_color;
            sf::VertexArray m_buff;
            uint16_t m_precision;
            PointLight();

        public:
            /////////////////////////////////////////////////
                        /// \brief Generates the light.
            ///
            /// \return void
            ///
            /////////////////////////////////////////////////
            virtual void generate();
            /////////////////////////////////////////////////
                        /// \brief Sets its position.
            ///
            /// \param sf::Vector2f : position
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setPosition(sf::Vector2f);
            /////////////////////////////////////////////////
                        /// \brief Sets its radius.
            ///
            /// \param float : radius
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setRadius(float);
            /////////////////////////////////////////////////
                        /// \brief Sets its color.
            ///
            /// \param sf::Color
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setColor(sf::Color);
            /////////////////////////////////////////////////
                        /// \brief Sets its precision.
            ///
            ///A higher precision will use more performance but will look better. For a static light, a high precision isn't needed while for a dynamic light a high precision could be needed.
            ///The precision is the number of vertex of the light. Low precision will be noticed especially close to walls.
            ///
            /// \param uint16_t : precision.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setPrecision(uint16_t);

            /////////////////////////////////////////////////
                        /// \brief Returns its position.
            ///
            /// \return sf::Vector2f : position
            ///
            /////////////////////////////////////////////////
            sf::Vector2f getPosition() const;
            /////////////////////////////////////////////////
                        /// \brief Returns its radius.
            ///
            /// \return float : radius.
            ///
            /////////////////////////////////////////////////
            float getRadius() const;
            /////////////////////////////////////////////////
                        /// \brief Returns its color.
            ///
            /// \return sf::Color : color.
            ///
            /////////////////////////////////////////////////
            sf::Color getColor() const;
            /////////////////////////////////////////////////
                        /// \brief Returns its precision.
            ///
            /// \return uint16_t : precision.
            ///
            /////////////////////////////////////////////////
            uint16_t getPrecision() const;
        };
    }
}

#endif // DEF_WP_LIGHT_HPP

#ifndef DEF_WP_LIGHT_MANAGER_HPP
#define DEF_WP_LIGHT_MANAGER_HPP
#include "Wall.hpp"
#include "Light.hpp"
#include "Spot.hpp"

namespace wp
{
    namespace light
    {
        /////////////////////////////////////////////////
                /// \brief The light manager.
        ///
        ///It manages the lights and walls and generate its texture from them.
        ///\class LightManager
        /////////////////////////////////////////////////
        class LightManager
        {
            std::vector<shared_ptr<PointLight> > m_lights;
            sf::Color m_ambientColor;
            sf::RenderTexture m_render;
            std::vector<shared_ptr<Wall> > m_walls;

        public:
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            /// \param sf::Vector2u : the resolution of the generated texture (typically the resolution of the window).
            ///
            /////////////////////////////////////////////////
            LightManager(sf::Vector2u);
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            ///You must specify the resolution of the generated texture (typically the resolution of the window).
            ///
            /// \param unsigned int : width of the resolution.
            /// \param unsigned int : height of the resolution.
            ///
            /////////////////////////////////////////////////
            LightManager(unsigned int, unsigned int);
            /////////////////////////////////////////////////
                        /// \brief Creates a new point light.
            ///
            /// \return shared_ptr<PointLight> : the new point light.
            ///
            /////////////////////////////////////////////////
            shared_ptr<PointLight> createPointLight();
            /////////////////////////////////////////////////
                        /// \brief Creates a new spot light.
            ///
            /// \return shared_ptr<SpotLight> : the new spot light.
            ///
            /////////////////////////////////////////////////
            shared_ptr<SpotLight> createSpotLight();
            /////////////////////////////////////////////////
                        /// \brief Adds a wall.
            ///
            /// \param shared_ptr<Wall> : the wall.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void AddWall(shared_ptr<Wall>);
            /////////////////////////////////////////////////
                        /// \brief Creates and add a wall.
            ///
            /// \param sf::Vector2f : point 1 of the wall.
            /// \param sf::Vector2f : point 2 of the wall.
            /// \return shared_ptr<Wall> : the wall.
            ///
            /////////////////////////////////////////////////
            shared_ptr<Wall> createWall(sf::Vector2f = sf::Vector2f(), sf::Vector2f = sf::Vector2f());
            /////////////////////////////////////////////////
                        /// \brief Generates the texture.
            ///
            /// \param sf::FloatRect : rectangle of the view to generate.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void generate(sf::FloatRect);
            /////////////////////////////////////////////////
                        /// \brief Sets the ambient color.
            ///
            ///The ambient color is the background color of the texture. A darker color means darker shadows.
            ///
            /// \param sf::Color : ambient color.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setAmbientColor(sf::Color);
            /////////////////////////////////////////////////
                        /// \brief Deletes a light.
            ///
            /// \param shared_ptr<PointLight> : light to delete.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void deleteLight(shared_ptr<PointLight>);
            /////////////////////////////////////////////////
                        /// \brief Deletes a wall.
            ///
            /// \param shared_ptr<Wall> : wall to delete.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void deleteWall(shared_ptr<Wall>);

            /////////////////////////////////////////////////
                        /// \brief Returns the generated texture.
            ///
            /// \return sf::Texture const& : generated texture.
            ///
            /////////////////////////////////////////////////
            sf::Texture const& getTexture() const;
            /////////////////////////////////////////////////
                        /// \brief Returns the ambient color.
            ///
            /// \return sf::Color : ambient color.
            ///
            /////////////////////////////////////////////////
            sf::Color getAmbientColor() const;
        };
    }
}

#endif // DEF_WP_LIGHT_MANAGER_HPP

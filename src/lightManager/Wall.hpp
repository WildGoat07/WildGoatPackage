#ifndef DEF_WP_WALL_HPP
#define DEF_WP_WALL_HPP
#include "../Various.hpp"

namespace wp
{
    namespace light
    {
        /////////////////////////////////////////////////
                /// \brief A basic wall.
        ///
        ///A wall will generate a shadow.
        ///
        ///\class Wall.
        /////////////////////////////////////////////////
        class Wall
        {
        public:
            sf::Vector2f point1;///< first point of the wall
            sf::Vector2f point2;///< second point of the wall
            /////////////////////////////////////////////////
                        /// \brief Default constructor.
            ///
            ///
            /////////////////////////////////////////////////
            Wall() {}
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            /// \param sf::Vector2f : first point
            /// \param sf::Vector2f : second point
            ///
            /////////////////////////////////////////////////
            Wall(sf::Vector2f p1, sf::Vector2f p2) :
                point1(p1),
                point2(p2)
            {

            }
        };
    }
}

#endif // DEF_WP_WALL_HPP


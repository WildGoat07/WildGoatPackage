#ifndef DEF_TILE_PATH_FINDER_HPP
#define DEF_TILE_PATH_FINDER_HPP
#include "Tile.hpp"
#include <queue>

namespace wp
{
    /////////////////////////////////////////////////
        /// \brief Path Finding namespace.
    ///
    ///Includes components of the pathfinding module.
    ///\namespace wp::pf
    ///
    /////////////////////////////////////////////////
    namespace pf
    {
        /////////////////////////////////////////////////
                /// \brief Find the shortest path in a tilemap.
        ///
        ///The used algorithm is the A*. The operated distance is the distance of Manhattan.
        ///
        ///\class TilePathFinder
        /////////////////////////////////////////////////
        class TilePathFinder
        {
            Tilemap* m_tilemap = nullptr;
            shared_ptr<Tile> m_start = shared_ptr<Tile>(nullptr);
            shared_ptr<Tile> m_end = shared_ptr<Tile>(nullptr);
        public:
            /////////////////////////////////////////////////
                        /// \brief Sets the starting tile.
            ///
            /// \param shared_ptr<Tile> : starting tile.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setStart(shared_ptr<Tile>);
            /////////////////////////////////////////////////
                        /// \brief Sets the ending or target tile.
            ///
            /// \param shared_ptr<Tile> : ending or target tile.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setEnd(shared_ptr<Tile>);
            /////////////////////////////////////////////////
                        /// \brief Sets the current tilemap.
            ///
            /// \param Tilemap* : pointer to the tilemap.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setTilemap(Tilemap*);
            /////////////////////////////////////////////////
                        /// \brief Returns the positions in the tilemap of the path.
            ///
            ///Each position is an index of the given tilemap. An empty std::vector is the result of an error, either there is not enough informations provided or there is no path.
            ///
            /// \return std::vector<sf::Vector2u>
            ///
            /////////////////////////////////////////////////
            std::vector<sf::Vector2u> findPath() const;
        };
    }
}

#endif // DEF_TILE_PATH_FINDER_HPP


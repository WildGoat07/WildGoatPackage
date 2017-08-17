#ifndef DEF_WP_TILE_HPP
#define DEF_WP_TILE_HPP
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../Various.hpp"

namespace wp
{
    namespace pf
    {
        class TilePathFinder;
        class Tilemap;
        /////////////////////////////////////////////////
                /// \brief A basic tile.
        ///
        ///To create a more complex tile (with your proper id or whatever you want), just inherit this class so it's compatible with the TilePathFinder.
        ///
        ///\class Tile
        /////////////////////////////////////////////////
        class Tile
        {
            float m_cost;
            sf::Vector2u index;
            std::vector<sf::Vector2u> m_path;
            float m_heuristic;
            struct leftSupRight
            {
                bool operator()(shared_ptr<Tile> left, shared_ptr<Tile> right) const
                {
                    return left->m_heuristic > right->m_heuristic;
                }
            };
            friend leftSupRight;
            friend TilePathFinder;
            friend Tilemap;
        public:
            bool filled;///< true if the tile is filled (e.g. you can't pass through). It is used for the path finding and to link (or not) the different tiles.
        };
        /////////////////////////////////////////////////
                /// \brief A basic tilemap
        ///
        ///A table of Tile.
        /////////////////////////////////////////////////
        class Tilemap
        {
            std::vector<shared_ptr<Tile> > m_table;
            sf::Vector2u m_size;
        public:
            /////////////////////////////////////////////////
                        /// \brief Returns the selected tile.
            ///
            /// \param sf::Vector2u : index of the tile.
            /// \return shared_ptr<Tile> : the tile.
            ///
            /////////////////////////////////////////////////
            shared_ptr<Tile> get(sf::Vector2u index) const
            {
                return m_table[index.x + m_size.x*index.y];
            }
            /////////////////////////////////////////////////
                        /// \brief Sets a tile.
            ///
            /// \param sf::Vector2u : index of the tile.
            /// \param shared_ptr<Tile> : the new tile.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void set(sf::Vector2u index, shared_ptr<Tile> tile)
            {
                tile->index = index;
                m_table[index.x + m_size.x*index.y] = tile;
            }
            /////////////////////////////////////////////////
                        /// \brief Creates the tilemap.
            ///
            /// \param sf::Vector2u : size of the tilemap.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void create(sf::Vector2u size)
            {
                m_table.clear();
                m_table.resize(size.x*size.y);
                m_size = size;
            }
            /////////////////////////////////////////////////
                        /// \brief Returns the size of the tilemap.
            ///
            /// \return sf::Vector2u : size.
            ///
            /////////////////////////////////////////////////
            sf::Vector2u size() const
            {
                return m_size;
            }
        };
    }
}

#endif // DEF_WP_TILE_HPP

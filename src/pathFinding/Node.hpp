#ifndef DEF_WP_NODE_HPP
#define DEF_WP_NODE_HPP
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace wp
{
    namespace pf
    {
        class PathFinder;

        /////////////////////////////////////////////////
                /// \brief A node for the path finding.
        ///
        ///A simple node that can be linked to other nodes.
        ///
        ///\class Node
        /////////////////////////////////////////////////
        class Node
        {
            friend PathFinder;
        protected:
            float m_cost;
            std::vector<Node*> m_path;
            struct leftSupRight
            {
                bool operator()(Node* left, Node* right) const
                {
                    return left->m_heuristic > right->m_heuristic;
                }
            };

        public:

            friend PathFinder;
            float m_heuristic;

            sf::Vector2f nodePosition;///< the real position of the node.
            std::vector<Node*> adjacent;///< all the nodes linked to it.
        };
    }
}

#endif // DEF_WP_NODE_HPP

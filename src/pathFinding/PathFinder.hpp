#ifndef DEF_PATH_FINDER_HPP
#define DEF_PATH_FINDER_HPP
#include "Node.hpp"
#include <queue>

namespace wp
{
    namespace pf
    {
        /////////////////////////////////////////////////
                /// \brief Find the shortest path between two nodes.
        ///
        ///The used algorithm is the A*. The operated distance is the euclidean distance.
        ///
        ///\class PathFinder
        /////////////////////////////////////////////////
        class PathFinder
        {
            Node* m_start = nullptr;
            Node* m_end = nullptr;
        public:
            /////////////////////////////////////////////////
                        /// \brief Sets the starting node.
            ///
            /// \param Node* : starting node.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setStart(Node*);
            /////////////////////////////////////////////////
                        /// \brief Sets the ending node.
            ///
            /// \param Node* : ending node.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setEnd(Node*);
            /////////////////////////////////////////////////
                        /// \brief Returns the shortest path.
            ///
            ///The table of nodes is the shortest path from the start to the end.
            ///
            /// \return std::vector<Node*> : path.
            ///
            /////////////////////////////////////////////////
            std::vector<Node*> findPath() const;
        };
    }
}

#endif // DEF_PATH_FINDER_HPP

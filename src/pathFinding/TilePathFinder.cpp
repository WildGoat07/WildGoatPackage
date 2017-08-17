#include "TilePathFinder.hpp"
#include "../Various.hpp"
#include <iostream>

using namespace wp::pf;

void TilePathFinder::setEnd(shared_ptr<Tile> node)
{
    m_end = node;
}
void TilePathFinder::setStart(shared_ptr<Tile> node)
{
    m_start = node;
}
void TilePathFinder::setTilemap(Tilemap* nodes)
{
    m_tilemap = nodes;
}
std::vector<sf::Vector2u> TilePathFinder::findPath() const
{
    if (m_start.get() == nullptr || m_end.get() == nullptr || m_tilemap == nullptr)
    {
        std::cerr << "error : too few informations provided.\n";
        return std::vector<sf::Vector2u>();
    }
    std::priority_queue<shared_ptr<Tile> , std::vector<shared_ptr<Tile> >, Tile::leftSupRight> openList;
    std::vector<shared_ptr<Tile> > closedList;
    std::vector<shared_ptr<Tile> > openedList;

    m_start->m_cost = 0;
    openList.push(m_start);
    while (!openList.empty())
    {
        shared_ptr<Tile> currNode = openList.top();
        openList.pop();
        if (currNode->index == m_end->index)
        {
            currNode->m_path.push_back(m_end->index);
            return currNode->m_path;
        }

        if (currNode->index.x >= 1)
        {
            shared_ptr<Tile> adjacent(m_tilemap->get(sf::Vector2u(currNode->index.x-1, currNode->index.y)));
            if (!adjacent->filled)
            {
                bool exists = false;
                for (std::vector<shared_ptr<Tile> >::iterator it = closedList.begin();it<closedList.end();it++)
                {
                    if (*it == adjacent)
                    {
                        exists = true;
                        it = closedList.end();
                    }
                }
                if (!exists)
                {
                    for (std::vector<shared_ptr<Tile> >::iterator it = openedList.begin();it<openedList.end();it++)
                    {
                        if (*it == adjacent)
                        {
                            exists = true;
                            it = openedList.end();
                        }
                    }
                }
                if (!exists)
                {
                    adjacent->m_cost = currNode->m_cost + 1;
                    adjacent->m_path = currNode->m_path;
                    adjacent->m_path.push_back(currNode->index);
                    adjacent->m_heuristic = adjacent->m_cost;
                    openedList.push_back(adjacent);
                    openList.push(adjacent);
                }
            }
        }
        if (currNode->index.y >= 1)
        {
            shared_ptr<Tile> adjacent(m_tilemap->get(sf::Vector2u(currNode->index.x, currNode->index.y-1)));
            if (!adjacent->filled)
            {
                bool exists = false;
                for (std::vector<shared_ptr<Tile> >::iterator it = closedList.begin();it<closedList.end();it++)
                {
                    if (*it == adjacent)
                    {
                        exists = true;
                        it = closedList.end();
                    }
                }
                if (!exists)
                {
                    for (std::vector<shared_ptr<Tile> >::iterator it = openedList.begin();it<openedList.end();it++)
                    {
                        if (*it == adjacent)
                        {
                            exists = true;
                            it = openedList.end();
                        }
                    }
                }
                if (!exists)
                {
                    adjacent->m_cost = currNode->m_cost + 1;
                    adjacent->m_path = currNode->m_path;
                    adjacent->m_path.push_back(currNode->index);
                    adjacent->m_heuristic = adjacent->m_cost;
                    openedList.push_back(adjacent);
                    openList.push(adjacent);
                }
            }
        }
        if (currNode->index.x < m_tilemap->size().x-1)
        {
            shared_ptr<Tile> adjacent(m_tilemap->get(sf::Vector2u(currNode->index.x+1, currNode->index.y)));
            if (!adjacent->filled)
            {
                bool exists = false;
                for (std::vector<shared_ptr<Tile> >::iterator it = closedList.begin();it<closedList.end();it++)
                {
                    if (*it == adjacent)
                    {
                        exists = true;
                        it = closedList.end();
                    }
                }
                if (!exists)
                {
                    for (std::vector<shared_ptr<Tile> >::iterator it = openedList.begin();it<openedList.end();it++)
                    {
                        if (*it == adjacent)
                        {
                            exists = true;
                            it = openedList.end();
                        }
                    }
                }
                if (!exists)
                {
                    adjacent->m_cost = currNode->m_cost + 1;
                    adjacent->m_path = currNode->m_path;
                    adjacent->m_path.push_back(currNode->index);
                    adjacent->m_heuristic = adjacent->m_cost;
                    openedList.push_back(adjacent);
                    openList.push(adjacent);
                }
            }
        }
        if (currNode->index.y < m_tilemap->size().y-1)
        {
            shared_ptr<Tile> adjacent(m_tilemap->get(sf::Vector2u(currNode->index.x, currNode->index.y+1)));
            if (!adjacent->filled)
            {
                bool exists = false;
                for (std::vector<shared_ptr<Tile> >::iterator it = closedList.begin();it<closedList.end();it++)
                {
                    if (*it == adjacent)
                    {
                        exists = true;
                        it = closedList.end();
                    }
                }
                if (!exists)
                {
                    for (std::vector<shared_ptr<Tile> >::iterator it = openedList.begin();it<openedList.end();it++)
                    {
                        if (*it == adjacent)
                        {
                            exists = true;
                            it = openedList.end();
                        }
                    }
                }
                if (!exists)
                {
                    adjacent->m_cost = currNode->m_cost + 1;
                    adjacent->m_path = currNode->m_path;
                    adjacent->m_path.push_back(currNode->index);
                    adjacent->m_heuristic = adjacent->m_cost;
                    openedList.push_back(adjacent);
                    openList.push(adjacent);
                }
            }
        }
        closedList.push_back(currNode);
    }
    return std::vector<sf::Vector2u>();
}


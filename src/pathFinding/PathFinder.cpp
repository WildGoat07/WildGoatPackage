#include "PathFinder.hpp"
#include "../Various.hpp"
#include <iostream>

using namespace wp::pf;

void PathFinder::setEnd(Node* node)
{
    m_end = node;
}
void PathFinder::setStart(Node* node)
{
    m_start = node;
}
std::vector<Node*> PathFinder::findPath() const
{
    if (m_start == nullptr || m_end == nullptr)
    {
        std::cerr << "error : too few informations provided.\n";
        return std::vector<Node*>();
    }
    std::priority_queue<Node*, std::vector<Node*>, Node::leftSupRight> openList;
    std::vector<Node*> closedList;
    std::vector<Node*> openedList;

    m_start->m_cost = 0;
    openList.push(m_start);
    while (!openList.empty())
    {
        Node* currNode = openList.top();
        openList.pop();
        if (currNode->nodePosition == m_end->nodePosition)
        {
            std::vector<Node*> path;
            path.push_back(m_end);
            bool fin = false;
            while (!fin)
            {
                Node* closest = nullptr;
                for (int i = 0;i<currNode->adjacent.size();i++)
                {
                    if (closest == nullptr)
                        closest = currNode->adjacent[i];
                    else if (closest->m_cost > currNode->adjacent[i]->m_cost)
                    {
                        if (currNode->adjacent[i]->m_cost > 0 || currNode->adjacent[i]->nodePosition == m_start->nodePosition)
                            closest = currNode->adjacent[i];
                    }
                }
                if (closest->nodePosition == m_start->nodePosition)
                    fin = true;
                path.push_back(closest);
                currNode = closest;
            }
            return path;
        }
        for (int i = 0;i<currNode->adjacent.size();i++)
        {
            bool exists = false;
            for (std::vector<Node*>::iterator it = closedList.begin();it<closedList.end();it++)
            {
                if (*it == currNode->adjacent[i] && (*it)->m_cost + wp::Various::length((*it)->nodePosition - currNode->adjacent[i]->nodePosition) <= currNode->adjacent[i]->m_cost)
                {
                    exists = true;
                    it = closedList.end();
                }
            }
            if (!exists)
            {
                for (std::vector<Node*>::iterator it = openedList.begin();it<openedList.end();it++)
                {
                    if (*it == currNode->adjacent[i] && (*it)->m_cost + wp::Various::length((*it)->nodePosition - currNode->adjacent[i]->nodePosition) <= currNode->adjacent[i]->m_cost)
                    {
                        exists = true;
                        it = openedList.end();
                    }
                }
            }
            if (!exists)
            {
                currNode->adjacent[i]->m_cost = currNode->m_cost + wp::Various::length(currNode->nodePosition - currNode->adjacent[i]->nodePosition);
                currNode->adjacent[i]->m_path = currNode->m_path;
                currNode->adjacent[i]->m_path.push_back(currNode);
                currNode->adjacent[i]->m_heuristic = currNode->adjacent[i]->m_cost;
                openedList.push_back(currNode->adjacent[i]);
                openList.push(currNode->adjacent[i]);
            }
        }
        closedList.push_back(currNode);
    }
    return std::vector<Node*>();
}

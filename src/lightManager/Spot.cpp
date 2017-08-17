#include "Spot.hpp"
#include <cmath>

using namespace wp::light;

SpotLight::SpotLight() :
    PointLight()
{

}
void SpotLight::generate()
{
    m_buff.clear();
    m_buff.append(sf::Vertex(m_position, m_color));
    std::vector<shared_ptr<Wall> > testRequired;
    for (int i = 0;i<m_walls->size();i++)
    {
        bool add = false;

        if (wp::Various::length(m_walls->at(i)->point1 - m_position) < m_radius ||
            wp::Various::length(m_walls->at(i)->point2 - m_position) < m_radius)
            add = true;

        if (!add)
        {
            for (float j = 0;j<wp::Various::length(m_walls->at(i)->point1 - m_walls->at(i)->point2);j+=m_radius/5)
            {
                if (wp::Various::length(m_walls->at(i)->point1 + j*wp::Various::normalize(m_walls->at(i)->point2 - m_walls->at(i)->point1) - m_position) < m_radius)
                    add = true;
            }
        }

        if (add)
        {
            testRequired.push_back(m_walls->at(i));
        }
    }
    for (uint16_t i = 0;i<=m_precision;i++)
    {
        float angle = m_dirAngle - m_openAngle/2 + (float)i/m_precision*m_openAngle;
        sf::Vector2f tmp = m_position + sf::Vector2f(m_radius * cos(angle*PI/180), m_radius * sin(angle*PI/180));
        sf::Color col;
        for (int j = 0;j<testRequired.size();j++)
        {
            if (wp::Various::segmentCollision(m_position, tmp, testRequired[j]->point1, testRequired[j]->point2))
            {
                sf::Vector2f dir1 = wp::Various::normalize(tmp - m_position);
                sf::Vector2f dir2 = wp::Various::normalize(testRequired[j]->point2 - testRequired[j]->point1);
                sf::Vector2f pos1 = m_position;
                sf::Vector2f pos2 = testRequired[j]->point1;

                float l = -(-dir1.x*m_position.y+dir1.x*pos2.y+dir1.y*pos1.x-dir1.y*pos2.x)/(dir1.x*dir2.y-dir1.y*dir2.x);
                sf::Vector2f tmp2 = pos2 + l*dir2;

                if (wp::Various::length(tmp - m_position) > wp::Various::length(tmp2 - m_position))
                {
                    tmp = tmp2;
                }
            }
        }
        col.r = wp::Various::linearInter(0, m_color.r, (m_radius - wp::Various::length(tmp - m_position))/m_radius);
        col.g = wp::Various::linearInter(0, m_color.g, (m_radius - wp::Various::length(tmp - m_position))/m_radius);
        col.b = wp::Various::linearInter(0, m_color.b, (m_radius - wp::Various::length(tmp - m_position))/m_radius);
        m_buff.append(sf::Vertex(tmp, col));
    }
}
void SpotLight::setDirection(float dir)
{
    m_dirAngle = dir;
}
void SpotLight::setAngle(float angle)
{
    m_openAngle = angle;
}
float SpotLight::getDirection() const
{
    return m_dirAngle;
}
float SpotLight::getAngle() const
{
    return m_openAngle;
}

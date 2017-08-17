#include "LightManager.hpp"

using namespace wp::light;

LightManager::LightManager(sf::Vector2u size):
    LightManager(size.x, size.y)
{

}
LightManager::LightManager(unsigned int x, unsigned int y)
{
    m_render.create(x, y);
}
shared_ptr<PointLight> LightManager::createPointLight()
{
    shared_ptr<PointLight> tmp(new PointLight());
    m_lights.push_back(tmp);
    return tmp;
}
shared_ptr<SpotLight> LightManager::createSpotLight()
{
    shared_ptr<SpotLight> tmp(new SpotLight());
    m_lights.push_back(tmp);
    return tmp;
}
void LightManager::AddWall(shared_ptr<Wall> wall)
{
    m_walls.push_back(wall);
}
shared_ptr<Wall> LightManager::createWall(sf::Vector2f p1, sf::Vector2f p2)
{
    shared_ptr<Wall> tmp(new Wall(p1, p2));
    m_walls.push_back(tmp);
    return tmp;
}
void LightManager::deleteLight(shared_ptr<PointLight> light)
{
    for (std::vector<shared_ptr<PointLight> >::iterator it = m_lights.begin();it!=m_lights.end();it++)
    {
        if (light == *it)
            m_lights.erase(it);
    }
}
void LightManager::deleteWall(shared_ptr<Wall> wall)
{
    for (std::vector<shared_ptr<Wall> >::iterator it = m_walls.begin();it!=m_walls.end();it++)
    {
        if (wall == *it)
            m_walls.erase(it);
    }
}
void LightManager::setAmbientColor(sf::Color c)
{
    m_ambientColor = c;
}
void LightManager::generate(sf::FloatRect rect)
{
    std::vector<shared_ptr<PointLight> > drawRequired;
    for (int i = 0;i<m_lights.size();i++)
    {
        shared_ptr<PointLight> curr = m_lights[i];
        if (rect.contains(curr->getPosition() + sf::Vector2f(curr->getRadius(), curr->getRadius())) ||
            rect.contains(curr->getPosition() + sf::Vector2f(-curr->getRadius(), curr->getRadius())) ||
            rect.contains(curr->getPosition() + sf::Vector2f(-curr->getRadius(), -curr->getRadius())) ||
            rect.contains(curr->getPosition() + sf::Vector2f(curr->getRadius(), -curr->getRadius())))
        {
            drawRequired.push_back(curr);
        }
        else
        {
            sf::FloatRect rect2(curr->getPosition().x - curr->getRadius(), curr->getPosition().y - curr->getRadius(),
                                curr->getRadius()*2, curr->getRadius()*2);
            if (rect2.contains(sf::Vector2f(rect.left, rect.top)) ||
                rect2.contains(sf::Vector2f(rect.left + rect.width, rect.top)) ||
                rect2.contains(sf::Vector2f(rect.left + rect.width, rect.top + rect.height)) ||
                rect2.contains(sf::Vector2f(rect.left, rect.top + rect.height)))
            {
                drawRequired.push_back(curr);
            }
        }
    }
    m_render.clear(m_ambientColor);
        sf::RenderStates states;
        states.transform.translate(-rect.left, -rect.top);
        states.blendMode = sf::BlendAdd;
    for (int i = 0;i<drawRequired.size();i++)
    {
        drawRequired[i]->m_walls = &m_walls;
        drawRequired[i]->generate();
        m_render.draw(drawRequired[i]->m_buff, states);
    }
    m_render.display();
}
sf::Color LightManager::getAmbientColor() const
{
    return m_ambientColor;
}
sf::Texture const& LightManager::getTexture() const
{
    return m_render.getTexture();
}

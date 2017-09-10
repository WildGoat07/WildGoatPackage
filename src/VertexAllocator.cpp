#include "VertexAllocator.hpp"

using namespace wp;

void VertexAllocator::VertexSquare::setSquare(sf::FloatRect box, sf::FloatRect tex)
{
    array[0]->position.x = box.left;
    array[0]->position.y = box.top;
    array[1]->position.x = box.left + box.width;
    array[1]->position.y = box.top;
    array[2]->position.x = box.left + box.width;
    array[2]->position.y = box.top + box.height;
    array[3]->position.x = box.left;
    array[3]->position.y = box.top + box.height;

    if (tex != sf::FloatRect())
    {
        array[0]->texCoords.x = tex.left;
        array[0]->texCoords.y = tex.top;
        array[1]->texCoords.x = tex.left + tex.width;
        array[1]->texCoords.y = tex.top;
        array[2]->texCoords.x = tex.left + tex.width;
        array[2]->texCoords.y = tex.top + tex.height;
        array[3]->texCoords.x = tex.left;
        array[3]->texCoords.y = tex.top + tex.height;
    }
}
VertexAllocator::VertexAllocator()
{
    m_size = 0;
    m_array.setPrimitiveType(sf::Quads);
    m_texture = nullptr;
}
VertexAllocator::VertexAllocator(unsigned int s) :
    VertexAllocator()
{
    setSize(s);
}
VertexAllocator::VertexSquare VertexAllocator::operator[](unsigned int index)
{
    VertexAllocator::VertexSquare res;
    for (unsigned int i = 0;i<4;i++)
        res.array[i] = &(m_array[index*4+i]);
    return res;
}
void VertexAllocator::VertexSquare::update()
{
    sf::Transform tr = getTransform();
    array[0]->position = tr.transformPoint(array[0]->position);
    array[1]->position = tr.transformPoint(array[1]->position);
    array[2]->position = tr.transformPoint(array[2]->position);
    array[3]->position = tr.transformPoint(array[3]->position);
}
VertexAllocator::VertexSquare VertexAllocator::allocateNewVertex(sf::FloatRect box, sf::FloatRect tex)
{
    m_array.append(sf::Vertex());
    m_array.append(sf::Vertex());
    m_array.append(sf::Vertex());
    m_array.append(sf::Vertex());
    m_size++;
    VertexAllocator::VertexSquare tmp = operator[](size()-1);
    tmp.array[0]->position.x = box.left;
    tmp.array[0]->position.y = box.top;
    tmp.array[0]->texCoords.x = tex.left;
    tmp.array[0]->texCoords.y = tex.top;
    tmp.array[1]->position.x = box.left + box.width;
    tmp.array[1]->position.y = box.top;
    tmp.array[1]->texCoords.x = tex.left + tex.width;
    tmp.array[1]->texCoords.y = tex.top;
    tmp.array[2]->position.x = box.left + box.width;
    tmp.array[2]->position.y = box.top + box.height;
    tmp.array[2]->texCoords.x = tex.left + tex.width;
    tmp.array[2]->texCoords.y = tex.top + tex.height;
    tmp.array[3]->position.x = box.left;
    tmp.array[3]->position.y = box.top + box.height;
    tmp.array[3]->texCoords.x = tex.left;
    tmp.array[3]->texCoords.y = tex.top + tex.height;
    return tmp;
}

#include "Object.hpp"

using namespace wp::JSON;

Object::Object() :
    Value()
{
    m_type = OBJECT_TYPE;
}


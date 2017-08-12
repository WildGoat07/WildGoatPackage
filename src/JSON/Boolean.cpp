#include "Boolean.hpp"

using namespace wp::JSON;

Boolean::Boolean() :
    Value()
{
    m_type = BOOLEAN_TYPE;
    value = false;
}

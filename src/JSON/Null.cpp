#include "Null.hpp"

using namespace wp::JSON;

Null::Null() :
    Value(),
    value(NULL)
{
    m_type = NULL_TYPE;
}


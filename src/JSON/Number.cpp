#include "Number.hpp"

using namespace wp::JSON;

Number::Number() :
    Value()
{
    m_type = NUMBER_TYPE;
    value = 0;
}


#include "String.hpp"

using namespace wp::JSON;

String::String() :
    Value()
{
    m_type = STRING_TYPE;
    value = "";
}


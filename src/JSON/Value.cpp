#include "Value.hpp"

using namespace wp::JSON;

Value::Value()
{
    m_type = UNKNOWN_TYPE;
}
uint8_t Value::getType() const
{
    return m_type;
}

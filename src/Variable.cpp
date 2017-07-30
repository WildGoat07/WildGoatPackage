#include "Variable.hpp"

using namespace wp;

template<typename T>
Variable<T>::Variable( ParamList* l)
{
    m_list = l;
    m_constant = true;
}

template<typename T>
Variable<T>::Variable(T const& val, ParamList* l, bool cons)
{
    if (!cons)
        m_reference = val;
    else
    {
        m_value = val;
        m_reference = nullptr;
    }
    m_list = l;
}
template<typename T>
Variable<T>::Variable(std::string const& ref, ParamList* l)
{
    m_reference = ref;
    m_list = l;
}

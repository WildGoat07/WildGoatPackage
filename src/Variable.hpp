#ifndef DEF_VARIABLE_HPP
#define DEF_VARIABLE_HPP
#include <string>
#include <map>

namespace wp
{
    template<typename T>
    /** \brief Creates a dynamic variable.
    *
    *   The variable can be constant, giving it a specified value, or can be a reference to another constant in a list of parameters. The reference is the ID of the constant.
    *
    *   \class Variable
     */
    class Variable
    {
    public:
        typedef std::map<std::string, T> ParamList;/**< list of parameters for reference variables. */
    protected:
        ParamList* m_list;
        bool m_constant;
        std::string m_reference;
        T m_value;
    public:
        /** \brief Constructor.
         *
         * \param ParamList* : list of parameters source.
         *
         */
        Variable()
        {
            m_list = nullptr;
            m_constant = true;
        }

        Variable(ParamList* l)
        {
            m_list = l;
            m_constant = true;
        }
        /** \brief Constructor.
        *
        *   If using a std::string as value type, set to true the bool to set the value as a constant and not as reference.
         *
         * \param T const& : value of the variable.
         * \param ParamList* : list of parameters source.
         * \param bool : true for constant.
         *
         */
        Variable(T const& val, ParamList* l, bool cons = true)
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
        /** \brief Constructor.
         *
         * \param std::string const& : reference of the variable.
         * \param ParamList* : list of parameters source.
         *
         */
        Variable(std::string const& ref, ParamList* l)
        {
            m_reference = ref;
            m_list = l;
        }
        /** \brief Sets the variable a constant value.
         *
         * \param T const& : value.
         * \return void
         *
         */
        void setValue(T const&);
        /** \brief Sets the variable a reference.
         *
         * \param std::string const& : reference.
         * \return void
         *
         */
        void setReference(std::string const&);
        /** \brief Returns the reference.
         *
         * \return std::string const& : reference.
         *
         */
        std::string const& getReference() const;
        /** \brief Returns the value of the variable.
         *
         * \return T const& : value.
         *
         */
        T const& getValue() const;
        /** \brief Returns the list of parameters.
         *
         * \return ParamList const* : list of parameters.
         *
         */
        ParamList const* getParameters() const;
        /** \brief Sets the list of parameters.
         *
         * \param ParamList* : list of parameters source.
         * \return void
         *
         */
        void setParameters(ParamList*);
    };

    template<typename T>
    inline void Variable<T>::setValue(T const& val)
    {
        m_value = val;
        m_constant = true;
    }
    template<typename T>
    inline void Variable<T>::setReference(std::string const& ref)
    {
        m_reference = ref;
        m_constant = false;
    }
    template<typename T>
    inline std::string const& Variable<T>::getReference() const
    {
        return m_reference;
    }
    template<typename T>
    inline T const& Variable<T>::getValue() const
    {
        if (m_constant)
            return m_value;
        else
            return m_list->at(m_reference);
    }
    template<typename T>
    inline typename Variable<T>::ParamList const* Variable<T>::getParameters() const
    {
        return m_list;
    }
    template<typename T>
    inline void Variable<T>::setParameters(Variable<T>::ParamList* param)
    {
        m_list = param;
    }
}
#endif // DEF_VARIABLE_HPP

#ifndef DEF_WP_VALUE_HPP
#define DEF_WP_VALUE_HPP
#include "../Various.hpp"
#include <string>

namespace wp
{
    namespace JSON
    {
        /** \brief A basic value.
        *
        *   The value can be of type :
        *   - object
        *   - array
        *   - string
        *   - number
        *   - boolean
        *   - null
        *
        *\see wp::JSON::Object
        *\see wp::JSON::Array
        *\see wp::JSON::String
        *\see wp::JSON::Number
        *\see wp::JSON::Boolean
        *\see wp::JSON::Null
        *   \class Value
         */
        class Value
        {
        protected:
            uint8_t m_type;
            Value();
        public:
            static const uint8_t UNKNOWN_TYPE = 0;/**< unknown type. An error occurrenced */
            static const uint8_t STRING_TYPE = 1;/**< string type */
            static const uint8_t OBJECT_TYPE = 2;/**< object type */
            static const uint8_t ARRAY_TYPE = 3;/**< array type */
            static const uint8_t BOOLEAN_TYPE = 4;/**< boolean type */
            static const uint8_t NUMBER_TYPE = 5;/**< number type */
            static const uint8_t NULL_TYPE = 6;/**< null type */
            /** \brief Returns its type.
             *
             * \return uint8_t : type.
             *
             */
            uint8_t getType() const;
            /** \brief Returns a pointer of the given type.
            *
            *   The given type must correspond to the one returned by getType().
             *
             * \return T* : requested pointer type.
             *
             */
            template<typename T> T* interpret() const
            {
                return (T*)this;
            }

        };
    }
}

#endif // DEF_WP_VALUE_HPP

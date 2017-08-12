#ifndef DEF_WP_NULL_HPP
#define DEF_WP_NULL_HPP
#include "Value.hpp"

namespace wp
{
    namespace JSON
    {
        /** \brief A null value.
        *
        *\see wp::JSON::Value
        *   \class wp::JSON::Null
         */
        class Null : public Value
        {
        public:
            typedef uint8_t valueType;///< internal value type
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            ///
            /////////////////////////////////////////////////
            Null();
            const valueType value;/**< the stored null value */
        };
    }
}

#endif // DEF_WP_NULL_HPP





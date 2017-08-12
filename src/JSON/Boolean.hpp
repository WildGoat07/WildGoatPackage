#ifndef DEF_WP_BOOLEAN_HPP
#define DEF_WP_BOOLEAN_HPP
#include "Value.hpp"

namespace wp
{
    namespace JSON
    {
        /** \brief A boolean value.
        *
        *\see wp::JSON::Value
        *   \class wp::JSON::Boolean
         */
        class Boolean : public Value
        {
        public:
            typedef bool valueType;///< internal value type
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            ///
            /////////////////////////////////////////////////
            Boolean();
            valueType value;/**< the stored number */
        };
    }
}

#endif // DEF_WP_BOOLEAN_HPP




#ifndef DEF_WP_NUMBER_HPP
#define DEF_WP_NUMBER_HPP
#include "Value.hpp"

namespace wp
{
    namespace JSON
    {
        /** \brief A number value.
        *
        *\see wp::JSON::Value
        *   \class wp::JSON::Number
         */
        class Number : public Value
        {
        public:
            typedef long double valueType;///< internal value type
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            ///
            /////////////////////////////////////////////////
            Number();
            valueType value;/**< the stored number */
        };
    }
}

#endif // DEF_WP_NUMBER_HPP



#ifndef DEF_WP_STRING_HPP
#define DEF_WP_STRING_HPP
#include <string>
#include "Value.hpp"

namespace wp
{
    namespace JSON
    {
        /** \brief A string value.
        *
        *\see wp::JSON::Value
        *   \class wp::JSON::String
         */
        class String : public Value
        {
        public:
            typedef std::string valueType;///< internal value type
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            ///
            /////////////////////////////////////////////////
            String();
            valueType value;/**< the stored string */
        };
    }
}

#endif // DEF_WP_STRING_HPP


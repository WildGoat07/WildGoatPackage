#ifndef DEF_WP_OBJECT_HPP
#define DEF_WP_OBJECT_HPP
#include <string>
#include "Value.hpp"

namespace wp
{
    namespace JSON
    {
        /** \brief An object value.
        *
        *\see wp::JSON::Value
        *   \class wp::JSON::Object
         */
        class Object : public Value
        {
        public:
            typedef std::map<std::string, shared_ptr<Value> > valueType;///< internal value type
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            ///
            /////////////////////////////////////////////////
            Object();
            valueType values;/**< the stored values */
        };
    }
}

#endif // DEF_WP_OBJECT_HPP





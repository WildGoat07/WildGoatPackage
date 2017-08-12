#ifndef DEF_WP_ARRAY_HPP
#define DEF_WP_ARRAY_HPP
#include <list>
#include "Value.hpp"

namespace wp
{
    namespace JSON
    {
        /** \brief An array value.
        *
        *\see wp::JSON::Value
        *   \class wp::JSON::Array
         */
        class Array : public Value
        {
        public:
            typedef std::list<shared_ptr<Value> > valueType;///< internal value type
            /////////////////////////////////////////////////
                        /// \brief Constructor.
            ///
            ///
            /////////////////////////////////////////////////
            Array();
            valueType values;/**< the stored array */
        };
    }
}

#endif // DEF_WP_ARRAY_HPP





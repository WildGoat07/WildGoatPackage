#ifndef DEF_WP_JSON_HPP
#define DEF_WP_JSON_HPP
#include <string>
#include "Value.hpp"
#include "String.hpp"
#include "Boolean.hpp"
#include "Null.hpp"
#include "Number.hpp"
#include "Object.hpp"
#include "Array.hpp"
#include "../Various.hpp"

namespace wp
{

    /** \brief Includes %JSON module.
    *
    *Includes every %JSON-related classes.
    *
    *\see wp::JSON::JSONParser
    *\see wp::JSON::Value
    *\see wp::JSON::String
    *\see wp::JSON::Object
    *\see wp::JSON::Array
    *\see wp::JSON::Boolean
    *\see wp::JSON::Number
    *\see wp::JSON::Null
     *
     *\namespace wp::JSON
     */
    namespace JSON
    {
        /** \brief The %JSON base.
        *
        *This class is used to load a %JSON encoded string and extract its data, modify it, or delete it.
        *
        *\class JSONParser
        *\see [JSON encoding](http://www.json.org)
         */
        class JSONParser
        {
            bool pushCurs(std::string const&, size_t&) const;
            shared_ptr<Value> m_content = nullptr;
            mutable std::string m_buff;
            std::string getValueString(Value*) const;
            shared_ptr<Value> getValueFromString(std::string const&, size_t&) const;
        public:
            /** \brief Parses the %JSON.
             *
             * \param const& std::string : %JSON.
             * \return void
             *
             */
            void parseJSON(std::string const&);
            /////////////////////////////////////////////////
                        /// \brief Sets the value of the %JSON string
            ///
            /// \param shared_ptr<Value> : value.
            /// \return void
            ///
            /////////////////////////////////////////////////
            void setContent(shared_ptr<Value>);
            /////////////////////////////////////////////////
                        /// \brief Returns the value of the %JSON string
            ///
            /// \return shared_ptr<Value> : value.
            ///
            /////////////////////////////////////////////////
            shared_ptr<Value> getValue() const;
            /////////////////////////////////////////////////
                        /// \brief Returns the %JSON-formatted string.
            ///
            /// \return std::string const& %JSON string
            ///
            /////////////////////////////////////////////////
            std::string const& getJSONString() const;
        };
    }
}



#endif // DEF_WP_JSON_HPP

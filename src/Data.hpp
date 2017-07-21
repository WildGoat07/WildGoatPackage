#ifndef DEF_DATA_HPP
#define DEF_DATA_HPP
#include <map>
#include <memory>
#include "Various.hpp"

namespace wp
{
    /** \brief Storage class.
    *
    *   Stores any given number or string to save and load them.
    *
    *   \class Data
     */
    class Data
    {
        public:
            /** \brief Handles numeric and string value
            *
            *   \class Value
             */
            class Value : public sf::NonCopyable
            {
                friend Data;
            private:
                Data* m_parent;
                std::string m_value;
            public:
                /** \brief Stores an integer.
                 *
                 * \param long long : integer to store.
                 * \return void
                 *
                 */
                void setInt(long long);
                /** \brief Stores a double.
                 *
                 * \param long double : double to store.
                 * \return void
                 *
                 */
                void setDouble(long double);
                /** \brief Stores a string.
                 *
                 * \param std::string const& : string to store.
                 * \return void
                 *
                 */
                void setString(std::string const&);
                /** \brief Returns its value.
                *
                *   The value is numeric.
                 *
                 * \return long double : numeric value.
                 *
                 */
                long double getValue() const;
                /** \brief Returns its value.
                *
                *   The value is a string.
                 *
                 * \return std::string const& : string value.
                 *
                 */
                std::string const& getString() const;
                /** \brief Constructor.
                *
                *   Constructs by giving an integer value.
                 *
                 * \param long long : integer.
                 *
                 */
                Value(long long = 0);
                /** \brief Constructor.
                *
                *   Constructs by giving a double.
                 *
                 * \param long double : double.
                 *
                 */
                Value(long double);
                /** \brief Constructor.
                *
                *   Constructs by giving a string.
                 *
                 * \param std::string const& : string.
                 *
                 */
                Value(std::string const&);
            };
        friend Value;
    private:
        mutable bool m_requestUpdate = false;
        mutable std::string m_render;
        mutable std::map<std::string, std::shared_ptr<Value> > m_data;
    public:
        typedef std::map<std::string, std::shared_ptr<Value> >::iterator iterator;/**< iterator */
        typedef std::map<std::string, std::shared_ptr<Value> >::const_iterator const_iterator;/**< constant iterator */
        typedef std::map<std::string, std::shared_ptr<Value> >::reverse_iterator reverse_iterator;/**< reverse iterator */
        typedef std::map<std::string, std::shared_ptr<Value> >::const_reverse_iterator const_reverse_iterator;/**< constant reverse iterator */
        /** \brief Returns its value.
         *
         * \param std::string const& : ID of the value.
         * \return Value& : value.
         *
         */
        std::shared_ptr<Value> operator[](std::string const&);
        /** \brief Returns its value.
        *
        *   Constant version of operator[]().
         *
         * \param std::string const& : ID of the value.
         * \return const Value& : value.
         *
         */
        std::shared_ptr<const Value> operator[](std::string const&) const;
        /** \brief Returns its value.
         *
         * \param std::string const& : ID of the value.
         * \return Value& : value.
         *
         */
        std::shared_ptr<Value> get(std::string const&);
        /** \brief Returns its value.
        *
        *   Constant version of get().
         *
         * \param std::string const& : ID of the value.
         * \return const Value& : value.
         *
         */
        std::shared_ptr<const Value> get(std::string const&) const;
        /** \brief beginning iterator.
        *
        *   Constant version of begin().
         *
         * \return const_iterator : iterator.
         *
         */
        const_iterator begin() const;
        /** \brief beginning reverse iterator.
        *
        *   Constant version of rbegin().
         *
         * \return const_reverse_iterator : iterator.
         *
         */
        const_reverse_iterator rbegin() const;
        /** \brief ending iterator.
        *
        *   Constant version.
         *
         * \return const_iterator : iterator.
         *
         */
        const_iterator end() const;
        /** \brief reverse ending iterator.
        *
        *   Constant version.
         *
         * \return const_reverse_iterator : iterator.
         *
         */
        const_reverse_iterator rend() const;
        /** \brief beginning iterator.
         *
         * \return iterator : iterator.
         *
         */
        iterator begin();
        /** \brief beginning reverse iterator.
         *
         * \return reverse_iterator : iterator.
         *
         */
        reverse_iterator rbegin();
        /** \brief ending iterator.
         *
         * \return iterator : iterator.
         *
         */
        iterator end();
        /** \brief ending reverse iterator.
         *
         * \return reverse_iterator : iterator.
         *
         */
        reverse_iterator rend();
        /** \brief Clears the data.
         *
         * \return void
         *
         */
        void clear();
        /** \brief If the data is empty.
        *
        *   Returns true if the data is empty.
         *
         * \return bool : true if empty.
         *
         */
        bool empty();
        /** \brief Erases a value.
        *
        *   Erases the value of the iterator.
         *
         * \param iterator : the iterator to the value.
         * \return void
         *
         */
        void erase(iterator);
        /** \brief Erases many value.
        *
        *   Erases the values from the first iterator to the second.
         *
         * \param iterator : the iterator to the first value.
         * \param iterator : the iterator to the last value.
         * \return void
         *
         */
        void erase(iterator, iterator);
        /** \brief Finds a value.
        *
        *   Returns an iterator of the found value.
         *
         * \param const std::string& : ID of the value.
         * \return iterator : iterator to the value.
         *
         */
        iterator find(const std::string&);
        /** \brief Swaps with another Data.
         *
         * \param Data& : Data to swap.
         * \return void
         *
         */
        void swap(Data&);
        /** \brief Creates a new value.
         *
         * \param std::string const& : ID of the value created.
         * \return std::shared_ptr<Value> : pointer to the value created.
         *
         */
        std::shared_ptr<Value> append(std::string const&);
        /** \brief Adds a new value.
         *
         * \param std::string const& : ID of the new value;
         * \param std::shared_ptr<Value> : pointer to the new value.
         * \return void
         *
         */
        void append(std::string const&, std::shared_ptr<Value>);
        /** \brief Returns the number of values in the data.
         *
         * \return size_t : size.
         *
         */
        size_t size() const;
        /** \brief Gets a string corresponding.
        *
        *   Returns a string processed from the data. This string can be saved in any way and can be loaded by a Data with load() to restore the saved values.
         *
         * \return std::string const& : string of the data.
         *
         */
        std::string const& getString() const;
        /** \brief Loads a data from a string.
        *
        *   Loads the data structure from the provided string. The string must be generated with the getString() function.
         *
         * \param std::string const& : string of the data.
         * \return void
         *
         */
        void load(std::string const&);
    };
    inline void Data::Value::setInt(long long v)
    {
        m_parent->m_requestUpdate = true;
        m_value = Various::intToString(v);
    }
    inline void Data::Value::setDouble(long double v)
    {
        m_parent->m_requestUpdate = true;
        m_value = Various::doubleToString(v);
    }
    inline void Data::Value::setString(std::string const& v)
    {
        m_parent->m_requestUpdate = true;
        m_value = v;
    }
    inline long double Data::Value::getValue() const
    {
        return Various::stringToDouble(m_value);
    }
    inline std::string const& Data::Value::getString() const
    {
        return m_value;
    }
    inline std::shared_ptr<Data::Value> Data::operator[](std::string const& ID)
    {
        return m_data[ID];
    }
    inline std::shared_ptr<const Data::Value> Data::operator[](std::string const& ID) const
    {
        return m_data[ID];
    }
    inline std::shared_ptr<Data::Value> Data::get(std::string const& ID)
    {
        return m_data[ID];
    }
    inline std::shared_ptr<const Data::Value> Data::get(std::string const& ID) const
    {
        return m_data[ID];
    }
    inline Data::const_iterator Data::begin() const
    {
        return m_data.begin();
    }
    inline Data::const_reverse_iterator Data::rbegin() const
    {
        return m_data.rbegin();
    }
    inline Data::const_iterator Data::end() const
    {
        return m_data.end();
    }
    inline Data::const_reverse_iterator Data::rend() const
    {
        return m_data.rend();
    }
    inline Data::iterator Data::begin()
    {
        return m_data.begin();
    }
    inline Data::reverse_iterator Data::rbegin()
    {
        return m_data.rbegin();
    }
    inline Data::iterator Data::end()
    {
        return m_data.end();
    }
    inline Data::reverse_iterator Data::rend()
    {
        return m_data.rend();
    }
    inline void Data::clear()
    {
        m_data.clear();
    }
    inline bool Data::empty()
    {
        return m_data.empty();
    }
    inline void Data::erase(Data::iterator it)
    {
        m_data.erase(it);
    }
    inline void Data::erase(Data::iterator it1, Data::iterator it2)
    {
        m_data.erase(it1, it2);
    }
    inline Data::iterator Data::find(const std::string& str)
    {
        return m_data.find(str);
    }
    inline void Data::swap(Data& dat)
    {
        m_data.swap(dat.m_data);
        dat.m_requestUpdate = true;
        m_requestUpdate = true;
    }
    inline size_t Data::size() const
    {
        return m_data.size();
    }
}

#endif // DEF_DATA_HPP

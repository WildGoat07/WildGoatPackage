#ifndef DEF_FUNCTION_HPP
#define DEF_FUNCTION_HPP

namespace wp
{
    /** \brief Interface to handle functions
    *
    *   \class Function
    *
    *   Interface to handle any function with one antecedent possible.
     */
    class Function
    {
    public:
        /** \brief Returns the image.
        *
        *   Returns the image of the function with the specified antecedent. The result and the antecedent are always and must always be between 0 and 1.
         *
         * \param double : antecedent.
         * \return double : image.
         *
         */
        virtual double operator()(double) const = 0;
    };
}

#endif // DEF_FUNCTION_HPP

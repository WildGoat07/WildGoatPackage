#ifndef DEF_DEFAULT_FONCTIONS_HPP
#define DEF_DEFAULT_FONCTIONS_HPP
#include "Various.hpp"
#include "Function.hpp"

namespace wp
{
    /** \brief The default function with one parameter.
    *
    *   \class DefaultFunction
     */
    class DefaultFunction : public Function
    {
    protected:
        double m_degree = 1;
    public:
        /** \brief Changes the degree.
        *
        *   Sets a new degree of the function.
         *
         * \param double : the degree.
         * \return void
         *
         */
        void setDegree(double);
        /** \brief Returns the degree.
         *
         * \return double : the degree.
         *
         */
        double getDegree() const;
    };
    /** \brief A quadratic Function.
    *
    *   \class QuadFunction
     */
    class QuadFunction : public DefaultFunction
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
        virtual double operator()(double) const override;
    };

    /** \brief A reversed quadratic Function.
    *
    *   \class SqrtFunction
     */
    class SqrtFunction : public DefaultFunction
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
        virtual double operator()(double) const override;
    };

    /** \brief A gauss-like Function.
    *
    *   \class GaussFunction
     */
    class GaussFunction : public DefaultFunction
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
        virtual double operator()(double) const override;
    };

    /** \brief A reversed gauss-like Function.
    *
    *   \class ReverseGaussFunction
     */
    class ReverseGaussFunction : public DefaultFunction
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
        virtual double operator()(double) const override;
    };

    /** \brief A linear Function.
    *
    *   \class LinearFunction
     */
    class LinearFunction : public DefaultFunction
    {
    public:
        LinearFunction();
        /** \brief Returns the image.
        *
        *   Returns the image of the function with the specified antecedent. The result and the antecedent are always and must always be between 0 and 1.
         *
         * \param double : antecedent.
         * \return double : image.
         *
         */
        virtual double operator()(double) const override;
    };
    inline double QuadFunction::operator()(double v) const
    {
        return wp::Various::quadInter(0, 1, v, m_degree);
    }
    inline void DefaultFunction::setDegree(double d)
    {
        m_degree = d;
    }
    inline double DefaultFunction::getDegree() const
    {
        return m_degree;
    }
    inline double SqrtFunction::operator()(double v) const
    {
        return wp::Various::sqrtInter(0, 1, v, m_degree);
    }
    inline double GaussFunction::operator()(double v) const
    {
        return wp::Various::gaussInter(0, 1, v, m_degree);
    }
    inline double ReverseGaussFunction::operator()(double v) const
    {
        return wp::Various::reverseGaussInter(0, 1, v, m_degree);
    }
    inline double LinearFunction::operator()(double v) const
    {
        return wp::Various::linearInter(0, 1, v, m_degree);
    }
    inline LinearFunction::LinearFunction()
    {
        m_degree = 0;
    }
}
#endif // DEF_DEFAULT_FONCTIONS_HPP


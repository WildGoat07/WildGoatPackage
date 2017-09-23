#ifndef DEF_BEZIER_HPP
#define DEF_BEZIER_HPP
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "Various.hpp"

namespace wp
{
    /** \brief Class that handle %Bézier's curve.
    *
    *   \class Bezier
    *
    *   \see [Bézier curve on wikipedia](https://en.wikipedia.org/wiki/Bézier_curve)
     */
    class Bezier
    {
    private:
        std::vector<sf::Vector2f> m_checkpoints;
    public:
        /** \brief Structure to define a line.
        *
        *   \struct Line
         */
        struct Line
        {
            sf::Vector2f start;/**< starting point */
            sf::Vector2f direction;/**< direction */
            /** \brief Constructor.
             *
             *
             */
            Line();
            /** \brief Alternative constructor.
             *
             * \param sf::Vector2f : starting point.
             * \param sf::Vector2f : direction.
             *
             */
            Line(sf::Vector2f, sf::Vector2f);
            /** \brief Returns a point of the line.
            *
            *   Returns the image of the function defined by y(x) = start + direction * x.
             *
             * \param double : the antecedent.
             * \return sf::Vector2f : the image.
             *
             */
            sf::Vector2f operator()(double) const;
        };
        /** \brief Clears the points.
         *
         * \return void
         *
         */
        void clear();
        /** \brief Adds a point to the end.
         *
         * \param sf::Vector2f : point.
         * \return void
         *
         */
        void addPoint(sf::Vector2f);
        /** \brief Returns the position of a point.
         *
         * \param unsigned int : index of the point.
         * \return sf::Vector2f : point.
         *
         */
        sf::Vector2f getPoint(unsigned int) const;
        /** \brief Moves a point of the curve.
         *
         * \param unsigned int : index of the point.
         * \param sf::Vector2f : new position.
         * \return void
         *
         */
        void movePoint(unsigned int, sf::Vector2f);
        /** \brief Returns the curve's image.
        *
        *   The antecedent must be between 0 and 1(included).
         *
         * \param double : antecedent.
         * \return sf::Vector2f : image.
         *
         */
        sf::Vector2f getValue(double) const;
        /** \brief Returns the tangent of the curve.
        *
        *   The antecedent must be between 0 and 1 (included).
         *
         * \param double : antecedent.
         * \return Line : tangent.
         *
         */
        Line getTangeant(double) const;
        /** \brief Returns the number of points.
         *
         * \return size_t : number of points.
         *
         */
        size_t size() const;
        /** \brief Returns the length of the curve.
        *
        *   Because the curve has an irrational length, you must specify a precision. The precision specify in how many pieces the curve will be cut.
         *
         * \param uint32_t : precision.
         * \return long double : approximative length.
         *
         */
        long double length(uint32_t) const;
    };
    inline sf::Vector2f Bezier::Line::operator()(double t) const
    {
        return start + t*direction;
    }
    inline void Bezier::clear()
    {
        m_checkpoints.clear();
    }
    inline void Bezier::addPoint(sf::Vector2f p)
    {
        m_checkpoints.push_back(p);
    }
    inline sf::Vector2f Bezier::getPoint(unsigned int i) const
    {
        return m_checkpoints[i];
    }
    inline void Bezier::movePoint(unsigned int i, sf::Vector2f p)
    {
        m_checkpoints[i] = p;
    }
    inline size_t Bezier::size() const
    {
        return m_checkpoints.size();
    }
}

#endif // DEF_BEZIER_HPP


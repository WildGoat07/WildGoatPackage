#ifndef DEF_GRAPHICMOTOR_MATRIX
#define DEF_GRAPHICMOTOR_MATRIX
#include <vector>
#include <cmath>
#include <iostream>
#include <SFML/System.hpp>

namespace wp
{
    /** \brief Class that handles a matrix.
    *
    *   \class Matrix
    *
    *   Handles a matrix and do many operations on it.
     */
    class  Matrix
    {
    private:
        std::vector<std::vector<double> > m_matrix;
    public:
        /** \brief Returns the identity matrix.
        *
        *   Returns the identity matrix with the specified size.
         *
         * \param size_t : size of the matrix.
         * \return Matrix : the identity matrix.
         *
         */
        static Matrix  getIdentity(size_t);

        /** \brief Constructor.
         *
         * \param size_t : width of the matrix(Optional, 1 by default).
         * \param size_t : height of the matrix(Optional, 1 by default)
         *
         */
        Matrix(size_t = 1, size_t = 1);
        /** \brief Constructor.
         *
         * \param sf::Vector2u : size of the matrix.
         *
         */
        Matrix(sf::Vector2u);
        /** \brief Copy constructor.
         *
         * \param const& Matrix : matrix to copy.
         *
         */
        Matrix(Matrix const&);
        /** \brief Creates a new matrix.
        *
        *   Creates a new matrix with new sizes.
         *
         * \param size_t : width of the matrix.
         * \param size_t : height of the matrix.
         * \return void
         *
         */
        void create(size_t, size_t);
        /** \brief Creates a new matrix.
        *
        *   Creates a new matrix with new sizes.
         *
         * \param sf::Vector2u : size of the matrix.
         * \return void
         *
         */
        void create(sf::Vector2u);
        /** \brief Returns the size.
        *
        *   Returns the size of the matrix.
         *
         * \return sf::Vector2u : size of the matrix.
         *
         */
        sf::Vector2u getSize() const;
        /** \brief Returns the value of the coordinates.
         *
         * \param sf::Vector2u : coordinates.
         * \return double& : reference to the value.
         *
         */
        double& get(sf::Vector2u);
        /** \brief Returns the value of the coordinates.
         *
         * \param size_t : x position.
         * \param size_t : y position.
         * \return double& : reference to the value.
         *
         */
        double& get(size_t, size_t);
        /** \brief Returns the value of the coordinates.
        *
        *   A constant version of get(sf::Vector2u).
         *
         * \param sf::Vector2u : coordinates.
         * \return double& : constant value.
         *
         */
        double get_const(sf::Vector2u) const;
        /** \brief Returns the value of the coordinates.
        *
        *   A constant version of get(size_t, size_t).
         *
         * \param size_t : x position.
         * \param size_t : y position.
         * \return double& : constant value.
         *
         */
        double get_const(size_t, size_t) const;
        /** \brief Returns the determiner.
        *
        *   Returns the determiner of the matrix. Be sure the matrix is square or it will return 0.
         *
         * \return double : the determiner.
         *
         */
        double getDeterminer() const;
        /** \brief Returns the transposed matrix.
         *
         * \return Matrix : the transposed matrix.
         *
         */
        Matrix getTransposed() const;
        /** \brief Returns a sub-matrix.
        *
        *   Returns the sub-matrix from the specified coordinates.
         *
         * \param size_t : x position.
         * \param size_t : y position.
         * \return Matrix : the sub-matrix.
         *
         */
        Matrix getSubMatrix(size_t, size_t) const;
        /** \brief Returns a sub-matrix.
        *
        *   Returns the sub-matrix from the specified coordinates.
         *
         * \param sf::Vector2u : the coordinates.
         * \return Matrix : the sub-matrix.
         *
         */
        Matrix getSubMatrix(sf::Vector2u) const;
        /** \brief Returns the inverse matrix.
        *
        *   Returns itself if the inverse matrix isn't available.
         *
         * \return Matrix : the inverse matrix.
         *
         */
        Matrix getInverse() const;
        /** \brief Returns the adjugate matrix
        *
        *   Returns itself if the adjugate matrix isn't available.
         *
         * \return Matrix : the adjugate matrix.
         *
         */
        Matrix getAdjugateMatrix() const;
        /** \brief Returns the minor
        *
        *   Returns the minor of the matrix from the specified coordinates.
         *
         * \param size_t : x position.
         * \param size_t : y position.
         * \return double : minor.
         *
         */
        double getMinor(size_t, size_t) const;
        /** \brief Returns the minor
        *
        *   Returns the minor of the matrix from the specified coordinates.
         *
         * \param sf::Vector2u : coordinates.
         * \return double : minor.
         *
         */
        double getMinor(sf::Vector2u) const;
        /** \brief Returns the cofactor
        *
        *   Returns the cofactor of the matrix from the specified coordinates.
         *
         * \param size_t : x position.
         * \param size_t : y position.
         * \return double : cofactor.
         *
         */
        double getCofactor(size_t, size_t) const;
        /** \brief Returns the cofactor
        *
        *   Returns the cofactor of the matrix from the specified coordinates.
         *
         * \param sf::Vector2u : coordinates.
         * \return double : cofactor.
         *
         */
        double getCofactor(sf::Vector2u) const;
        void operator+=(Matrix const&);
        void operator-=(Matrix const&);
        void operator*=(Matrix const&);
        void operator*=(double);
        void operator/=(double);
        void operator/=(Matrix const&);
    };
}
wp::Matrix operator+(wp::Matrix, wp::Matrix);
wp::Matrix operator-(wp::Matrix);
wp::Matrix operator-(wp::Matrix, wp::Matrix);
wp::Matrix operator*(wp::Matrix, wp::Matrix);
wp::Matrix operator/(wp::Matrix, wp::Matrix);
wp::Matrix operator*(double, wp::Matrix);
wp::Matrix operator*(wp::Matrix, double);
wp::Matrix operator/(wp::Matrix, double);

/** \brief Converts the matrix as a vector
*
*   Converts the first column as a vector with two components.
 *
 * \param const& wp::Matrix : the matrix
 * \return sf::Vector2f : the new vector
 *
 */
sf::Vector2f getMatrixAsVector2(wp::Matrix const&);
/** \brief Converts the vector as a matrix
*
*   Converts the vector as the first column in the matrix.
 *
 * \param const& sf::Vector2f : the vector.
 * \return wp::Matrix : the new matrix.
 *
 */
wp::Matrix getVector2AsMatrix(sf::Vector2f const&);
/** \brief Converts the matrix as a vector
*
*   Converts the first column as a vector with three components.
 *
 * \param const& wp::Matrix : the matrix
 * \return sf::Vector3f : the new vector
 *
 */
sf::Vector3f getMatrixAsVector3(wp::Matrix const&);
/** \brief Converts the vector as a matrix
*
*   Converts the vector as the first column in the matrix.
 *
 * \param const& sf::Vector3f : the vector.
 * \return wp::Matrix : the new matrix.
 *
 */
wp::Matrix getVector3AsMatrix(sf::Vector3f const&);


#endif // DEF_GRAPHICMOTOR_MATRIX

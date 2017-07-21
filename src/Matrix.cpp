#include "Matrix.hpp"

using namespace wp;

Matrix operator+(Matrix a, Matrix b)
{
    a += b;
    return a;
}
Matrix operator-(Matrix a, Matrix b)
{
    a -= b;
    return a;
}
Matrix operator-(Matrix a)
{
    a *= -1;
    return a;
}
Matrix operator*(Matrix a, Matrix b)
{
    a *= b;
    return a;
}
Matrix operator/(Matrix a, Matrix b)
{
    a /= b;
    return a;
}
Matrix operator/(Matrix a, double b)
{
    a /= b;
    return a;
}
Matrix operator*(Matrix a, double b)
{
    a *= b;
    return a;
}
Matrix operator*(double b, Matrix a)
{
    a *= b;
    return a;
}

Matrix::Matrix(Matrix const& m)
{
    m_matrix = m.m_matrix;
}
Matrix::Matrix(sf::Vector2u v) : Matrix(v.x, v.y)
{}

Matrix Matrix::getIdentity(size_t v)
{
    Matrix m(v, v);
    for (int i = 0;i<v;i++)
        m.get(i, i) = 1;
    return m;
}

Matrix::Matrix(size_t x, size_t y)
{
    if (x < 1 || y < 1)
    {
        std::cerr << "can not construct matrix with invalid size" << std::endl;
    }
    for (unsigned int i = 0;i<x;i++)
    {
        std::vector<double> tmp;
        for (unsigned int j = 0;j<y;j++)
        {
            tmp.push_back(0);
        }
        m_matrix.push_back(tmp);
    }
}
void Matrix::create(sf::Vector2u v)
{
    *this = Matrix(v);
}
void Matrix::create(size_t x, size_t y)
{
    *this = Matrix(x, y);
}
sf::Vector2u Matrix::getSize() const
{
    return sf::Vector2u(m_matrix.size(), m_matrix[0].size());
}
double& Matrix::get(sf::Vector2u v)
{
    return m_matrix[v.x][v.y];
}
double& Matrix::get(size_t x, size_t y)
{
    return m_matrix[x][y];
}
double Matrix::get_const(sf::Vector2u v) const
{
    return m_matrix[v.x][v.y];
}
double Matrix::get_const(size_t x, size_t y) const
{
    return m_matrix[x][y];
}
double Matrix::getDeterminer() const
{
    if (getSize().x != getSize().y)
        return 0;
    if (getSize().x == 1)
        return m_matrix[0][0];
    if (getSize().x == 2)
    {
        double det;
        det = m_matrix[0][0] * m_matrix[1][1];
        det -= m_matrix[1][0] * m_matrix[0][1];
        return det;
    }
    else
    {
        double det = 0;
        for (unsigned int j = 0;j<getSize().y;j++)
        {
            double tmp;
            tmp = getSubMatrix(0, j).getDeterminer();
            if (j%2 == 1)
                det += -tmp * m_matrix[0][j];
            else
                det += tmp * m_matrix[0][j];
        }
        return det;
    }
}
Matrix Matrix::getAdjugateMatrix() const
{
    if (getSize().x != getSize().y)
    {
        std::cerr << "invalid size of matrix" << std::endl;
        return *this;
    }
    if (getSize().x == 2)
    {
        Matrix matrice(*this);
        matrice.get(0, 0) = m_matrix[1][1];
        matrice.get(0, 1) = -m_matrix[1][0];
        matrice.get(1, 0) = -m_matrix[0][1];
        matrice.get(1, 1) = m_matrix[0][0];
        return matrice;
    }
    Matrix matrice(*this);
    for (unsigned int i = 0;i<getSize().x;i++)
    {
        for (unsigned int j = 0;j<getSize().y;j++)
        {
            double tmp;
            tmp = getSubMatrix(i, j).getDeterminer();
            if ((i+j)%2 == 1)
                matrice.get(i, j) = -tmp;
            else
                matrice.get(i, j) = tmp;
        }
    }
    return matrice;
}
double Matrix::getCofactor(size_t x, size_t y) const
{
    double factor = getMinor(x, y);
    if ((x+y)%2 == 1)
        factor *= -1;
    return factor;
}
double Matrix::getCofactor(sf::Vector2u v) const
{
    return getCofactor(v.x, v.y);
}
double Matrix::getMinor(sf::Vector2u v) const
{
    return getMinor(v.x, v.y);
}
double Matrix::getMinor(size_t x, size_t y) const
{
    return getSubMatrix(x, y).getDeterminer();
}
Matrix Matrix::getSubMatrix(sf::Vector2u v) const
{
    return getSubMatrix(v.x, v.y);
}
Matrix Matrix::getSubMatrix(size_t x, size_t y) const
{
    Matrix matrice(getSize() - sf::Vector2u(1, 1));
    size_t a = 0, b = 0;
    for (unsigned int i = 0;i<getSize().x;i++)
    {
        b = 0;
        for (unsigned int j = 0;j<getSize().y;j++)
        {
            if (i != x && j != y)
            {
                matrice.get(a, b) = m_matrix[i][j];
                b++;
            }
        }
        if (i != x)
            a++;
    }
    return matrice;
}
Matrix Matrix::getInverse() const
{
    double det = getDeterminer();
    if (det != 0)
        return (getAdjugateMatrix().getTransposed() / det);
    else
    {
        std::cerr << "can not inverse the matrix" << std::endl;
        return *this;
    }
}
Matrix Matrix::getTransposed() const
{
    Matrix matrice(getSize().y, getSize().x);

    for (unsigned int i = 0;i<getSize().x;i++)
    {
        for (unsigned int j = 0;j<getSize().y;j++)
        {
            matrice.get(j, i) = m_matrix[i][j];
        }
    }
    return matrice;
}
void Matrix::operator+=(Matrix const& m)
{
    if (getSize().x != m.getSize().x || getSize().y != m.getSize().y)
    {
        std::cerr << "invalid size of matrix" << std::endl;
        return;
    }
    for (unsigned int i = 0;i<getSize().x;i++)
    {
        for (unsigned int j = 0;j<getSize().y;j++)
            m_matrix[i][j] += m.m_matrix[i][j];
    }
}
void Matrix::operator-=(Matrix const& m)
{
    if (getSize().x != m.getSize().x || getSize().y != m.getSize().y)
    {
        std::cerr << "invalid size of matrix" << std::endl;
        return;
    }
    for (unsigned int i = 0;i<getSize().x;i++)
    {
        for (unsigned int j = 0;j<getSize().y;j++)
            m_matrix[i][j] -= m.m_matrix[i][j];
    }
}
void Matrix::operator*=(Matrix const& m)
{
    if (getSize().x != m.getSize().y)
    {
        std::cerr << "invalid size of matrix" << std::endl;
        return;
    }
    Matrix matrice(m.getSize().x, getSize().y);
    for (unsigned int i = 0;i<m.getSize().x;i++)
    {
        for (unsigned int j = 0;j<getSize().y;j++)
        {
            double value = 0;
            for (unsigned int k = 0;k<getSize().x;k++)
                value += m_matrix[k][j] * m.m_matrix[i][k];
            matrice.m_matrix[i][j] = value;
        }
    }
    m_matrix = matrice.m_matrix;
}
void Matrix::operator/=(Matrix const& n)
{
    Matrix m(n.getInverse());
    if (getSize().x != m.getSize().y)
    {
        std::cerr << "invalid size of matrix" << std::endl;
        return;
    }
    Matrix matrice(m.getSize().x, getSize().y);
    for (unsigned int i = 0;i<m.getSize().x;i++)
    {
        for (unsigned int j = 0;j<getSize().y;j++)
        {
            double value = 0;
            for (unsigned int k = 0;k<getSize().x;k++)
                value += m_matrix[k][j] * m.m_matrix[i][k];
            matrice.m_matrix[i][j] = value;
        }
    }
    m_matrix = matrice.m_matrix;
}
void Matrix::operator*=(double n)
{
    for (unsigned int  i = 0;i<getSize().x;i++)
    {
        for (unsigned int j = 0;j<getSize().y;j++)
            m_matrix[i][j] *= n;
    }
}
void Matrix::operator/=(double n)
{
    for (unsigned int  i = 0;i<getSize().x;i++)
    {
        for (unsigned int j = 0;j<getSize().y;j++)
            m_matrix[i][j] /= n;
    }
}

sf::Vector3f getMatrixAsVector3(Matrix const& m)
{
    if (m.getSize().y == 4)
        return sf::Vector3f(m.get_const(0, 0), m.get_const(0, 1), m.get_const(0, 2));
    else
    {
        std::cerr << "can not convert Matrix to sf::Vector3f" << std::endl;
        return sf::Vector3f();
    }
}
sf::Vector2f getMatrixAsVector2(Matrix const& m)
{
    if (m.getSize().y == 3)
        return sf::Vector2f(m.get_const(0, 0), m.get_const(0, 1));
    else
    {
        std::cerr << "can not convert Matrix to sf::Vector2f" << std::endl;
        return sf::Vector2f();
    }
}
Matrix getVector2AsMatrix(sf::Vector2f const& v)
{
    Matrix m(1, 3);
    m.get(0, 2) = 1;
    m.get(0, 0) = v.x;
    m.get(0, 1) = v.y;
    return m;
}
Matrix getVector3AsMatrix(sf::Vector3f const& v)
{
    Matrix m(1, 4);
    m.get(0, 3) = 1;
    m.get(0, 0) = v.x;
    m.get(0, 1) = v.y;
    m.get(0, 2) = v.z;
    return m;
}

#include <iostream>
#include <random>
#include <ostream>
#include <cstring>
#include "Dvector.h"

Dvector::Dvector()
{
    m_size = 0;
    m_coords = nullptr;
    std::cout << "Constructeur par défaut" << std::endl;
}

Dvector::Dvector(const int size, const double val)
{
    std::cout << "Constructeur taille / valeur" << std::endl;

    if (size < 0)
    {
        throw std::invalid_argument("Taille invalide");
    }

    m_size = size;
    if (m_size == 0)
    {
        m_coords = nullptr;
    }
    else
    {
        m_coords = new double[size];
        for (int i = 0; i < size; i++)
        {
            m_coords[i] = val;
        }
    }
}

Dvector::Dvector(const Dvector &other) : Dvector()
{
    std::cout << "Constructeur par copie" << std::endl;
    *this = other;
}

Dvector::Dvector(std::string fileName)
{
    std::cout << "Constructeur par fichier" << std::endl;
    std::ifstream initFile(fileName);

    if (initFile)
    {
        std::string currentWord;
        m_size = 0;
        while (initFile >> currentWord)
        {
            m_size++;
        }

        initFile.clear();
        initFile.seekg(0, std::ios::beg);

        if (m_size != 0)
        {
            m_coords = new double[m_size];
            for (int i = 0; i < m_size; i++)
            {
                initFile >> currentWord;
                m_coords[i] = std::stod(currentWord);
            }
        }
        else
        {
            m_coords = NULL;
        }
    }
    else
    {
        throw std::invalid_argument("Impossible d'ouvrir le fichier " + fileName);
    }
}

void Dvector::display(std::ostream &str) const
{
    for (int i = 0; i < m_size; i++)
    {
        str << m_coords[i] << std::endl;
    }
}

int Dvector::size() const
{
    return m_size;
}

double *Dvector::coords() const
{
    return m_coords;
}

void Dvector::fillRandomly()
{
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0, 1);
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] = distribution(generator);
    }
}

Dvector::~Dvector()
{
    std::cout << "Destructeur" << std::endl;
    delete[] m_coords;
}

void Dvector::setSize(const int newSize) {
    if (newSize < 0)
    {
        throw std::invalid_argument("Taille invalide");
    }

    if (m_size != newSize)
    {
        if (newSize != 0)
        {
            double* temp = new double[newSize];
            if (m_size != 0)
            {
                memcpy(temp, m_coords, std::min(m_size, newSize)*sizeof(double));
                delete[] m_coords;
            }
            m_coords = temp;
        }
        else
        {
            if (m_size != 0)
            {
                delete[] m_coords;
            }
            
            m_coords = nullptr;
        }
        m_size = newSize;
    }
}

void Dvector::resize(const int newSize, const double val)
{
    int temp = m_size;
    setSize(newSize);
    if (newSize > temp)
    {
        for (int i = temp; i < m_size; i++)
        {
            m_coords[i] = val;
        }
    }
}

/* Acces operator */
double &Dvector::operator()(const int i) const
{
    if (i < 0 || i >= m_size)
    {
        throw std::out_of_range("Indice invalide");
    }

    return m_coords[i];
}

/* Arithmetic operators */

Dvector &Dvector::operator+=(const double x)
{
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] += x;
    }
    return *this;
}

Dvector &Dvector::operator+=(const Dvector &other)
{
    if (m_size != other.m_size)
    {
        throw std::domain_error("Tailles des Dvectors incompatibles");
    }

    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] += other.m_coords[i];
    }
    return *this;
}

Dvector &Dvector::operator-=(const double x)
{
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] -= x;
    }
    return *this;
}

Dvector &Dvector::operator-=(const Dvector &other)
{
    if (m_size != other.m_size)
    {
        throw std::domain_error("Tailles des Dvectors incompatibles");
    }

    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] -= other.m_coords[i];
    }
    return *this;
}

Dvector &Dvector::operator*=(const double x)
{
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] *= x;
    }
    return *this;
}

Dvector &Dvector::operator/=(const double x)
{
    if (x == 0)
    {
        throw std::domain_error("Division par 0");
    }

    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] /= x;
    }
    return *this;
}

Dvector operator-(const Dvector &v)
{
    return v * (-1);
}

Dvector operator+(const Dvector &v, const double x)
{
    Dvector ret(v);
    ret += x;
    return ret;
}

Dvector operator+(const Dvector &v1, const Dvector &v2)
{
    Dvector ret(v1);
    ret += v2;
    return ret;
}

Dvector operator-(const Dvector &v, const double x)
{
    Dvector ret(v);
    ret -= x;
    return ret;
}

Dvector operator-(const Dvector &v1, const Dvector &v2)
{
    Dvector ret(v1);
    ret -= v2;
    return ret;
}

Dvector operator*(const Dvector &v, const double x)
{
    Dvector ret(v);
    ret *= x;
    return ret;
}

Dvector operator/(const Dvector &v, const double x)
{
    Dvector ret(v);
    ret /= x;
    return ret;
}

/* Stream operators */

std::ostream &operator<<(std::ostream &stream, const Dvector &v)
{
    v.display(stream);
    return stream;
}

std::istream &operator>>(std::istream &stream, Dvector &v)
{
    int i = 0;
    while (i < v.size() && stream >> v(i))
    {
        i++;
    }
    return stream;
}

/* Boolean operators */

bool Dvector::operator==(const Dvector &other) const
{
    if (m_size != other.m_size)
    {
        return false;
    }
    else
    {
        if (m_size == 0)
        {
            // m_coords et other.m_coords doivent etre égaux (à nullptr)
            if (m_coords != other.m_coords)
            {
                return false;
            }
        }
        for (int i = 0; i < m_size; i++)
        {
            if (m_coords[i] != other.m_coords[i])
            {
                return false;
            }
        }
    }

    return true;
}

bool Dvector::operator!=(const Dvector &other) const
{
    return !(*this == other);
}

Dvector &Dvector::operator=(const Dvector &other)
{
    if (this != &other)
    {
        setSize(other.m_size);
        memcpy(m_coords, other.m_coords, m_size * sizeof(double));
    }
    return *this;
}

// Dvector &Dvector::operator=(const Dvector &other)
// {
//     if (this != &other)
//     {
//         if (m_size != other.m_size)
//         {
//             m_size = other.m_size;
//             delete[] m_coords;
//             if (m_size == 0)
//             {
//                 m_coords = nullptr;
//             }
//             else
//             {
//                 m_coords = new double[m_size];
//             }
//         }
//         for (int i = 0; i < m_size; i++)
//         {
//             m_coords[i] = other.m_coords[i];
//         }
//     }
//     return *this;
// }
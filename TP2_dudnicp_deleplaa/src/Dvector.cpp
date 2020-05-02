#include <iostream>
#include <random>
#include <fstream>
#include <ostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cstring>
#include "Dvector.h"


Dvector::Dvector() {
    std::cout << "Default constructor" << std::endl;
    m_size = 0;
}

Dvector::Dvector(int size) {
    std::cout << "Constructor given size" << std::endl;
    m_size = size;
    m_coords = new double[size];
}

Dvector::Dvector(int size, double val) {
    std::cout << "Constructor given size and common value" << std::endl;
    m_size = size;
    m_coords = new double[size];
    for (int i = 0; i < size; i++) {
        m_coords[i] = val;
    }
}

Dvector::Dvector(const Dvector &other) {
    std::cout << "Copy constructor" << std::endl;
    m_size = other.m_size;
    m_coords = new double[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] = other.m_coords[i];
    }
}

Dvector::Dvector(std::string fileName) {
    std::cout << "Constructor given file name" << std::endl;
    std::ifstream initFile(fileName);

    if (initFile) {
        std::string currentWord;
        m_size = 0;
        while(initFile >> currentWord) {
            m_size ++;
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

        } else {
            m_coords = NULL;
        }
        
    } else {
        std::cout << "Impossible to open file " << fileName << std::endl;
    }
}

void Dvector::display(std::ostream &str) const{
    for (int i = 0; i < m_size; i++)
    {
        str << m_coords[i] << std::endl;
    }
}

int Dvector::size() const {
    return m_size;
}

double* Dvector::coords() const {
    return m_coords;
}

void Dvector::fillRandomly() {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0,1);
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] = distribution(generator);
    }
}

void Dvector::resize(const int newSize, const double val = 0) {
    m_coords = (double*) realloc(m_coords, newSize * sizeof(double));
    if (newSize > m_size)
    {
        for (int i = m_size; i < newSize; i++)
        {
            m_coords[i] = val;
        }
    }
    m_size = newSize;
}

Dvector::~Dvector() {}

/* Acces operator */
double& Dvector::operator()(const int i) {
    assert(i >= 0 && i < m_size);

    return m_coords[i];   
}

/* Arithmetic operators */

Dvector& Dvector::operator+=(const double x) {
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] += x;
    }
    return *this;
}

Dvector& Dvector::operator+=(const Dvector &other) {
    assert(m_size == other.m_size);
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] += other.m_coords[i];
    }
    return *this;
}


Dvector& Dvector::operator-=(const double x) {
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] -= x;
    }
    return *this;
}

Dvector& Dvector::operator-=(const Dvector &other) {
    assert(m_size == other.m_size);
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] -= other.m_coords[i];
    }
    return *this;
}

Dvector& Dvector::operator*=(const double x) {
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] *= x;
    }
    return *this;
}

Dvector& Dvector::operator/=(const double x) {
    assert(x != 0);
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] /= x;
    }
    return *this;
}

Dvector operator-(const Dvector &v) {
    Dvector ret(v);
    return ret * -1;
}


Dvector operator+(const Dvector &v, const double x) {
    Dvector ret(v);
    ret += x;
    return ret;
}

Dvector operator+(const Dvector &v1, const  Dvector &v2) {
    Dvector ret(v1);
    ret += v2;
    return ret;
}


Dvector operator-(const Dvector &v, const double x) {
    Dvector ret(v);
    ret -= x;
    return ret;
}

Dvector operator-(const Dvector &v1, const Dvector &v2) {
    Dvector ret(v1);
    ret -= v2;
    return ret;
}


Dvector operator*(const Dvector &v, const double x) {
    Dvector ret(v);
    ret *= x;
    return ret;
}


Dvector operator/(const Dvector &v, const double x) {
    Dvector ret(v);
    ret /= x;
    return ret;
}

/* Stream operators */

std::ostream& operator<<(std::ostream& stream, const Dvector& v) {
    v.display(stream);
    return stream;
}

std::istream& operator>>(std::istream& stream, Dvector& v) {
    int i = 0;
    while (i < v.size() && stream >> v(i))
    {
        i++;
    }
    return stream;
}

/* Boolean operators */

bool Dvector::operator==(const Dvector& other) const {
    if (m_size != other.m_size)
    {
        return false;
    }
    for (int i = 0; i < m_size; i++)
    {
        if (m_coords[i] != other.m_coords[i])
        {
            return false;
        }
    }
    return true;
}

Dvector& Dvector::operator=(const Dvector &other) {
    if (this != &other)
    {
        memcpy(this, &other, sizeof(other));
    }
}

/*
void Dvector::operator=(const Dvector& other) {
    m_size = other.m_size;
    m_coords = new double[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] = other.m_coords[i];
    }
}
*/
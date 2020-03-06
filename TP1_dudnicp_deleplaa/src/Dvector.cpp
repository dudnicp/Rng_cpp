#include <iostream>
#include <random>
#include <fstream>
#include "Dvector.h"

Dvector::Dvector() {
    std::cout << "Default constructor" << std::endl;
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

Dvector::Dvector(Dvector &other) {
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

        if (m_size != 0)
        {
            m_coords = new double[m_size];
            initFile.seekg(std::ios::beg);
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

Dvector::~Dvector() {}
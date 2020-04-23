#include "Dvector.h"
#include <random>
#include <cassert>
#include <fstream>
#include <iostream>

/**
 * \file Dvector.cpp
 * \brief Vecteur de doubles
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

Dvector::Dvector() {
    std::cout << "Constructeur par défaut" << std::endl;
    m_size = 0;
    m_coords = nullptr;
}

Dvector::Dvector(int size, double val) {
    std::cout << "Constructeur taille / valeur" << std::endl;
    m_size = size;
    m_coords = new double[size];
    for (int i = 0; i < size; i++) {
        m_coords[i] = val;
    }
}

Dvector::Dvector(const Dvector &other) {
    std::cout << "Constructeur par copie" << std::endl;
    m_size = other.m_size;
    m_coords = new double[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_coords[i] = other.m_coords[i];
    }
}

Dvector::Dvector(std::string fileName) {
    std::cout << "Constructeur par fichier" << std::endl;
    std::ifstream initFile(fileName);

    if (initFile) {
        double currentCoord;
        m_size = 0;
        while(initFile >> currentCoord) {
            m_size ++;
        }

        initFile.clear();
        initFile.seekg(0, std::ios::beg);

        if (m_size != 0) {   
            m_coords = new double[m_size];
            for (int i = 0; i < m_size; i++) {   
                initFile >> m_coords[i];
            }
        } else {
            m_coords = nullptr;
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

Dvector::~Dvector() {
    delete[] m_coords;
}
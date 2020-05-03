#include "Dvector.h"
#include <iostream>
#include <random>
#include <fstream>
#include <cstring>

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
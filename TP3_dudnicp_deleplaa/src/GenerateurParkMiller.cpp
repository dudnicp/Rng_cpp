#include "GenerateurParkMiller.h"
#include "GenerateurNombreAleatoire.h"
#include <iostream>

/**
 * \file GenerateurNombreAleatoire.cpp
 * \brief Générateur de nombres entiers aléatoires utilisant la méthode de Park-Miller
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

GenerateurParkMiller::GenerateurParkMiller(int dim) : GenerateurNombreAleatoire(dim)
{
    m_method = ParkMiller();
}

GenerateurParkMiller::~GenerateurParkMiller() {}

GenerateurParkMiller::GenerateurParkMiller(const GenerateurParkMiller &other) : GenerateurNombreAleatoire(other)
{
    m_method = ParkMiller(other.m_method);
}

GenerateurParkMiller &GenerateurParkMiller::operator=(const GenerateurParkMiller &other)
{
    if (this != &other)
    {
        m_dim = other.m_dim;
        m_method = other.m_method;
    }
    return *this;
}

void GenerateurParkMiller::clone(const GenerateurParkMiller &other)
{
    *this = other;
}

uint64_t GenerateurParkMiller::get_max() const
{
    return m_method.get_max();
}

uint64_t GenerateurParkMiller::get_seed() const
{
    return m_method.get_seed();
}

void GenerateurParkMiller::set_seed(const uint64_t seed)
{
    m_method.set_seed(seed);
}

void GenerateurParkMiller::reset_seed()
{
    m_method.set_seed(1);
}

uint64_t *GenerateurParkMiller::generate()
{
    uint64_t *ret = new uint64_t[m_dim];
    for (int i = 0; i < m_dim; i++)
    {
        ret[i] = m_method.generate();
    }
    return ret;
}
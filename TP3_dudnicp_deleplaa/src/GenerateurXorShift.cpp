#include "GenerateurXorShift.h"
#include <iostream>

/**
 * \file GenerateurXorShift.cpp
 * \brief Générateur de nombres entiers aléatoires utilisant la méthode de XorShift
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

GenerateurXorShift::GenerateurXorShift(int dim) : GenerateurNombreAleatoire(dim)
{
    m_method = XorShift();
}

GenerateurXorShift::~GenerateurXorShift() {}

GenerateurXorShift::GenerateurXorShift(const GenerateurXorShift &other) : GenerateurNombreAleatoire(other)
{
    m_method = XorShift(other.m_method);
}

GenerateurXorShift &GenerateurXorShift::operator=(const GenerateurXorShift &other)
{
    if (this != &other)
    {
        m_dim = other.m_dim;
        m_method = other.m_method;
    }
    return *this;
}

uint64_t GenerateurXorShift::get_max() const
{
    return m_method.get_max();
}

void GenerateurXorShift::clone(const GenerateurXorShift &other)
{
    *this = other;
}

uint64_t GenerateurXorShift::get_seed() const
{
    return m_method.get_seed();
}

void GenerateurXorShift::set_seed(const uint64_t seed)
{
    m_method.set_seed(seed);
}

void GenerateurXorShift::reset_seed()
{
    m_method.set_seed(1);
}

uint64_t *GenerateurXorShift::generate()
{
    uint64_t *ret = new uint64_t[m_dim];
    for (int i = 0; i < m_dim; i++)
    {
        ret[i] = m_method.generate();
    }
    return ret;
}
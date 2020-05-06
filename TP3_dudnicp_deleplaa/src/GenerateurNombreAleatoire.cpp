#include "GenerateurNombreAleatoire.h"

/**
 * \file GenerateurNombreAleatoire.cpp
 * \brief Générateur de nombres entiers aléatoires
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

GenerateurNombreAleatoire::GenerateurNombreAleatoire(int dim) : m_dim(dim) {}

GenerateurNombreAleatoire::~GenerateurNombreAleatoire() {}

GenerateurNombreAleatoire::GenerateurNombreAleatoire(const GenerateurNombreAleatoire &other) : m_dim(other.m_dim) {}

GenerateurNombreAleatoire &GenerateurNombreAleatoire::operator=(const GenerateurNombreAleatoire &other)
{
    if (this != &other)
    {
        m_dim = other.m_dim;
    }
    return *this;
}

void GenerateurNombreAleatoire::clone(const GenerateurNombreAleatoire &other)
{
    *this = other;
}

void GenerateurNombreAleatoire::set_dim(const int dim)
{
    m_dim = dim;
}

int GenerateurNombreAleatoire::get_dim() const
{
    return m_dim;
}
/**
 * \file GenerateurNombreAleatoire.cpp
 * \brief Corps des méthodes de la classe GenerateurANombreAleatoire
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#include "GenerateurNombreAleatoire.h"

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

double* GenerateurNombreAleatoire::generate_uniform() {
    uint64_t *temp = generate();
    double *ret = new double[m_dim];
    for (int i = 0; i < m_dim; i++)
    {
        ret[i] = (double) temp[i] / (double) get_max();
    }
    delete[] temp;
    return ret;
}
#include "GenerateurNombreAleatoire.h"

GenerateurNombreAleatoire::GenerateurNombreAleatoire(int dim) : m_dim(dim) {}

GenerateurNombreAleatoire::~GenerateurNombreAleatoire() {}

GenerateurNombreAleatoire::GenerateurNombreAleatoire(const GenerateurNombreAleatoire &other) : m_dim(other.m_dim) {}

GenerateurNombreAleatoire& GenerateurNombreAleatoire::operator=(const GenerateurNombreAleatoire &other) {
    if (this != &other)
    {
        m_dim = other.m_dim;
    }
    return *this;
}

void GenerateurNombreAleatoire::set_dim(const int dim) {
    m_dim = dim;
}

int GenerateurNombreAleatoire::get_dim() const {
    return m_dim;
}
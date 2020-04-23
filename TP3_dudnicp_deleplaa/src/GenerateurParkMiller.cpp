#include "GenerateurParkMiller.h"
#include "GenerateurNombreAleatoire.h"
#include <iostream>

GenerateurParkMiller::GenerateurParkMiller(int dim) : GenerateurNombreAleatoire(dim) {
    m_generator = ParkMiller();
}

GenerateurParkMiller::~GenerateurParkMiller() {}

GenerateurParkMiller::GenerateurParkMiller(const GenerateurParkMiller &other) : GenerateurNombreAleatoire(other) {
    m_generator = ParkMiller(other.m_generator);
}

GenerateurParkMiller& GenerateurParkMiller::operator=(const GenerateurParkMiller &other) {
    if (this != &other)
    {
        m_dim = other.m_dim;
        m_generator = other.m_generator;
    }
    return *this;
}

GenerateurParkMiller* GenerateurParkMiller::clone() {
    return new GenerateurParkMiller(*this);
}

unsigned long long GenerateurParkMiller::get_max() const {
    return m_generator.get_max();
}

unsigned long long GenerateurParkMiller::get_seed() const{
    return m_generator.get_seed();
}

void GenerateurParkMiller::set_seed(const unsigned long long seed) {
    try
    {
        m_generator.set_seed(seed);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void GenerateurParkMiller::reset_seed() {
    m_generator.set_seed(1);
}

unsigned long long* GenerateurParkMiller::generate() {
    unsigned long long* ret = new unsigned long long[m_dim];
    for (int i = 0; i < m_dim; i++)
    {
        ret[i] = m_generator.generate();
    }
}
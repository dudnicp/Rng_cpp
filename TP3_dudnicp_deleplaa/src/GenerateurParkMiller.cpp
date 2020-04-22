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

void GenerateurParkMiller::operator=(const GenerateurParkMiller &other) {
    m_dim = other.m_dim;
    m_generator = other.m_generator;
}

GenerateurParkMiller* GenerateurParkMiller::clone() {
    return new GenerateurParkMiller(*this);
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
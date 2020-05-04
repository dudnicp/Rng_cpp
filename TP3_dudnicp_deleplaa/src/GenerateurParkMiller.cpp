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

void GenerateurParkMiller::clone(const GenerateurParkMiller& other) {
    *this = other;
}

uint64_t GenerateurParkMiller::get_max() const {
    return m_generator.get_max();
}

uint64_t GenerateurParkMiller::get_seed() const{
    return m_generator.get_seed();
}

void GenerateurParkMiller::set_seed(const uint64_t seed) {
    m_generator.set_seed(seed);
}

void GenerateurParkMiller::reset_seed() {
    m_generator.set_seed(1);
}

uint64_t* GenerateurParkMiller::generate() {
    uint64_t* ret = new uint64_t[m_dim];
    for (int i = 0; i < m_dim; i++)
    {
        ret[i] = m_generator.generate();
    }
    return ret;
}
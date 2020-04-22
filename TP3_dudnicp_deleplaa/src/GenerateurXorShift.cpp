#include "GenerateurXorShift.h"
#include <iostream>

GenerateurXorShift::GenerateurXorShift(int dim) : GenerateurNombreAleatoire(dim) {
    m_generator = XorShift();
}

GenerateurXorShift::~GenerateurXorShift() {}

GenerateurXorShift::GenerateurXorShift(const GenerateurXorShift &other) : GenerateurNombreAleatoire(other) {
    m_generator = XorShift(other.m_generator);
}

void GenerateurXorShift::operator=(const GenerateurXorShift &other) {
    m_dim = other.m_dim;
    m_generator = other.m_generator;
}

GenerateurXorShift* GenerateurXorShift::clone() {
    return new GenerateurXorShift(*this);
}

unsigned long long GenerateurXorShift::get_seed() const{
    return m_generator.get_seed();
}

void GenerateurXorShift::set_seed(const unsigned long long seed) {
    m_generator.set_seed(seed);
}

void GenerateurXorShift::reset_seed() {
    m_generator.set_seed(1);
}
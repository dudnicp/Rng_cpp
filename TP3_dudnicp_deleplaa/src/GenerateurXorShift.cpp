#include "GenerateurXorShift.h"
#include <iostream>

GenerateurXorShift::GenerateurXorShift(int dim) : GenerateurNombreAleatoire(dim) {
    m_generator = XorShift();
}

GenerateurXorShift::~GenerateurXorShift() {}

GenerateurXorShift::GenerateurXorShift(const GenerateurXorShift &other) : GenerateurNombreAleatoire(other) {
    m_generator = XorShift(other.m_generator);
}

GenerateurXorShift& GenerateurXorShift::operator=(const GenerateurXorShift &other) {
    if (this != &other)
    {
        m_dim = other.m_dim;
        m_generator = other.m_generator;
    }
    return *this;
}

unsigned long long GenerateurXorShift::get_max() const {
    return m_generator.get_max();
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

unsigned long long* GenerateurXorShift::generate() {
    unsigned long long* ret = new unsigned long long[m_dim];
    for (int i = 0; i < m_dim; i++)
    {
        ret[i] = m_generator.generate();
    }
}
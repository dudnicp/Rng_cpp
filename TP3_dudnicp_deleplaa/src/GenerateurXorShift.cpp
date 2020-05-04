#include "GenerateurXorShift.h"
#include <iostream>

GenerateurXorShift::GenerateurXorShift(int dim) : GenerateurNombreAleatoire(dim)
{
    m_generator = XorShift();
}

GenerateurXorShift::~GenerateurXorShift() {}

GenerateurXorShift::GenerateurXorShift(const GenerateurXorShift &other) : GenerateurNombreAleatoire(other)
{
    m_generator = XorShift(other.m_generator);
}

GenerateurXorShift &GenerateurXorShift::operator=(const GenerateurXorShift &other)
{
    if (this != &other)
    {
        m_dim = other.m_dim;
        m_generator = other.m_generator;
    }
    return *this;
}

uint64_t GenerateurXorShift::get_max() const
{
    return m_generator.get_max();
}

void GenerateurXorShift::clone(const GenerateurXorShift &other)
{
    *this = other;
}

uint64_t GenerateurXorShift::get_seed() const
{
    return m_generator.get_seed();
}

void GenerateurXorShift::set_seed(const uint64_t seed)
{
    m_generator.set_seed(seed);
}

void GenerateurXorShift::reset_seed()
{
    m_generator.set_seed(1);
}

uint64_t *GenerateurXorShift::generate()
{
    uint64_t *ret = new uint64_t[m_dim];
    for (int i = 0; i < m_dim; i++)
    {
        ret[i] = m_generator.generate();
    }
    return ret;
}
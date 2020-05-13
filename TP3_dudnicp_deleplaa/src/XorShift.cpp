/**
 * \file XorShift.cpp
 * \brief Corps des méthodes de la classe XorShift
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#include "XorShift.h"

XorShift::XorShift() : m_seed(1) {}

XorShift::~XorShift() {}

XorShift::XorShift(const XorShift &other) : m_seed(other.m_seed) {}

XorShift& XorShift::operator=(const XorShift &other) {
    if (this != &other)
    {
        m_seed = other.m_seed;
    }
    return *this;
}

uint64_t XorShift::get_max() const {
    return UINT64_MAX;
}

uint64_t XorShift::get_seed() const {
    return m_seed;
}

void XorShift::set_seed(const uint64_t seed) {
    if (seed < 1)
    {
        throw std::invalid_argument("Graine invalide");
    }
    
    m_seed = seed;
}

uint64_t XorShift::generate() {
    m_seed ^= (m_seed << a1);
    m_seed ^= (m_seed >> a2);
    m_seed ^= (m_seed << a3);

    return m_seed;
}
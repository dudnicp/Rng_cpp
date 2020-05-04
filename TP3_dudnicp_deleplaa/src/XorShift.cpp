#include "XorShift.h"
#include <limits>

/**
 * \file XorShift.cpp
 * \brief Méthode XorShift pour la génération de nombres aléatoires
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

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
    return std::numeric_limits<uint64_t>::max();
}

uint64_t XorShift::get_seed() const {
    return m_seed;
}

void XorShift::set_seed(const uint64_t seed) {
    m_seed = seed;
}

uint64_t XorShift::generate() {
    m_seed = m_seed | (m_seed << a1);
    m_seed = m_seed | (m_seed >> a2);
    m_seed = m_seed | (m_seed << a3);

    return m_seed;
}
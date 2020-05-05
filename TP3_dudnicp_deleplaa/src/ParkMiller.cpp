#include "ParkMiller.h"
#include <cmath>

/**
 * \file ParkMiller.cpp
 * \brief Méthode de Park-Miller pour la génération de nombres aléatoires
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

ParkMiller::ParkMiller() : m_seed(1) {}

ParkMiller::~ParkMiller() {};

ParkMiller::ParkMiller(const ParkMiller &other) : m_seed(other.m_seed) {}

ParkMiller& ParkMiller::operator=(const ParkMiller &other) {
    if (this != &other)
    {
        m_seed = other.m_seed;
    }
    return *this;
}

uint64_t ParkMiller::get_max() const {
    return m;
}

void ParkMiller::set_seed(uint64_t seed) {
    uint64_t gcd = seed;
    uint64_t temp_m = m;
    uint64_t temp;
    while (temp_m != 0) {
        temp = temp_m;
        temp_m = gcd % temp_m;
        gcd = temp;
    }

    if (gcd == 1) {
        m_seed = seed;
    } else {
        throw std::invalid_argument("Graine invalide");
    }  
}

uint64_t ParkMiller::get_seed() const {
    return m_seed;
}

uint64_t ParkMiller::generate() {
    m_seed = (a * (m_seed - (uint64_t)floor(m_seed/q) * q) - r * (uint64_t)floor(m_seed/q)) % m;
    return m_seed;
}
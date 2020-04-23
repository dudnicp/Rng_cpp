#include "ParkMiller.h"
#include <cmath>

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

unsigned long long ParkMiller::get_max() const {
    return m;
}

void ParkMiller::set_seed(unsigned long long seed) {
    unsigned long long gcd = seed;
    unsigned long long temp_m = m;
    unsigned long long temp;
    while (temp_m != 0) {
        temp = temp_m;
        temp_m = gcd % temp_m;
        gcd = temp;
    }

    if (gcd == 1) {
        m_seed = seed;
    } else {
        throw InvalidSeed();
    }  
}

unsigned long long ParkMiller::get_seed() const {
    return m_seed;
}

unsigned long long ParkMiller::generate() {
    m_seed = (a * (m_seed - (long)floor(m_seed/q) * q) - r * (long)floor(m_seed/q)) % m;
    return m_seed;
}
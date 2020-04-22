#include "ParkMiller.h"
#include <cmath>
#include <algorithm>

ParkMiller::ParkMiller() : m_seed(1) {}

ParkMiller::~ParkMiller() {};

ParkMiller::ParkMiller(const ParkMiller &other) : m_seed(other.m_seed) {}

void ParkMiller::operator=(const ParkMiller &other) {
    m_seed = other.m_seed;
}

void ParkMiller::set_seed(unsigned int seed) {
    if (std::__gcd(m, (int) seed) == 1)
    {
        m_seed = seed;
    } else {
        throw InvalidSeed();
    }
    
}

unsigned int ParkMiller::get_seed() const {
    return m_seed;
}

unsigned int ParkMiller::generate() {

    m_seed = (a * (m_seed - (long)floor(m_seed/q) * q) - r * (long)floor(m_seed/q)) % m;
    return m_seed;
}
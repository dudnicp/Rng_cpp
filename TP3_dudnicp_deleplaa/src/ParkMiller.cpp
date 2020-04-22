#include "ParkMiller.h"
#include <cmath>

ParkMiller::ParkMiller() : m_seed(1) {}

ParkMiller::~ParkMiller() {};

ParkMiller::ParkMiller(const ParkMiller &other) : m_seed(other.m_seed) {}

void ParkMiller::operator=(const ParkMiller &other) {
    m_seed = other.m_seed;
}

unsigned long ParkMiller::get_seed() const {
    return m_seed;
}

unsigned long ParkMiller::generate() {

    m_seed = (a * (m_seed - (long)floor(m_seed/q) * q) - r * (long)floor(m_seed/q)) % m;
    return m_seed;
}
#include "ParkMiller.h"

ParkMiller::ParkMiller() : m_seed(0) {}

ParkMiller::~ParkMiller() {};

ParkMiller::ParkMiller(const int seed) : m_seed(seed) {}

ParkMiller::ParkMiller(const ParkMiller &other) : m_seed(other.m_seed) {}

void ParkMiller::operator=(const ParkMiller &other) {
    m_seed = other.m_seed;
}

void ParkMiller::set_seed(const int seed) {
    m_seed = seed;
}

int ParkMiller::get_seed() const {
    return m_seed;
}

int ParkMiller::generate() const {
    
    
    
    
    return 0;
}
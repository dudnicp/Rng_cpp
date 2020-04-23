#include "XorShift.h"
#include <limits>

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

unsigned long long XorShift::get_max() const {
    return std::numeric_limits<unsigned long long>::max();
}

unsigned long long XorShift::get_seed() const {
    return m_seed;
}

void XorShift::set_seed(const unsigned long long seed) {
    m_seed = seed;
}

unsigned long long XorShift::generate() {
    m_seed = m_seed | (m_seed << a1);
    m_seed = m_seed | (m_seed >> a2);
    m_seed = m_seed | (m_seed << a3);

    return m_seed;
}
#include "XorShift.h"

XorShift::XorShift() : m_seed(1) {}

XorShift::~XorShift() {}

XorShift::XorShift(const XorShift &other) : m_seed(other.m_seed) {}

void XorShift::operator=(const XorShift &other) {
    m_seed = other.m_seed;
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
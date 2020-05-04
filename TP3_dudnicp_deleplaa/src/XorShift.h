#ifndef XORSHIFT_H
#define XORSHIFT_H

#include <cstdint>

class XorShift
{
private:
    uint64_t m_seed;
    const uint64_t a1 = 17;
    const uint64_t a2 = 31;
    const uint64_t a3 = 8;
public:
    XorShift();
    ~XorShift();
    XorShift(const XorShift &other);
    XorShift& operator=(const XorShift &other);

    uint64_t generate();

    uint64_t get_max() const;

    void set_seed(const uint64_t seed);
    uint64_t get_seed() const;
};

#endif
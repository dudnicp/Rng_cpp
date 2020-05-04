#ifndef PARKMILLER_H
#define PARKMILLER_H

#include <cstdint>

class ParkMiller
{
private:
    uint64_t m_seed;
    const uint64_t a = 16807;
    const uint64_t m = 2147483647;
    const uint64_t q = 127773;
    const uint64_t r = 2836;
public:
    ParkMiller();
    ~ParkMiller();
    ParkMiller(const ParkMiller &other);
    ParkMiller& operator=(const ParkMiller &other);
    
    uint64_t generate();

    uint64_t get_max() const;

    void set_seed(const uint64_t seed);
    uint64_t get_seed() const;
};

#endif
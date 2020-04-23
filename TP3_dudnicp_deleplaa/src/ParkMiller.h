#include "InvalidSeed.h"


class ParkMiller
{
private:
    unsigned long long m_seed;
    const unsigned long long a = 16807;
    const unsigned long long m = 2147483647;
    const unsigned long long q = 127773;
    const unsigned long long r = 2836;
public:
    ParkMiller();
    ~ParkMiller();
    ParkMiller(const ParkMiller &other);
    ParkMiller& operator=(const ParkMiller &other);
    
    unsigned long long generate();

    unsigned long long get_max() const;

    void set_seed(const unsigned long long seed);
    unsigned long long get_seed() const;
};



#include "InvalidSeed.h"


class ParkMiller
{
private:
    unsigned int m_seed;
    const int a = 16807;
    const int m = 2147483647;
    const int q = 127773;
    const int r = 2836;
public:
    ParkMiller();
    ~ParkMiller();
    ParkMiller(const ParkMiller &other);
    void operator=(const ParkMiller &other);
    unsigned int generate();

    void set_seed(const unsigned int seed);
    unsigned int get_seed() const;
};



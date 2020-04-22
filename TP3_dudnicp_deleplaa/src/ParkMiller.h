class ParkMiller
{
private:
    unsigned long m_seed;
    const long a = 16807;
    const long m = 2147483647;
    const long q = 127773;
    const long r = 2836;
public:
    ParkMiller();
    ~ParkMiller();
    ParkMiller(const ParkMiller &other);
    void operator=(const ParkMiller &other);
    unsigned long generate();

    unsigned long get_seed() const;
};



class ParkMiller
{
private:
    int m_seed;
public:
    ParkMiller();
    ~ParkMiller();
    ParkMiller(int seed);
    ParkMiller(const ParkMiller &other);
    void operator=(const ParkMiller &other);
    int generate() const;

    void set_seed(int seed);
    int get_seed() const;
};



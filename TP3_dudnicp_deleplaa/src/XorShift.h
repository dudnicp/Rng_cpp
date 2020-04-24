class XorShift
{
private:
    unsigned long long m_seed;
    const long long a1 = 17;
    const long long a2 = 31;
    const long long a3 = 8;
public:
    XorShift();
    ~XorShift();
    XorShift(const XorShift &other);
    XorShift& operator=(const XorShift &other);

    unsigned long long generate();

    unsigned long long get_max() const;

    void set_seed(const unsigned long long seed);
    unsigned long long get_seed() const;
};

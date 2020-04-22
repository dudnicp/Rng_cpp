class XorShift
{
private:
    unsigned long m_seed;
    const long a1 = 17;
    const long a2 = 31;
    const long a3 = 8;
public:
    XorShift();
    ~XorShift();
    XorShift(const XorShift &other);
    void operator=(const XorShift &other);

    unsigned long generate();

    void set_seed(const unsigned long seed);
    unsigned long get_seed() const;
};

#include "GenerateurNombreAleatoire.h"
#include "XorShift.h"

class GenerateurXorShift : public GenerateurNombreAleatoire
{
private:
    XorShift m_generator;
public:
    GenerateurXorShift(int dim);
    ~GenerateurXorShift();
    GenerateurXorShift(const GenerateurXorShift &other);
    void operator=(const GenerateurXorShift &other);

    virtual GenerateurXorShift* clone();

    virtual void set_seed(const unsigned long long seed);
    virtual unsigned long long get_seed() const;
    virtual void reset_seed();

    virtual unsigned long long* generate();
};


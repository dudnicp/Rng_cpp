#ifndef GENERATEURXORSHIFT_H
#define GENERATEURXORSHIFT_H

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
    GenerateurXorShift& operator=(const GenerateurXorShift &other);

    void clone(const GenerateurXorShift &other);

    virtual uint64_t get_max() const;
    virtual void set_seed(const uint64_t seed);
    virtual uint64_t get_seed() const;
    virtual void reset_seed();

    virtual uint64_t* generate();
};

#endif

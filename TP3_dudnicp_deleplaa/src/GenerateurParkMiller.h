#ifndef GENERATEURPARKMILLER_H
#define GENERATEURPARKMILLER_H

#include "GenerateurNombreAleatoire.h"
#include "ParkMiller.h"

class GenerateurParkMiller : public GenerateurNombreAleatoire
{
private:
    ParkMiller m_generator;
public:
    GenerateurParkMiller(int dim);
    ~GenerateurParkMiller();
    GenerateurParkMiller(const GenerateurParkMiller &other);
    GenerateurParkMiller& operator=(const GenerateurParkMiller &other);

    virtual uint64_t get_max() const;

    virtual GenerateurParkMiller* clone();

    virtual void set_seed(const uint64_t seed);
    virtual uint64_t get_seed() const;
    virtual void reset_seed();

    virtual uint64_t* generate();
};

#endif
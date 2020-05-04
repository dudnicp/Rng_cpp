#ifndef GENERATEURNOMBREALEATOIRE_H
#define GENERATEURNOMBREALEATOIRE_H

#include <cstdint>

class GenerateurNombreAleatoire
{
protected:
    int m_dim;

public:
    GenerateurNombreAleatoire(const int dim);
    virtual ~GenerateurNombreAleatoire();
    GenerateurNombreAleatoire(const GenerateurNombreAleatoire &other);
    GenerateurNombreAleatoire& operator=(const GenerateurNombreAleatoire &other);

    void set_dim(const int dim);
    int get_dim() const;

    void clone(const GenerateurNombreAleatoire &other);

    virtual uint64_t get_max() const = 0;
    virtual void set_seed(const uint64_t seed) = 0;
    virtual uint64_t get_seed() const = 0;
    virtual void reset_seed() = 0;

    virtual uint64_t* generate() = 0;
};

#endif
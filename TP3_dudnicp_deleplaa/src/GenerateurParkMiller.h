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

    virtual unsigned long long get_max() const;

    virtual GenerateurParkMiller* clone();

    virtual void set_seed(const unsigned long long seed);
    virtual unsigned long long get_seed() const;
    virtual void reset_seed();

    virtual unsigned long long* generate();
};
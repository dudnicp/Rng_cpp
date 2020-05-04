#ifndef GENERATEURXORSHIFT_H
#define GENERATEURXORSHIFT_H

#include "GenerateurNombreAleatoire.h"
#include "XorShift.h"

/**
 * \file GenerateurXorShift.h
 * \brief Générateur de nombres entiers aléatoires utilisant la méthode de XorShift
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

/**
 * \class GenerateurXorShift
 * \brief Générateur de nombres entiers aléatoires utilisant la méthode de XorShift
 */
class GenerateurXorShift : public GenerateurNombreAleatoire
{
private:
    XorShift m_method; ///< Méthode utilisée pour générer les nombres aléatoires
public:

    /**
     * \brief Crée un générateur aléatoire de la taille spécifiée utilisant la méthode XorShift
     * \param[in] dim La taille du générateur
     * \throw invalid_argument Si la dimension spécifiée est < 1
     */
    GenerateurXorShift(int dim);

    /**
     * \brief Detruit le générateur aléatoire libérant la mémoire
     */
    ~GenerateurXorShift();

    /**
     * \brief Crée un générateur aléatoire identique au générateur spécifié utilisant la méthode de XorShift
     * \param[in] other Le générateur à recopier
     */
    GenerateurXorShift(const GenerateurXorShift &other);

    /**
     * \brief Modifie ce générateur en recopiant les valeurs du générateur spécifié utilisant la méthode de XorShift
     * \param[in] other Le générateur à recopier
     * \return Une référence sur ce générateur (après recopie)
     */
    GenerateurXorShift& operator=(const GenerateurXorShift &other);


    /**
     * \brief Identique à \see operator=
     */
    void clone(const GenerateurXorShift &other);

    virtual uint64_t get_max() const;
    virtual void set_seed(const uint64_t seed);
    virtual uint64_t get_seed() const;
    virtual void reset_seed();

    virtual uint64_t* generate();
};

#endif

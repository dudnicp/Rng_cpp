#ifndef GENERATEURPARKMILLER_H
#define GENERATEURPARKMILLER_H

#include "GenerateurNombreAleatoire.h"
#include "ParkMiller.h"

/**
 * \file GenerateurParkMiller.h
 * \brief Générateur de nombres entiers aléatoires utilisant la méthode de Park-Miller
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

/**
 * \class GenerateurParkMiller
 * \brief Générateur de nombres entiers aléatoires utilisant la méthode de Park-Miller
 */
class GenerateurParkMiller : public GenerateurNombreAleatoire
{
private:
    ParkMiller m_method; ///< Méthode utilisée pour générer les nombres aléatoires
public:

    /**
     * \brief Crée un générateur aléatoire de la taille spécifiée utilisant la méthode de Park-Miller
     * \param[in] dim La taille du générateur
     * \throw invalid_argument Si la dimension spécifiée est < 1
     */
    GenerateurParkMiller(int dim);

    /**
     * \brief Detruit le générateur aléatoire libérant la mémoire
     */
    ~GenerateurParkMiller();

    /**
     * \brief Crée un générateur aléatoire identique au générateur spécifié utilisant la méthode de Park-Miller
     * \param[in] other Le générateur à recopier
     */
    GenerateurParkMiller(const GenerateurParkMiller &other);

    /**
     * \brief Modifie ce générateur en recopiant les valeurs du générateur spécifié utilisant la méthode de Park-Miller
     * \param[in] other Le générateur à recopier
     * \return Une référence sur ce générateur (après recopie)
     */
    GenerateurParkMiller& operator=(const GenerateurParkMiller &other);

    /**
     * \brief Identique à \see operator=
     */
    void clone(const GenerateurParkMiller &other);

    virtual uint64_t get_max() const;
    virtual void set_seed(const uint64_t seed);
    virtual uint64_t get_seed() const;
    virtual void reset_seed();

    virtual uint64_t* generate();
};

#endif
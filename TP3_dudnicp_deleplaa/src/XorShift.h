#ifndef XORSHIFT_H
#define XORSHIFT_H

#include <iostream>


/**
 * \file XorShift.h
 * \brief Méthode XorShift pour la génération de nombres aléatoires
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

/**
 * \class XorShift
 * \brief Méthode XorShift pour la génération de nombres aléatoires
 */
class XorShift
{
private:
    uint64_t m_seed; ///< Graine de la méthode
    const uint64_t a1 = 17; ///< Un parametre de la méthode
    const uint64_t a2 = 31; ///< Un parametre de la méthode
    const uint64_t a3 = 8; ///< Un parametre de la méthode
public:

    /**
     * \brief Initialise une méthode XorShift avec une graine égale à 1
     */
    XorShift();

    /**
     * \brief Detruit la méthode en libérant la mémoire
     */
    ~XorShift();

    /**
     * \brief Initialise une méthode XorShift identique à celle spécifiée
     * \param[in] other La méthode à recopier
     */
    XorShift(const XorShift &other);

    /**
     * \brief Modifie cette méthode en recopiant les valeurs de la méthode spécifiée
     * \param[in] other La méthode à recopier
     */
    XorShift& operator=(const XorShift &other);

    /**
     * \brief Modifie la graine et retourne la nouvelle graine
     * \return La nouvelle graine
     */
    uint64_t generate();

    /**
     * \brief Renvoie la plus grande graine possible de la méthode
     * \return La plus grande graine possible de la méthode
     */
    uint64_t get_max() const;

    /**
     * \brief Modifie la graine de la méthode
     * \param[in] seed La nouvelle graine de la méthode
     * \throw invalid_argument Si la graine spécifiée est < 1
     */
    void set_seed(const uint64_t seed);

    /**
     * \brief Accesseur de la graine de la méthode
     * \return La graine de la méthode
     */
    uint64_t get_seed() const;
};

#endif
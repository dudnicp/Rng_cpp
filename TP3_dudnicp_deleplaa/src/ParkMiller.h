#ifndef PARKMILLER_H
#define PARKMILLER_H

#include <iostream>

/**
 * \file ParkMiller.h
 * \brief Méthode de Park-Miller pour la génération de nombres aléatoires
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

/**
 * \class ParkMiller
 * \brief Méthode de Park-Miller pour la génération de nombres aléatoires
 */
class ParkMiller
{
private:
    uint64_t m_seed; ///< Graine de la méthode
    const uint64_t a = 16807; ///< Un parametre de la méthode
    const uint64_t m = INT32_MAX; ///< Un parametre de la méthode
    const uint64_t q = 127773; ///< Un parametre de la méthode
    const uint64_t r = 2836; ///< Un parametre de la méthode

public:

    /**
     * \brief Initialise une méthode de Park-Miller avec une graine égale à 1
     */
    ParkMiller();

    /**
     * \brief Detruit la méthode en libérant la mémoire
     */
    ~ParkMiller();

    /**
     * \brief Initialise une méthode de Park-Miller identique à celle spécifiée
     * \param[in] other La méthode à recopier
     */
    ParkMiller(const ParkMiller &other);

    /**
     * \brief Modifie cette méthode en recopiant les valeurs de la méthode spécifiée
     * \param[in] other La méthode à recopier
     */
    ParkMiller& operator=(const ParkMiller &other);
    
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
     * \throw invalid_argument Si la graine spécifiée est < 1 ou >= m 
     * \see m
     */
    void set_seed(const uint64_t seed);

    /**
     * \brief Accesseur de la graine de la méthode
     * \return La graine de la méthode
     */
    uint64_t get_seed() const;
};

#endif
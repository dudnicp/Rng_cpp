/**
 * \file Distribution.h
 * \brief Prototypes de la classe Disitribution
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include "GenerateurNombreAleatoire.h"

/**
 * \class Distribution
 * \brief Variable aléatoires suivant une distribution particulière
 */
class Distribution
{
public:
    Distribution() = default;
    virtual ~Distribution() = default;
    Distribution(const Distribution &other) = default;
    Distribution& operator=(const Distribution &other) = default;

    /**
     * \brief Effectue un tirage aléatoire suivant cette distribution
     * \param[in] generator Le générateur à partir duquel effectuer le tirage aléatoire
     * \return Un tableau de valeurs aléatoires suivants cette distribution, de la taille du générateur spécifié
     */
    virtual double* random_draws(GenerateurNombreAleatoire &generator) const = 0;

    /**
     * \brief Moyenne de la distribution
     * \return La moyenne de la distribution
     */
    virtual double mean() const = 0;

    /**
     * \brief Variance de la distribution
     * \return La variance de la distribution
     */
    virtual double var() const = 0;

    /**
     * \brief Écart type de la distribution
     * \return L'écart type de la distribution
     */
    virtual double stdev() const = 0;

    /** 
     * \brief Fonction de répartition de la distribution
     * \param[in] x Un réel
     * \return La valeur de la fonction de répartition de la distribution au point x
     */
    virtual double cdf(const double x) const = 0;

    /** 
     * \brief Inverse de la fonction de répartition de la distribution
     * \param[in] x Un réel
     * \return La valeur de l'inverse de la fonction de répartition de la distribution au point x
     * \throw domain_error Si x <= 0 ou x => 1
     */
    virtual double inv_cdf(const double x) const = 0;

    /** 
     * \brief Densité de probabilité de la distribution
     * \param[in] x Un réel
     * \return La densité de probabilité de la distribution au point x
     */
    virtual double pdf(const double x) const = 0;
};

#endif

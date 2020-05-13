/**
 * \file DistributionNormale.h
 * \brief Prototypes de la classe DistributionNormale
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#ifndef DISTRIBUTIONNORMALE_H
#define DISTRIBUTIONNORMALE_H

#include "Distribution.h"
#include <cmath>

/**
 * \class DistributionNormale
 * \brief Variable aléatoire suivant une distribution normale
 */
class DistributionNormale : public Distribution
{
private:
    double m_mean; ///< Moyenne de la distribution
    double m_stdev; ///< Écart type de la distribution
    
public:
    static constexpr double TWO_PI = 2.0 * M_PI;

    /**
     * \brief Construit une distribution normale de moyenne 0, d'écart type 1
     */
    DistributionNormale();

    /**
     * \brief Construit une distribution normale de moyenne et écart type spécifiés
     * \param[in] mean La moyenne de la distribution
     * \param[in] stdev Écart type de la distribution
     */
    DistributionNormale(const double mean, const double stdev);

    /**
     * \brief Detruit la distribution, libérant la mémoire
     */
    ~DistributionNormale();

    /**
     * \brief Construit une distribution normale identique à celle spécifiée
     * \param[in] other La distribution normale à recopier
     */
    DistributionNormale(const DistributionNormale &other);

    /**
     * \brief Modifie cette distribution en recopiant les valeurs de la distribution spécifiée
     * \param[in] other La distribution normale à recopier
     * \return Une référence sur cette distribution (après recopie)
     */
    DistributionNormale& operator=(const DistributionNormale &other);

    virtual double* random_draws(GenerateurNombreAleatoire &generator) const;

    virtual double mean() const;
    virtual double var() const;
    virtual double stdev() const;
    virtual double cdf(const double x) const;
    virtual double inv_cdf(const double x) const;
    virtual double pdf(const double x) const;
};

#endif


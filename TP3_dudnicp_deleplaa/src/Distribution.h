#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include "GenerateurNombreAleatoire.h"


class Distribution
{
public:
    Distribution() = default;
    virtual ~Distribution() = default;
    Distribution(const Distribution &other) = default;
    Distribution& operator=(const Distribution &other) = default;

    virtual double* random_draws(GenerateurNombreAleatoire &generator) const = 0;

    virtual double mean() const = 0;
    virtual double var() const = 0;
    virtual double stdev() const = 0;
    virtual double cdf(const double x) const = 0;
    virtual double inv_cdf(const double x) const = 0;
    virtual double pdf(const double x) const = 0;
};

#endif

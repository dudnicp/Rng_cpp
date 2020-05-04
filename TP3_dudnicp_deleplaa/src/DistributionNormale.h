#ifndef DISTRIBUTIONNORMALE_H
#define DISTRIBUTIONNORMALE_H

#include "Distribution.h"
#include <cmath>

class DistributionNormale : public Distribution
{
private:
    double m_mean;
    double m_stdev;
    
public:
    static const double TWO_PI = 2.0 * M_PI;


    DistributionNormale();
    DistributionNormale(const double mean, const double stdev);
    ~DistributionNormale();
    DistributionNormale(const DistributionNormale &other);
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


/**
 * \file DistributionNormale.cpp
 * \brief Corps des fonctions de la classe DistributionNormale
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#include "DistributionNormale.h"
#include <cmath>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>

DistributionNormale::DistributionNormale() : m_mean(0.), m_stdev(1.) {}

DistributionNormale::DistributionNormale(const double mean, const double stdev) : m_mean(mean), m_stdev(stdev) {}

DistributionNormale::~DistributionNormale() {}

DistributionNormale::DistributionNormale(const DistributionNormale &other) : m_mean(other.m_mean), m_stdev(other.m_stdev) {}

DistributionNormale &DistributionNormale::operator=(const DistributionNormale &other)
{
    if (this != &other)
    {
        m_mean = other.m_mean;
        m_stdev = other.m_stdev;
    }
    return *this;
}

double *DistributionNormale::random_draws(GenerateurNombreAleatoire &generator) const
{
    // Transformation de Box-Muller

    uint64_t *X = generator.generate();
    uint64_t *Y = generator.generate();

    const int dim = generator.get_dim();

    double *ret = new double[dim];

    for (int i = 0; i < dim; i++)
    {
        double x = X[i] * (1. / generator.get_max());
        double y = Y[i] * (1. / generator.get_max());
        ret[i] = sqrt(-2.0 * log(x)) * cos(TWO_PI * y);

        ret[i] = ret[i] * m_stdev + m_mean;
    }

    return ret;
}

double DistributionNormale::mean() const
{
    return m_mean;
}

double DistributionNormale::stdev() const
{
    return m_stdev;
}

double DistributionNormale::var() const
{
    return m_stdev * m_stdev;
}

double DistributionNormale::cdf(const double x) const
{
    double temp = erf((x - m_mean) / (m_stdev * sqrt(2.)));
    return (1. + temp) / 2.;
}

double DistributionNormale::pdf(const double x) const
{
    double temp = -pow((x - m_mean) / m_stdev, 2) / 2.;
    return exp(temp) / (m_stdev * sqrt(TWO_PI));
}

double DistributionNormale::inv_cdf(const double x) const
{
    if (x <= 0 || x >= 1)
    {
        std::stringstream error;
        error << "inv_cdf définie sur ]0, 1[, argument recu : " << x;
        throw std::domain_error(error.str());
    }

    double z = 2. * x - 1.;

    // calcul des 1000 premiers termes de la suite
    int n = 1000;
    double inv_erf = 0;
    double c[n] = {0};
    c[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            c[i] += c[j] * c[i - 1 - j] / ((j + 1) * (2 * j + 1));
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        inv_erf += c[i] / (2. * i + 1) * pow(sqrt(M_PI) / 2. * z, 2 * i + 1);
    }

    return m_stdev * M_SQRT2 * inv_erf + m_mean;
}

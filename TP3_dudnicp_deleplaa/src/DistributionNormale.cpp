#include "DistributionNormale.h"
#include <cmath>

DistributionNormale::DistributionNormale() : m_mean(0.), m_stdev(1.) {}

DistributionNormale::DistributionNormale(const double mean, const double stdev) : m_mean(mean), m_stdev(stdev) {}

DistributionNormale::~DistributionNormale() {}

DistributionNormale::DistributionNormale(const DistributionNormale &other) : m_mean(other.m_mean), m_stdev(other.m_stdev) {}

DistributionNormale& DistributionNormale::operator=(const DistributionNormale &other) {
    if (this != &other)
    {   
        m_mean = other.m_mean;
        m_stdev = other.m_stdev;
    }
    return *this;
}

double* DistributionNormale::random_draws(GenerateurNombreAleatoire &generator) const {
    unsigned long long* X = generator.generate();
    unsigned long long* Y = generator.generate();

    const int dim = generator.get_dim();
    
    double* ret = new double[dim];
    
    for (int i = 0; i < dim; i++)
    {   
        double x = X[i] * (1. / generator.get_max());
        double y = Y[i] * (1. / generator.get_max());
        ret[i] = sqrt(-2.0 * log(x)) * cos(TWO_PI * y);

        ret[i] = ret[i] * m_stdev + m_mean;
    }

    return ret;
}

double DistributionNormale::mean() const {
    return m_mean;
}

double DistributionNormale::stdev() const {
    return m_stdev;
}

double DistributionNormale::mean() const {
    return m_stdev*m_stdev;
}

double DistributionNormale::cdf(const double x) const {
    double temp = erf((x - m_mean) / (m_stdev * sqrt(2.)));
    return (1. + temp) / 2.;
}

double DistributionNormale::pdf(const double x) const {
    double temp = -pow((x - m_mean)/m_stdev, 2) / 2.;
    return exp(temp) / (m_stdev * sqrt(TWO_PI));
}

double DistributionNormale::inv_cdf(const double x) const {
    double left = 0.;
    double right = 1.;
    double error = 0.0001;
    double temp = 0;
    while (right - left > error)
    {
        temp = (left + right) / 2.;
        double y = cdf(temp);
        if (y > x) {
            right = temp;
        } else if (y < x) {
            left = temp;
        } else {
            break;
        }
    }
    return temp;
}


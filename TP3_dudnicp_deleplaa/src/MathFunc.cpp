#include "MathFunc.h"
#include <iostream>
#include <cmath>
#include <sstream>

/**
 * \file MathFunc.cpp
 * \brief Fonctions mathématiques
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

double mean(const double *data, const int n)
{
    double ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += data[i];
    }

    return ret / n;
}

int factorial(const int n)
{
    if (n < 0)
    {
        throw std::domain_error("Impossible d'appeller la fonction factorial sur des entiers négatifs");
    }

    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return factorial(n - 1) * n;
    }
}

double G(const double x)
{
    int temp = 2 * x;
    if (temp != 2 * x || temp <= 0) // Verification 2*x est strictement positif
    {
        std::stringstream str;
        str << "Impossible d'appeler G pour x = " << x;
        throw std::domain_error(str.str());
    }

    switch (temp)
    {
    case 1:
        return sqrt(M_PI);
        break;
    case 2:
        return 1;
        break;
    default:
        return (x - 1) * G(x - 1);
        break;
    }
}

double chi2Pdf(const double x, const int df)
{
    if (x < 0 || df < 1)
    {
        std::stringstream str;
        str << "Impossible de calculer chi2Pdf pour x = " << x << " et df = " << df;
        throw std::domain_error(str.str());
    }

    return pow(x / 2., (df - 2) / 2.) * exp(-x / 2.) / (2 * G(df / 2.));
}

double chi2Cdf(const double x, const int df)
{
    if (x < 0 || df < 1)
    {
        std::stringstream str;
        str << "Impossible de calculer chi2Cdf pour x = " << x << " et df = " << df;
        throw std::domain_error(str.str());
    }

    switch (df)
    {
    case 1:
        return erf(sqrt(x / 2.));
        break;
    case 2:
        return 1. - exp(-x / 2.);
        break;
    default:
        return chi2Cdf(x, df - 2) - 2 * chi2Pdf(x, df);
        break;
    }
}

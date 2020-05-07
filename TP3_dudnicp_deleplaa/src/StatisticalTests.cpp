#include "StatisticalTests.h"
#include "DistributionNormale.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

// Test de H_null : data suit une loi uniforme sur [0, 1] avec le test de Kolmogorov-Smirnov
// On suppose n >> 100 pour avoir des tests aussi précis que possible
void uniformFrequencyKSTest(const double *data, const size_t n)
{
    // copie des données
    double cpy[n];
    memcpy(cpy, data, n);

    // tri des données
    std::sort(cpy, cpy + n);

    // calcul de D+
    double Dplus = 1. / n - cpy[0];
    double current;
    for (size_t i = 1; i < n; i++)
    {
        current = (i + 1.) / n - cpy[i];
        if (current > Dplus)
        {
            Dplus = current;
        }
    }

    // calcul de D-
    double Dminus = cpy[0];
    for (size_t i = 1; i < n; i++)
    {
        current = cpy[i] - ((double)i) / n;
        if (current > Dminus)
        {
            Dminus = current;
        }
    }

    // D = max(D+, D-)
    double D = (Dplus > Dminus) ? Dplus : Dminus;
    double D_alpha = 1.36 / sqrt(n - 1);

    std::cout << "D obtenu : " << D << std::endl;
    std::cout << "D_alpha toléré pour alpha = 0.05 : " << D_alpha << std::endl;

    // Hypothèse H_null (data ~ U[0,1]) rejetée si D > D_alpha
    if (D > D_alpha)
    {
        exit(EXIT_FAILURE);
    }
}

// Test du Chi2
void chiSquaredTest(const double *obtained, const double *expected, const size_t n)
{
    // Calcul du chi2 obtenu
    double chi2 = 0;
    for (size_t i = 0; i < n; i++)
    {
        chi2 += pow(obtained[i] - expected[i], 2) / expected[i];
    }
    double chi2_alpha;
    switch (n)
    {
    case 99:
        chi2_alpha = 123.25;
        break;
    default:
        throw std::invalid_argument("Degré de liberté non traité");
        break;
    }

    std::cout << "Chi2 obtenu : " << chi2 << std::endl;
    std::cout << "Chi2 toléré pour alpha = 0.05 : " << chi2_alpha << std::endl;

    // Hypothèse H_null rejetée si chi2 > chi2_alpha
    if (chi2 > chi2_alpha)
    {
        exit(EXIT_FAILURE);
    }
}

// Test de H_null : data suit une loi uniforme sur [0, 1] avec le test du Chi2
// On suppose n >> 100 pour avoir des tests aussi précis que possible
void uniformFrequencyChiSquaredTest(const double *data, size_t n)
{
    size_t nClasses = 100;
    double obtained[nClasses] = {0};
    double expected[nClasses];

    for (size_t i = 0; i < nClasses; i++)
    {
        expected[i] = ((double)n) / nClasses;

    }

    // calculs des fréquences obtenues
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < nClasses; j++)
        {
            if (data[i] < ((double)(j + 1)) / n)
            {
                obtained[j]++;
                break;
            }
        }
    }

    chiSquaredTest(obtained, expected, nClasses - 1);
}

// Test de H_null : data suit une loi normale N(0,1 avec le test du Chi2
// On suppose n >> 100 pour avoir des tests aussi précis que possible
void normalFrequencyChiSquaredTest(const double *data, size_t n)
{
    size_t nClasses = 100;
    double obtained[nClasses] = {0};
    double expected[nClasses];
    double inv_cdf[nClasses];

    DistributionNormale stdNormal;

    for (size_t i = 0; i < nClasses; i++)
    {
        expected[i] = ((double)n) / nClasses;
        inv_cdf[i] = stdNormal.inv_cdf(expected[i]);
    }

    // calculs des fréquences obtenues
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < nClasses; j++)
        {
            if (data[i] < inv_cdf[j])
            {
                obtained[j]++;
                break;
            }
        }
    }

    chiSquaredTest(obtained, expected, nClasses - 1);
}

// Test de H_null : nombres générées aléatoirement sont indépendants
// On suppose n >> 100 pour avoir des tests aussi précis que possible
void autocorrelationTest(const double *data, const size_t n)
{
    std::vector<double> obtainedZ;

    // i et m < 10 car M doit etre >> 1 pour obtenir une distribution normale
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t m = i + 1; m < 10; m++)
        {
            // calcul de M
            int M = 0;
            while (i + (M + 2) * m <= n)
            {
                M++;
            }

            // calcul rho
            double rho = 0.;
            for (size_t k = 0; k < (unsigned) (M + 1); k++)
            {
                rho += data[i + k * m] * data[(k + 1) * m];
            }
            rho /= (M + 1);
            rho -= 0.25;

            // calcul sigma
            double sigma = sqrt(13. * M + 7.) / (12. * (M + 1.));

            double z = rho / sigma;
            obtainedZ.push_back(z);
        }
    }

    double maxZ = *(std::max_element(obtainedZ.begin(), obtainedZ.end()));
    double Z_alpha_2 = 1.96;

    std::cout << "Z max obtenu : " << maxZ << std::endl;
    std::cout << "Z_alpha/2 toleré (en valeur absolue) pour alpha = 0.05 : " << Z_alpha_2 << std::endl;

    // Hypothèse H_null (données indépendantes) rejetée si |maxZ| > Z_alpha/2
    if (maxZ > Z_alpha_2 || maxZ < -Z_alpha_2)
    {
        exit(EXIT_FAILURE);
    }
}

std::vector<Run> computeRuns(const double *data, size_t n)
{
    std::vector<Run> runs;
    bool rising = (data[1] >= data[0]);
    runs.push_back({rising, 1});
    for (size_t i = 2; i < n; i++)
    {
        if ((data[i] >= data[i-1]) xor rising)
        {
            runs.back().length ++;
        }
        else
        {
            rising = !rising;
            runs.push_back({rising, 1});
        }
    }
    
    return runs;
}


void aboveAndBelowMean(const double* data, size_t n, int &above, int &below) {

    // Calcul de la moyenne
    double mean = 0;
    for (size_t i = 0; i < n; i++)
    {
        mean += data[i];
    }
    mean /= n;
    
    // calcul du nombre de nombres au dessus et en dessous de la moyenne
    above = 0;
    below = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (data[i] > mean)
        {
            above ++;
        }
        else
        {
            below ++;
        }
    }
}
/**
 * \file StatisticalTests.cpp
 * \brief Corps des fonctions relatives aux tests statistiques
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#include "StatisticalTests.h"
#include "DistributionNormale.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <boost/math/special_functions/factorials.hpp>

double mean(const double *data, const int n)
{
    double ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += data[i];
    }
    return ret /= n;
}

double chi2(const double *obtained, const double *expected, const int n)
{
    if (n < 1)
    {
        throw std::invalid_argument("La taille des tableaux doit être un entier strictement positif");
    }

    double ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += pow(obtained[i] - expected[i], 2) / expected[i];
    }

    return ret;
}

double KS(const double *data, const int n)
{
    if (n < 1000)
    {
        throw std::invalid_argument("Pas assez de données pour obtenir une valeur significative");
    }

    // copie des données
    double cpy[n];
    std::copy(data, data + n, cpy);

    std::sort(cpy, cpy + n);

    // calcul de D+
    double Dplus = 1. / n - cpy[0];
    double current;
    for (int i = 1; i < n; i++)
    {
        current = (i + 1.) / n - cpy[i];
        if (current > Dplus)
        {
            Dplus = current;
        }
    }

    // calcul de D-
    double Dminus = cpy[0];
    for (int i = 1; i < n; i++)
    {
        current = cpy[i] - ((double)i) / n;
        if (current > Dminus)
        {
            Dminus = current;
        }
    }

    // D = max(D+, D-)
    return (Dplus > Dminus) ? Dplus : Dminus;
}

double uniformDistributionChi2(const double *data, const int n, const int nClasses)
{
    if (n < 1000)
    {
        throw std::invalid_argument("Pas assez de données pour obtenir une valeur significative");
    }

    double obtained[nClasses] = {0};
    double expected[nClasses];

    // Calcul des fréquences attendues
    for (int i = 0; i < nClasses; i++)
    {
        expected[i] = ((double)n) / nClasses;
    }

    // calculs des fréquences obtenues
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nClasses; j++)
        {
            if (data[i] < (j + 1.) / nClasses)
            {
                obtained[j]++;
                break;
            }
        }
    }

    return chi2(obtained, expected, nClasses);
}

double normalDistributionChi2(const double *data, const int n, const int nClasses)
{
    if (n < 1000)
    {
        throw std::invalid_argument("Pas assez de données pour obtenir une valeur significative");
    }

    double obtained[nClasses] = {0};
    double expected[nClasses];
    double inv_cdf[nClasses];

    DistributionNormale stdNormal;

    // Calcul des fréquences attendues
    for (int i = 0; i < nClasses - 1; i++)
    {
        expected[i] = ((double)n) / nClasses;
        inv_cdf[i] = stdNormal.inv_cdf((double) (i + 1.) / (double) nClasses);
    }
    expected[nClasses - 1] = ((double)n) / nClasses;
    inv_cdf[nClasses - 1] = 100; // La distribution normale ne peut générer des nombres qu'entre -6 et 6

    // calculs des fréquences obtenues
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nClasses; j++)
        {
            if (data[i] < inv_cdf[j])
            {
                obtained[j]++;
                break;
            }
        }
    }
    
    return chi2(obtained, expected, nClasses);
}

double autocorrelationNormalVar(const double *data, const int n)
{

    if (n < 1000)
    {
        throw std::invalid_argument("Pas assez de données pour obtenir une valeur significative");
    }

    std::vector<double> obtainedZ;

    // i < 10 et m < 20 car M doit etre >> 1 pour obtenir une distribution normale
    for (int i = 0; i < 10; i++)
    {
        for (int m = i + 1; m < 20; m++)
        {
            // calcul de M
            int M = 0;
            while (i + (M + 2) * m <= n)
            {
                M++;
            }

            // calcul rho
            double rho = 0.;
            for (int k = 0; k < (M + 1); k++)
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

    return *(std::max_element(obtainedZ.begin(), obtainedZ.end()));
}

double runsUDNumberNormalVar(const double *data, const int n)
{
    if (n < 1000)
    {
        throw std::invalid_argument("Pas assez de données pour obtenir une valeur significative");
    }

    // calcul du nombre de runs up and down
    int nRuns = 1;
    bool risingRun = (data[1] >= data[0]);
    for (int i = 2; i < n; i++)
    {
        if ((data[i] >= data[i - 1]) xor risingRun)
        {
            nRuns++;
            risingRun = !risingRun;
        }
    }

    // pour nRuns > 20, nRuns devrait suivre une loi normale
    double mu_nRuns = (2 * n - 1.) / 3.;
    double sigma_nRuns = sqrt((16. * n - 29.) / 90.);
    return (nRuns - mu_nRuns) / sigma_nRuns;
}

double runsABMNumberNormalVar(const double *data, const int n)
{
    if (n < 1000)
    {
        throw std::invalid_argument("Pas assez de données pour obtenir une valeur significative");
    }

    // Calcul de la moyenne
    double m = mean(data, n);

    // calcul du nombre de valeurs au dessus et en dessous de la moyenne
    int nRuns = 1;
    bool runAboveMean = (data[0] > m);
    int nAbove = (int) runAboveMean;
    int nBelow = (int) !runAboveMean;

    for (int i = 1; i < n; i++)
    {
        bool currentAbove = (data[i] > m);
        if (currentAbove xor runAboveMean)
        {
            nRuns++;
        }
        nAbove += (int) currentAbove;
        nBelow += (int) !currentAbove;
    }

    double mu_AB = (2. * nAbove * nBelow) / n + 0.5;
    double temp1 = 2. * nAbove * nBelow * (2. * nAbove * nBelow - n);
    double temp2 = (double) n * (double) n * (double)(n - 1.);
    double sigma_AB = sqrt(temp1 / temp2);
    return (nRuns - mu_AB) / sigma_AB;
}

double runsUDLengthChi2(const double *data, const int n)
{
    if (n < 20)
    {
        throw std::invalid_argument("Pas assez de données pour obtenir une valeur significative");
    }

    if (n > 100)
    {
        throw std::invalid_argument("Trop de données, peut fausser la valeur obtenue");
    }

    // calcul du nombre et de la taille des runs ups and down
    // de chaque taille entre 1 et n-1 (donc indice tableau entre 0 et n-2)
    double runs[n - 1] = {0};
    int nRuns = 1;
    bool risingRun = (data[1] >= data[0]);
    for (int i = 2; i < n; i++)
    {
        int currentRunLength = 0; // on calcule les tailles de 0 à n-2 au lieu de 1 à n-1
        if ((data[i] >= data[i - 1]) xor risingRun)
        {
            runs[currentRunLength]++;
            nRuns++;
            risingRun = !risingRun;
        }
        else
        {
            currentRunLength++;
        }
    }

    // calcul des valeurs attendues pour le test du chi2
    double expected[n - 1];
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        expected[i] = (2. / boost::math::factorial<double>(j + 3)) * (n * (pow(j, 2) + 3 * j + 1.) - (pow(j, 3) + 3 * pow(j, 2) - j - 4));
    }
    expected[n - 2] = 2. / boost::math::factorial<double>(n);

    return chi2(runs, expected, n - 1);
}

double runsABMLengthChi2(const double *data, const int n)
{
    if (n < 20)
    {
        throw std::invalid_argument("Pas assez de données pour obtenir une valeur significative");
    }

    if (n > 100)
    {
        throw std::invalid_argument("Trop de données, peut fausser la valeur obtenue");
    }

    // calcul de la moyenne
    double m = mean(data, n);

    // calcul du nombre et de la taille des runs above/below mean et du nombre de valeurs au dessus/en dessous de la moyenne en même temps
    double runs[n] = {0};
    int nRuns = 1;
    bool runAboveMean = (data[0] > m);
    int nAbove = runAboveMean;
    int nBelow = !runAboveMean;

    for (int i = 1; i < n; i++)
    {
        int currentRunLength = 0;
        bool currentAbove = (data[i] > m);
        if (currentAbove xor runAboveMean) /* code */
        {
            runs[currentRunLength]++;
            nRuns++;
            runAboveMean = !runAboveMean;
        }
        else
        {
            currentRunLength++;
        }
        nAbove += currentAbove;
        nBelow += !currentAbove;
    }

    // calcul des valeurs attendues pour le test du chi2
    double expected[n];
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        double n1 = nAbove;
        double n2 = nBelow;
        double u = pow(n1 / n, j) * (n2 / n) + pow(n2 / n, j) * (n1 / n);
        double e = n1 / n2 + n2 / n1;

        expected[i] = n * u / e;
    }

    return chi2(runs, expected, n);
}
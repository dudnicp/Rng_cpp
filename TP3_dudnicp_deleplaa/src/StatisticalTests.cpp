#include "StatisticalTests.h"
#include "DistributionNormale.h"
#include "MathFunc.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>


// Test du Chi2
void chiSquaredTest(const double *obtained, const double *expected, const int n, const double alpha)
{
    // Calcul de la p-value obtenue
    double x = 0;
    for (int i = 0; i < n; i++)
    {
        x += pow(obtained[i] - expected[i], 2) / expected[i];
    }
    double pValue = 1 - chi2Cdf(x, n - 1);

    std::cout << "p-value obtenue : " << pValue << std::endl;
    std::cout << "p-value tolérée : " << alpha << std::endl;

    if (pValue < alpha)
    {
        exit(EXIT_FAILURE);
    }
}

// Test de loi normale
void stdNormalTest(const double z, const double alpha)
{
    DistributionNormale stdNormal;
    double z_alpha_2 = stdNormal.inv_cdf(alpha / 2.);

    std::cout << "z obtenu " << z << std::endl;
    std::cout << "z_alpha/2 toleré (en valeur absolue) pour alpha = " << alpha << " : " << z_alpha_2 << std::endl;

    // Hypothèse H_null (données indépendantes) rejetée si |maxZ| > Z_alpha/2
    if (z > z_alpha_2 || z < -z_alpha_2)
    {
        exit(EXIT_FAILURE);
    }
}

// Test de H_null : data suit une loi uniforme sur [0, 1] avec le test de Kolmogorov-Smirnov
// On suppose n >> 100 pour avoir des tests aussi précis que possible
void uniformFrequencyKSTest(const double *data, const int n)
{
    // copie des données
    double cpy[n];
    memcpy(cpy, data, n);

    // tri des données
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

// Test de H_null : data suit une loi uniforme sur [0, 1] avec le test du Chi2
// On suppose n >> 100 pour avoir des tests aussi précis que possible
void uniformFrequencyChiSquaredTest(const double *data, int n)
{
    int nClasses = 100;
    double obtained[nClasses] = {0};
    double expected[nClasses];

    for (int i = 0; i < nClasses; i++)
    {
        expected[i] = ((double)n) / nClasses;
    }

    // calculs des fréquences obtenues
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nClasses; j++)
        {
            if (data[i] < ((double)(j + 1)) / n)
            {
                obtained[j]++;
                break;
            }
        }
    }

    chiSquaredTest(obtained, expected, nClasses, ALPHA);
}

// Test de H_null : data suit une loi normale N(0,1 avec le test du Chi2
// On suppose n >> 100 pour avoir des tests aussi précis que possible
void normalFrequencyChiSquaredTest(const double *data, int n)
{
    int nClasses = 100;
    double obtained[nClasses] = {0};
    double expected[nClasses];
    double inv_cdf[nClasses];

    DistributionNormale stdNormal;

    for (int i = 0; i < nClasses; i++)
    {
        expected[i] = ((double)n) / nClasses;
        inv_cdf[i] = stdNormal.inv_cdf(expected[i]);
    }

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

    chiSquaredTest(obtained, expected, nClasses, ALPHA);
}

// Test de H_null : nombres générées aléatoirement sont indépendants
// On suppose n >> 100 pour avoir des tests aussi précis que possible
void autocorrelationTest(const double *data, const int n)
{
    std::vector<double> obtainedZ;

    // i et m < 10 car M doit etre >> 1 pour obtenir une distribution normale
    for (int i = 0; i < 10; i++)
    {
        for (int m = i + 1; m < 10; m++)
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

    double maxZ = *(std::max_element(obtainedZ.begin(), obtainedZ.end()));

    stdNormalTest(maxZ, ALPHA);
}

void runsNumberTest(const double *data, const int n)
{
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
    double Z_nRuns = (nRuns - mu_nRuns) / sigma_nRuns;

    stdNormalTest(Z_nRuns, ALPHA);
}

void aboveAndBelowMeanTest(const double *data, const int n)
{
    // Calcul de la moyenne et du nombre de runs up and down en même temps
    int nRuns = 1;
    bool risingRun = (data[1] >= data[0]);
    double mean = data[0] + data[1];
    for (int i = 2; i < n; i++)
    {
        if ((data[i] >= data[i - 1]) xor risingRun)
        {
            nRuns++;
            risingRun = !risingRun;
        }
        mean += data[i];
    }
    mean /= n;

    // calcul du nombre de valeurs au dessus et en dessous de la moyenne
    int nAbove = 0;
    int nBelow = 0;
    for (int i = 0; i < n; i++)
    {
        if (data[i] > mean)
        {
            nAbove++;
        }
        else
        {
            nBelow++;
        }
    }

    double mu_AB = (2. * nAbove * nBelow) / n + 0.5;
    double sigma_AB = sqrt((2. * nAbove * nBelow * (2. * nAbove * nBelow - n)) / (n * n * (n - 1.)));
    double Z_AB = (nRuns - mu_AB) / sigma_AB;

    stdNormalTest(Z_AB, ALPHA);
}

void runsLengthTest(const double *data, const int n)
{
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
            currentRunLength ++;
        }
        
    }

    // calcul des valeurs attendues pour le test du chi2
    double expected[n - 1];
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        expected[i] = (2. / factorial(j + 3)) * (n * (pow(j, 2) + 3 * j + 1.) - (pow(j, 3) + 3 * pow(j, 2) - j - 4));
    }
    expected[n - 2] = 2. / factorial(n);

    chiSquaredTest(runs, expected, n - 1, ALPHA);
}

void runsAboveAndBelowMeanTest(const double* data, const int n) {
    double mean = 0;
    for (int i = 0; i < n; i++)
    {
        mean += data[i];
    }
    mean /= n;

    // calcul du nombre et de la taille des runs above/below mean et du nombre de valeurs au dessus/en dessous de la moyenne en même temps
    double runs[n] = {0};
    int nRuns = 1;
    bool runAboveMean = (data[0] > mean);
    int nAbove = 0;
    int nBelow = 0;

    for (int i = 1; i < n; i++)
    {
        int currentRunLength = 0;
        bool currentAbove = (data[i] > mean);
        if (currentAbove xor runAboveMean)/* code */
        {
            runs[currentRunLength] ++;
            nRuns ++;
            runAboveMean = !runAboveMean;
        }
        else
        {
            currentRunLength ++;
        }
        nAbove += runAboveMean;
        nBelow += !runAboveMean;
    }
    
    // calcul des valeurs attendues pour le test du chi2
    double expected[n];
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        double n1 = nAbove;
        double n2 = nBelow;
        double u = pow(n1/n, j) * (n2/n) + pow(n2/n, j) * (n1/n);
        double e = n1/n2 + n2/n1;

        expected[i] = n*u/e;
    }

    chiSquaredTest(runs, expected, n, ALPHA);   
}
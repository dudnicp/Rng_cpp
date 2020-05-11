#include "GenerateurParkMiller.h"
#include "StatisticalTests.h"

/**
 * \file ParkMillerFrequency.cpp
 * \brief Tests de fréquences pour vérifier que la méthode de ParkMiller génère des nombres aléatoires
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    const int dim = 1000000;
    GenerateurParkMiller parkMiller(dim);
    double *data = parkMiller.generate_uniform();

    uniformFrequencyKSTest(data, dim);

    uniformFrequencyChiSquaredTest(data, dim);

    return EXIT_SUCCESS;
}

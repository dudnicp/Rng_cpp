#include "GenerateurXorShift.h"
#include "StatisticalTests.h"
#include "MathFunc.h"
#include <algorithm>
#include <cstring>

/**
 * \file TestXorShiftFrequency.cpp
 * \brief Tests de fréquences pour vérifier que la méthode de XorShift génère des nombres aléatoires
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    const int dim = 1000000;
    GenerateurXorShift xorShift(dim);
    double *data = xorShift.generate_uniform();

    std::cout << "--- Test Kolmogorov-Smirnov ---" << std::endl;
    uniformFrequencyKSTest(data, dim);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test Chi2 ---" << std::endl;
    uniformFrequencyChiSquaredTest(data, dim);
    std::cout << "--- PASSED ---" << std::endl;

    delete[] data;

    return EXIT_SUCCESS;
}

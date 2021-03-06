/**
 * \file TestXorShiftAutocorrelation.cpp
 * \brief Tests statistiques d'autocorrélation pour évaluer les performances du générateur XorShift
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestXorShiftAutocorrelation

#include "GenerateurXorShift.h"
#include "StatisticalTests.h"
#include "DistributionNormale.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(autocorrelation)
{
    const int N = 1000000;
    GenerateurXorShift g(N);
    double *data = g.generate_uniform();
    double Z = std::abs(autocorrelationNormalVar(data, N));

    delete[] data;

    DistributionNormale d;
    double Z_alpha = d.inv_cdf(0.975); // Test pour alpha = 0.05

    std::cout << "Z obtenu : " << Z << std::endl;
    std::cout << "Z toléré : " << Z_alpha << std::endl;

    BOOST_CHECK_LT(Z, Z_alpha);
}
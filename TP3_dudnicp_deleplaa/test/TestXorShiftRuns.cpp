/**
 * \file TestXorShiftRuns.cpp
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
#include <boost/math/distributions/chi_squared.hpp>

BOOST_AUTO_TEST_CASE(runs_up_down_number)
{
    std::cout << "--- Runs \"up & down\" number test ---" << std::endl;

    const int N = 1000000;
    GenerateurXorShift g(N);
    double *data = g.generate_uniform();
    double Z = std::abs(runsUDNumberNormalVar(data, N));

    delete[] data;

    DistributionNormale d;
    double Z_alpha = d.inv_cdf(0.975); // Test pour alpha = 0.05

    std::cout << "Z obtenu : " << Z << std::endl;
    std::cout << "Z attendu : " << Z_alpha << std::endl;

    BOOST_CHECK_LT(Z, Z_alpha);
}

BOOST_AUTO_TEST_CASE(runs_above_below_number)
{
    std::cout << "--- Runs \"above & below mean\" number test ---" << std::endl;

    const int N = 1000000;
    GenerateurXorShift g(N);
    double *data = g.generate_uniform();
    double Z = std::abs(runsABMNumberNormalVar(data, N));

    delete[] data;

    DistributionNormale d;
    double Z_alpha = d.inv_cdf(0.975); // Test pour alpha = 0.05

    std::cout << "Z obtenu : " << Z << std::endl;
    std::cout << "Z attendu : " << Z_alpha << std::endl;

    BOOST_CHECK_LT(Z, Z_alpha);
}

BOOST_AUTO_TEST_CASE(runs_up_down_length)
{
    std::cout << "--- Runs \"up & down\" length test ---" << std::endl;

    const int N = 100;
    GenerateurXorShift g(N);
    double *data = g.generate_uniform();
    double X2 = runsUDLengthChi2(data, N);
    double expectedX2 = boost::math::quantile(boost::math::chi_squared(N - 2), 0.95);

    delete[] data;

    std::cout << "X2 obtenu : " << X2 << std::endl;
    std::cout << "X2 attendu : " << expectedX2 << std::endl;

    BOOST_CHECK_LT(X2, expectedX2);
}

BOOST_AUTO_TEST_CASE(runs_above_below_length)
{
    std::cout << "--- Runs \"above & below mean\" length test ---" << std::endl;

    const int N = 100;
    GenerateurXorShift g(N);
    double *data = g.generate_uniform();
    double X2 = runsABMLengthChi2(data, N);
    double expectedX2 = boost::math::quantile(boost::math::chi_squared(N - 1), 0.95);

    delete[] data;

    std::cout << "X2 obtenu : " << X2 << std::endl;
    std::cout << "X2 attendu : " << expectedX2 << std::endl;

    BOOST_CHECK_LT(X2, expectedX2);
}

/**
 * \file TestParkMillerFrequency.cpp
 * \brief Tests statistiques de fréquence pour évaluer les performances du générateur de Park-Miller
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestParkMillerFrequency

#include "GenerateurXorShift.h"
#include "DistributionNormale.h"
#include "StatisticalTests.h"
#include <boost/math/distributions/chi_squared.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(chi2_test)
{
    std::cout << "--- Test du X2 ---" << std::endl;

    const int N = 1000000;
    const int nClasses = 100;
    GenerateurXorShift g(N);
    g.set_seed(123468);
    DistributionNormale d;
    double *data = d.random_draws(g);
    double X2 = normalDistributionChi2(data, N, nClasses);
    double expectedX2 = boost::math::quantile(boost::math::chi_squared(nClasses - 1), 0.95);

    delete[] data;

    std::cout << "X2 obtenu : " << X2 << std::endl;
    std::cout << "X2 attendu : " << expectedX2 << std::endl;

    BOOST_CHECK_LT(X2, expectedX2);
}
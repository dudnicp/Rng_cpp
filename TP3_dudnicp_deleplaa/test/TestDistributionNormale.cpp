#include "DistributionNormale.h"
#include "MyTest.h"

/**
 * \file TestDistributionNormale.cpp
 * \brief Tests sur les distributions normales
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test constructeur par défaut
    DistributionNormale d1;
    TEST_EQ(d1.mean(), 0.);
    TEST_EQ(d1.stdev(), 1.);

    // Test constructeur moyenne / écart type
    DistributionNormale d2(3., 2.);
    TEST_EQ(d2.mean(), 3.);
    TEST_EQ(d2.stdev(), 2.);

    // Test constructeur copie
    DistributionNormale d3(d2);
    TEST_EQ(d3.mean(), 3.);
    TEST_EQ(d3.stdev(), 2.);

    // Test opérateur d'affecation
    DistributionNormale d4;
    d4 = d3;
    TEST_EQ(d4.mean(), 3.);
    TEST_EQ(d4.stdev(), 2.);

    // Test var
    TEST_EQ(d2.var(), 4.);


    // Test pdf
    TEST_PRECISION(d1.pdf(-2.), 0.05399, 1E-5);
    TEST_PRECISION(d1.pdf(-1.), 0.24197, 1E-5);
    TEST_PRECISION(d1.pdf(0.), 0.39894, 1E-5);
    TEST_PRECISION(d1.pdf(1.), 0.24197, 1E-5);
    TEST_PRECISION(d1.pdf(2.), 0.05399, 1E-5);
    
    // Test cdf
    TEST_PRECISION(d1.cdf(-2.), 0.02275, 1E-5);
    TEST_PRECISION(d1.cdf(-1.), 0.15865, 1E-5);
    TEST_PRECISION(d1.cdf(0.), 0.5, 1E-5);
    TEST_PRECISION(d1.cdf(1.), 0.84134, 1E-5);
    TEST_PRECISION(d1.cdf(2.), 0.97725, 1E-5);

    // Test inv_cdf
    TEST_PRECISION(d1.inv_cdf(0.1), -1.28155, 1E-5);
    TEST_PRECISION(d1.inv_cdf(0.25), -0.67449, 1E-5);
    TEST_PRECISION(d1.inv_cdf(0.5), 0., 1E-5);
    TEST_PRECISION(d1.inv_cdf(0.75), 0.67449, 1E-5);
    TEST_PRECISION(d1.inv_cdf(0.9), 1.28155, 1E-5);

    return EXIT_SUCCESS;
}

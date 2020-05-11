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
    std::cout << "--- Test constructeur par défaut ---" << std::endl;
    DistributionNormale d1;
    TEST_EQ(d1.mean(), 0.);
    TEST_EQ(d1.stdev(), 1.);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test constructeur moyenne / écart type ---" << std::endl;
    DistributionNormale d2(3., 2.);
    TEST_EQ(d2.mean(), 3.);
    TEST_EQ(d2.stdev(), 2.);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test constructeur copie ---" << std::endl;
    DistributionNormale d3(d2);
    TEST_EQ(d3.mean(), 3.);
    TEST_EQ(d3.stdev(), 2.);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test operator= ---" << std::endl;
    DistributionNormale d4;
    d4 = d3;
    TEST_EQ(d4.mean(), 3.);
    TEST_EQ(d4.stdev(), 2.);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test var() ---" << std::endl;
    TEST_EQ(d2.var(), 4.);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test pdf() ---" << std::endl;
    TEST_PRECISION(d1.pdf(-2.), 0.05399, 1E-5);
    TEST_PRECISION(d1.pdf(-1.), 0.24197, 1E-5);
    TEST_PRECISION(d1.pdf(0.), 0.39894, 1E-5);
    TEST_PRECISION(d1.pdf(1.), 0.24197, 1E-5);
    TEST_PRECISION(d1.pdf(2.), 0.05399, 1E-5);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test cdf() ---" << std::endl;
    TEST_PRECISION(d1.cdf(-2.), 0.02275, 1E-5);
    TEST_PRECISION(d1.cdf(-1.), 0.15865, 1E-5);
    TEST_PRECISION(d1.cdf(0.), 0.5, 1E-5);
    TEST_PRECISION(d1.cdf(1.), 0.84134, 1E-5);
    TEST_PRECISION(d1.cdf(2.), 0.97725, 1E-5);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test inv_cdf() ---" << std::endl;
    std::cout << d1.inv_cdf(0.1) << std::endl;
    TEST_PRECISION(d1.inv_cdf(0.1), -1.28155, 1E-3);
    TEST_PRECISION(d1.inv_cdf(0.25), -0.67449, 1E-3);
    TEST_PRECISION(d1.inv_cdf(0.5), 0., 1E-3);
    TEST_PRECISION(d1.inv_cdf(0.75), 0.67449, 1E-3);
    TEST_PRECISION(d1.inv_cdf(0.9), 1.28155, 1E-3);
    std::cout << "--- PASSED ---" << std::endl;

    return EXIT_SUCCESS;
}

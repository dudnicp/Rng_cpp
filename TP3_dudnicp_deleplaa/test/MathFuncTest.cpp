#include "MathFunc.h"
#include "MyTest.h"
#include <cmath>

/**
 * \file MathFuncTest.cpp
 * \brief Tests sur les fonctions mathématiques auxiliaires
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    std::cout << "--- Test mean() ---" << std::endl;
    double data[10];
    for (int i = 0; i < 10; i++)
    {
        data[i] = i;
    }
    TEST_EQ(mean(data, 10), 4.5);
    std::cout << "--- PASSED ---" << std::endl;


    std::cout << "--- Test factorial() ---" << std::endl;
    TEST_EQ(factorial(0), 1);
    TEST_EQ(factorial(1), 1);
    TEST_EQ(factorial(5), 120);
    try
    {
        factorial(-1);
        return EXIT_FAILURE;
    }
    catch (const std::domain_error &e)
    {
    }
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test G() ---" << std::endl;
    TEST_EQ(G(1. / 2.), sqrt(M_PI));
    TEST_EQ(G(1), 1);
    TEST_EQ(G(5. / 2.), sqrt(M_PI) * (1. / 2.) * (3. / 2.));
    try
    {
        G(-1);
        return EXIT_FAILURE;
    }
    catch (const std::domain_error &e)
    {
    }
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- chi2Cdf ---" << std::endl;
    TEST_PRECISION(chi2Cdf(0.02, 1), 0.100, 0.001);
    TEST_PRECISION(chi2Cdf(124.45, 100), 0.950, 0.001);
    try
    {
        chi2Cdf(10, -1);
        return EXIT_FAILURE;
    }
    catch (const std::domain_error &e)
    {
    }
    std::cout << "--- PASSED ---" << std::endl;

    return EXIT_SUCCESS;
}

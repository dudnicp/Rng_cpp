#include "MyTest.h"
#include "Dvector.h"

/**
 * \file TestSelfDivOperator.cpp
 * \brief Test sur l'opérateur /= de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test Dvector /= double
    TEST_EQ(Dvector(3, 2.) /= 3, Dvector(3, 2./3.));

    // Test Dvector / 0
    try
    {
        Dvector(3, 2.) /= 0;
        return EXIT_FAILURE;
    }
    catch(const std::domain_error& e) {}


    return EXIT_SUCCESS;
}

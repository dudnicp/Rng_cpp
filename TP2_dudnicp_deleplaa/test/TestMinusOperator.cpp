#include "MyTest.h"
#include "Dvector.h"

/**
 * \file TestMinusOperator.cpp
 * \brief Tests sur l'opérateur - binaire de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test Dvector - double
    TEST_EQ(Dvector(3, 2.) - 3., Dvector(3, -1.));

    // Test Dvector - Dvector
    TEST_EQ(Dvector(3, 2.) - Dvector(3, 3.), Dvector(3, -1));

    // Test Dvector - Dvector (tailles incompatibles)
    try
    {
        Dvector(3, 2.) - Dvector(4, 2.);
        return EXIT_FAILURE;
    }
    catch(const std::domain_error& e) {}

    
    return EXIT_SUCCESS;
}

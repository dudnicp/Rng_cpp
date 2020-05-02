#include "MyTest.h"
#include "Dvector.h"

/**
 * \file TestSelfMultOperator.cpp
 * \brief Test sur l'opérateur *= de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test Dvector / double
    TEST_EQ(Dvector(3, 2.) *= 3, Dvector(3, 6.));

    
    return EXIT_SUCCESS;
}

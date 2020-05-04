#include "MyTest.h"
#include "Dvector.h"

/**
 * \file TestUnaryMinusOperator.cpp
 * \brief Tests sur l'opérateur + de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test Dvector + double
    TEST_EQ(-Dvector(3, 2.), Dvector(3, -2.));
    
    
    return EXIT_SUCCESS;
}

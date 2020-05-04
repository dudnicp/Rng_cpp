#include "MyTest.h"
#include "Dvector.h"

/**
 * \file TestEqualityOperator.cpp
 * \brief Tests sur l'opérateur == de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test Dvector == Dvector true
    TEST_EQ(Dvector(3, 2.) == Dvector(3, 2.), true);

    // Test Dvector == Dvector false (taille)
    TEST_EQ(Dvector(3, 2.) == Dvector(4, 2.), false);

    // Test Dvector == Dvector false (coordonnées)
    TEST_EQ(Dvector(3, 2.) == Dvector(3, 3.), false);

    // Test Dvector == Dvector true (Dvectors nulls)
    TEST_EQ(Dvector() == Dvector(), true);

    // Test Dvector == Dvector false (Dvector null)
    TEST_EQ(Dvector() == Dvector(3, 2.), false);
    
    return EXIT_SUCCESS;
}

#include "MyTest.h"
#include "Dvector.h"

/**
 * \file TestAffectationOperator.cpp
 * \brief Tests sur l'opérateur = de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    Dvector v;

    // Test affectation vecteur
    TEST_EQ(v = Dvector(3, 2.), Dvector(3, 2.));

    // Test affectation vecteur null
    TEST_EQ(v = Dvector(), Dvector());

    return EXIT_SUCCESS;
}

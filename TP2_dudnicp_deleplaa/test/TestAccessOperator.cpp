#include "MyTest.h"
#include "Dvector.h"

/**
 * \file TestAccessOperator.cpp
 * \brief Tests sur l'opérateur () de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    Dvector v(3, 2.);

    // Test accès lecture
    TEST_EQ(v(1), 2.);

    // Test accès ecriture
    v(1) = 3.;
    TEST_EQ(v(1), 3.);

    // Test accès interdit (indice < 0)
    try
    {
        v(-1);
        return EXIT_FAILURE;
    }
    catch(const std::out_of_range& e) {}

    // Test accès interdit (indice > 0)
    try
    {
        v(3);
        return EXIT_FAILURE;
    }
    catch(const std::out_of_range& e) {}
    

    return EXIT_SUCCESS;
}

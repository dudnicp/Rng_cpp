#include "MyTest.h"
#include "Dvector.h"

/**
 * \file TestResize.cpp
 * \brief Tests sur la méthode resize de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    Dvector v(3, 2.);

    // Test resize taille égale
    v.resize(3, 3.);
    TEST_EQ(v, Dvector(3, 2.));

    // Test resize taille inferieure
    v.resize(2, 3.);
    TEST_EQ(v, Dvector(2, 3.));

    // Test resize taille supérieure
    v.resize(4, 2.);
    Dvector test(4, 2.);
    test(0) = test(1) = 3.;
    TEST_EQ(v, test);

    // Test resize taille nulle
    v.resize(0);
    TEST_EQ(v, Dvector());

    // Test resize taille invalide ( < 0)
    try
    {
        v.resize(-1);
        return EXIT_FAILURE;
    }
    catch(const std::invalid_argument& e) {}
    
    
    return EXIT_SUCCESS;
}

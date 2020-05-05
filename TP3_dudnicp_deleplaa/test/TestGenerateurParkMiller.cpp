#include "GenerateurParkMiller.h"
#include "MyTest.h"

/**
 * \file TestGenerateurParkMiller.cpp
 * \brief Tests sur le générateur aléatoire de Park-Miller
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test constructeur dim
    GenerateurParkMiller g1(3);
    TEST_EQ(g1.get_dim(), 3);
    TEST_EQ(g1.get_seed(), 1);

    // Test constructeur par copie
    GenerateurParkMiller g2(g1);
    TEST_EQ(g2.get_dim(), 3);
    TEST_EQ(g2.get_seed(), 1);
    
    // Test opérateur affectation
    GenerateurParkMiller g3(1);
    g3 = g1;
    TEST_EQ(g3.get_dim(), 3);
    TEST_EQ(g3.get_seed(), 1);

    
    // Test set_dim
    g2.set_dim(1);
    TEST_EQ(g2.get_dim(), 1);

    // Test set_seed
    g2.set_seed(2);
    TEST_EQ(g2.get_seed(), 2);

    // Test clone
    g1.clone(g2);
    TEST_EQ(g1.get_dim(), 1);
    TEST_EQ(g1.get_seed(), 2);

    // Test reset_seed
    g1.reset_seed();
    TEST_EQ(g1.get_seed(), 1);

    // Test get_max
    TEST_EQ(g1.get_max(), INT32_MAX);

    // Test generate()
    TEST_EQ(*(g1.generate()), 16807);
    TEST_EQ(*(g1.generate()), 282475249);
    TEST_EQ(*(g1.generate()), 1622650073);
    TEST_EQ(*(g1.generate()), 984943658);

    return EXIT_SUCCESS;
}

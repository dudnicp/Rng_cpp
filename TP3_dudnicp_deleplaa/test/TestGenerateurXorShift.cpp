#include "GenerateurXorShift.h"
#include "MyTest.h"

/**
 * \file TestGenerateurXorShift.cpp
 * \brief Tests sur le générateur aléatoire de Park-Miller
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test constructeur dim
    GenerateurXorShift g1(3);
    TEST_EQ(g1.get_dim(), 3);
    TEST_EQ(g1.get_seed(), (uint64_t) 1);

    // Test constructeur par copie
    GenerateurXorShift g2(g1);
    TEST_EQ(g2.get_dim(), 3);
    TEST_EQ(g2.get_seed(), (uint64_t) 1);
    
    // Test opérateur affectation
    GenerateurXorShift g3(1);
    g3 = g1;
    TEST_EQ(g3.get_dim(), 3);
    TEST_EQ(g3.get_seed(), (uint64_t) 1);

    
    // Test set_dim
    g2.set_dim(1);
    TEST_EQ(g2.get_dim(), 1);

    // Test set_seed
    g2.set_seed(2);
    TEST_EQ(g2.get_seed(), (uint64_t) 2);

    // Test clone
    g1.clone(g2);
    TEST_EQ(g1.get_dim(), 1);
    TEST_EQ(g1.get_seed(), (uint64_t) 2);

    // Test reset_seed
    g1.reset_seed();
    TEST_EQ(g1.get_seed(), (uint64_t) 1);

    // Test get_max
    TEST_EQ(g1.get_max(), UINT64_MAX);

    // Test generate()
    TEST_EQ(*(g1.generate()), (uint64_t) 33685761);
    TEST_EQ(*(g1.generate()), (uint64_t) 1125917087301641);
    TEST_EQ(*(g1.generate()), (uint64_t) 868093111971292453);
    TEST_EQ(*(g1.generate()), (uint64_t) 13510906257080325);

    return EXIT_SUCCESS;
}

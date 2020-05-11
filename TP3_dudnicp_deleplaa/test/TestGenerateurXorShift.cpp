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
    std::cout << "--- Test constructeur dim ---" << std::endl;
    GenerateurXorShift g1(3);
    TEST_EQ(g1.get_dim(), 3);
    TEST_EQ(g1.get_seed(), (uint64_t) 1);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test constructeur par copie ---" << std::endl;
    GenerateurXorShift g2(g1);
    TEST_EQ(g2.get_dim(), 3);
    TEST_EQ(g2.get_seed(), (uint64_t) 1);
    std::cout << "--- PASSED ---" << std::endl;
    
    std::cout << "--- Test operator= ---" << std::endl;
    GenerateurXorShift g3(1);
    g3 = g1;
    TEST_EQ(g3.get_dim(), 3);
    TEST_EQ(g3.get_seed(), (uint64_t) 1);
    std::cout << "--- PASSED ---" << std::endl;

    
    std::cout << "--- Test set_dim ---" << std::endl;
    g2.set_dim(4);
    TEST_EQ(g2.get_dim(), 4);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test set_seed ---" << std::endl;
    g2.set_seed(2);
    TEST_EQ(g2.get_seed(), (uint64_t) 2);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test clone ---" << std::endl;
    g1.clone(g2);
    TEST_EQ(g1.get_dim(), 4);
    TEST_EQ(g1.get_seed(), (uint64_t) 2);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test reset_seed ---" << std::endl;
    g1.reset_seed();
    TEST_EQ(g1.get_seed(), (uint64_t) 1);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test get_max ---" << std::endl;
    TEST_EQ(g1.get_max(), UINT64_MAX);
    std::cout << "--- PASSED ---" << std::endl;

    std::cout << "--- Test generate ---" << std::endl;
    uint64_t *data = g1.generate();
    TEST_EQ(data[0], (uint64_t) 33685761);
    TEST_EQ(data[1], (uint64_t) 1125917087301641);
    TEST_EQ(data[2], (uint64_t) 868093111971292453);
    TEST_EQ(data[3], (uint64_t) 13510906257080325);
    std::cout << "--- PASSED ---" << std::endl;

    delete[] data;

    return EXIT_SUCCESS;
}

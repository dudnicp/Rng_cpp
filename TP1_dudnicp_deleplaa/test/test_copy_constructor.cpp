#include "Dvector.h"
#include <iostream>
#include <cassert>

/**
 * \file test_copy_constructor.cpp
 * \brief Tests du constructeur par copie de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    std::cout << "--- Test Constructeur par copie ---" << std::endl;
    Dvector a(3,2);
    Dvector b(a);
    assert(b.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(b.coords()[i] == 2);
    }
    std::cout << "--- OK ---" << std::endl << std::endl;

    return EXIT_SUCCESS;
}

#include "Dvector.h"
#include <iostream>
#include <cassert>

/**
 * \file test_default_constructor.cpp
 * \brief Tests du constructeur par défaut de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    std::cout << "--- Test Constructeur par défaut ---" << std::endl;
    Dvector a;
    assert(a.size() == 0);
    assert(a.coords() == nullptr);
    std::cout << "--- OK ---" << std::endl << std::endl;

    return EXIT_SUCCESS;
}

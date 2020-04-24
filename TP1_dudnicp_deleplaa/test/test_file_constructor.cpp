#include "Dvector.h"
#include <iostream>
#include <cassert>

/**
 * \file test_file_constructor.cpp
 * \brief Tests du constructeur par fichier de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    std::cout << "--- Test Constructeur par fichier ---" << std::endl;
    Dvector a("test.txt");
    assert(a.size() == 6);
    for (int i = 0; i < 6; i++)
    {   
        assert(a.coords()[i] == (i+1)/10.0);
    }
    std::cout << "--- OK ---" << std::endl << std::endl;

    return EXIT_SUCCESS;
}

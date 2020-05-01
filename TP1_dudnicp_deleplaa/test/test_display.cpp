#include "Dvector.h"
#include <iostream>
#include <cassert>
#include <sstream>

/**
 * \file test_display.cpp
 * \brief Tests de la fonction display() de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    std::cout << "--- Test display() ---" << std::endl;
    Dvector a(3,2);
    std::stringstream str;
    a.display(str);
    if (str.str() != "3\n2\n2\n") {
        return EXIT_FAILURE;
    }
    
    assert(str.str() == "2\n2\n2\n");
    std::cout << "--- OK ---" << std::endl << std::endl;

    return EXIT_SUCCESS;
}

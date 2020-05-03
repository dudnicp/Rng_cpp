#include "Dvector.h"
#include <iostream>

/**
 * \file DemoQ1.cpp
 * \brief Démonstration annexe pour répondre à la Q1
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    std::cout << "Dvector x; x = Dvector(3, 1.)" << std::endl;
    Dvector x;
    x = Dvector(3, 1.);
    x.display(std::cout);
    std::cout << std::endl;

    std::cout << "Dvector x = Dvector(3, 1.)" << std::endl;
    Dvector y = Dvector(3, 1.);
    y.display(std::cout);

    return EXIT_SUCCESS;
}

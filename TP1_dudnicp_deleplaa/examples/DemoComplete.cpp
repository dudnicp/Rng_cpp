#include "Dvector.h"
#include <iostream>

/**
 * \file DemoComplete.cpp
 * \brief Démonstration annexe pour illustrer les différentes utilisation des Dvectors
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    Dvector v0;
    std::cout << "Coordonnées de v1:" << std::endl;
    v0.display(std::cout);

    Dvector v1(10);
    v1.fillRandomly();
    std::cout << "Coordonnées de v1:" << std::endl;
    v1.display(std::cout);

    try
    {
        Dvector v2(-1, 1.);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    Dvector v3(v1);
    std::cout << "Coordonnées de v3:" << std::endl;
    v3.display(std::cout);

    return EXIT_SUCCESS;
}

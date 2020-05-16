/**
 * \file bigGenParkMiller.cpp
 * \brief Génération d'un grand nombre de valeurs avec la méthode de Park-Miller
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */


#include "GenerateurParkMiller.h"

int main(int argc, char const *argv[])
{
    GenerateurParkMiller g(10000000);
    g.generate();
    return EXIT_SUCCESS;
}

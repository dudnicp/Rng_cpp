/**
 * \file bigGenXorShift.cpp
 * \brief Génération d'un grand nombre de valeurs avec la méthode XorShift
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */


#include "GenerateurXorShift.h"

int main(int argc, char const *argv[])
{
    GenerateurXorShift g(10000000);
    g.generate();
    return EXIT_SUCCESS;
}

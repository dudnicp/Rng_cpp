#include "Dvector.h"

/**
 * \file DemoQ4.cpp
 * \brief Affectation d'un vecteur de grande taille pour tester les performances de l'opérateur = de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    Dvector test;
    test = Dvector(100000000);

    return EXIT_SUCCESS;
}

#include "Dvector.h"
#include "MyTest.h"

/**
 * \file TestFileConstructor.cpp
 * \brief Tests du constructeur par fichier de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test initialisation fichier vide
    Dvector v("EmptyInit.txt");
    TEST_EQ(v.size(), 0);
    TEST_EQ(v.coords(), (double *) nullptr);

    // Tests avec fichiers non vide
    Dvector* tab = new Dvector[3];
    tab[0] = Dvector("LineBreakInit.txt"); // Coordonnées séparées par des sauts de ligne
    tab[1] = Dvector("SpaceInit.txt"); // Coordonnées séparées par des sauts esapces
    tab[2] = Dvector("ComplexInit.txt"); // Coordonnées séparées par sauts de lignes et espace avec des lignes vides et des tabulations

    for (int i = 0; i < 3; i++)
    {
        TEST_EQ(tab[i].size(), 6);
        TEST_NEQ(tab[i].coords(), (double *) nullptr);
        for (int j = 0; j < tab[i].size(); j++)
        {
            TEST_EQ(tab[i].coords()[j], j/10.);
        }
    }

    return EXIT_SUCCESS;
}

#include "Dvector.h"
#include "MyTest.h"

/**
 * \file test_file_constructor.cpp
 * \brief Tests du constructeur par fichier de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test initialisation fichier vide
    Dvector v("init_files/EmptyInit.txt");
    TEST_EQ(v.size(), 0);
    TEST_EQ(v.coords(), (double *) nullptr);

    // Tests avec fichiers non vide
    Dvector* tab = new Dvector[3];
    tab[0] = Dvector("init_files/LineBreak.txt"); // Coordonnées séparées par des sauts de ligne
    tab[1] = Dvector("init_files/SpaceInit.txt"); // Coordonnées séparées par des sauts esapces
    tab[2] = Dvector("init_files/ComplexInit.txt"); // Coordonnées séparées par sauts de lignes et espace avec des lignes vides et des tabulations

    for (int i = 0; i < 3; i++)
    {
        TEST_EQ(v.size(), 6);
        TEST_NEQ(v.coords(), (double *) nullptr);
        for (int i = 0; i < v.size(); i++)
        {
            TEST_EQ(v.coords()[i], i/10.);
        }
    }

    return EXIT_SUCCESS;
}

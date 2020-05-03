#include "Dvector.h"
#include "MyTest.h"

/**
 * \file test_constructor.cpp
 * \brief Tests du constructeur taille + valeur de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    // Test Constructeur taille + valeur par défaut
    Dvector v0(3);
    TEST_EQ(v0.size(), 3);
    TEST_NEQ(v0.coords(), (double *) nullptr);
    for (int i = 0; i < v0.size(); i++)
    {
        TEST_EQ(v0.coords()[i], 0.);
    }

    // Test Constructeur taille + valeur
    Dvector v1(3, 2.);
    TEST_EQ(v1.size(), 3);
    TEST_NEQ(v1.coords(), (double *) nullptr);
    for (int i = 0; i < v1.size(); i++)
    {
        TEST_EQ(v1.coords()[i], 2.);
    }

    // Test Constructeur taille invalide
    try
    {
        Dvector v2(-1);
        return EXIT_FAILURE;
    }
    catch(const std::exception& e) {}
    

    return EXIT_SUCCESS;
}

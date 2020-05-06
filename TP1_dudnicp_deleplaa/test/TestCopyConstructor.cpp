#include "Dvector.h"
#include "MyTest.h"
/**
 * \file TestCopyConstructor.cpp
 * \brief Tests du constructeur par copie de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    Dvector test(3, 2.);
    Dvector nullVect;

    // Test Constructeur copie Dvector
    Dvector v(test);
    TEST_EQ(v.size(), 3);
    TEST_NEQ(v.coords(), nullptr);
    for (int i = 0; i < v.size(); i++)
    {
        TEST_EQ(v.coords()[i], 2.);
    }

    // Test Constructeur copie Dvector nul
    Dvector w(nullVect);
    TEST_EQ(w.size(), 0);
    TEST_EQ(w.coords(), nullptr);    

    return EXIT_SUCCESS;
}

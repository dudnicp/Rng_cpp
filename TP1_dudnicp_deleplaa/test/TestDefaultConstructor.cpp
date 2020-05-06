#include "Dvector.h"
#include "MyTest.h"

/**
 * \file TestDefaultConstructor.cpp
 * \brief Tests du constructeur par défaut de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    Dvector v;
    TEST_EQ(v.size(), 0);
    TEST_EQ(v.coords(), nullptr);

    return EXIT_SUCCESS;
}

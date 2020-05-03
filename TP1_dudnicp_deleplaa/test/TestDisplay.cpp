#include "Dvector.h"
#include "MyTest.h"

#include <sstream>

/**
 * \file test_display.cpp
 * \brief Tests de la fonction display() de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    std::stringstream str;
    Dvector v(3, 2.);
    v.display(str);
    TEST_EQ(str.str(), std::string("2\n2\n2\n"));

    return EXIT_SUCCESS;
}

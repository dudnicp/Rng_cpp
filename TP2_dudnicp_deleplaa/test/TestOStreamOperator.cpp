#include "MyTest.h"
#include "Dvector.h"

#include <sstream>

/**
 * \file TestOStreamOperator.cpp
 * \brief Test sur l'opérateur << de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    std::stringstream str1;
    std::stringstream str2;

    // Test stream << Dvector
    str1 << Dvector(3, 2.);
    TEST_EQ(str1.str(), std::string("2\n2\n2\n"));

    // Test stream << Dvector << Dvector
    str2 << Dvector(3, 2.) << Dvector(3, 2.);
    TEST_EQ(str2.str(), std::string("2\n2\n2\n2\n2\n2\n"));
    
    return EXIT_SUCCESS;
}

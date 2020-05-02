#include "MyTest.h"
#include "Dvector.h"

#include <sstream>

/**
 * \file TestIStreamOperator.cpp
 * \brief Tests sur l'opérateur >> de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    std::stringstream str1("1. 1. 1.");
    std::stringstream str2("2. 2. 2. 2.");
    std::stringstream str3("3. 3.");

    Dvector v(3);

    // Test stream.size == v.m_size
    str1 >> v;
    TEST_EQ(v, Dvector(3, 1.));

    // Test stream.size > v.m_size
    str2 >> v;
    TEST_EQ(v, Dvector(3, 2.));

    // Test stream.size < v.m_size
    str3 >> v;
    Dvector test(3, 3.);
    test(2) = 2;
    TEST_EQ(v, test);
    
    return EXIT_SUCCESS;
}

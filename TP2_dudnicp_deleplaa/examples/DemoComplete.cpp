#include "Dvector.h"
#include <sstream>

/**
 * \file DemoComplete.cpp
 * \brief Illustration des différentes utilisations possibles des Dvectors
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{
    Dvector a(3, 2.);
    Dvector b = a + 2;

    Dvector c;
    c.resize(3, 1);
    std::cout << (c - a) / 3. + b * 2. << std::endl;

    c(0) = 10;
    c(1) = 15;
    c(2) = 20;

    std::stringstream str;
    str << c;
    str >> a;

    if (a == c)
    {
        b += b*= 3;
        a = b;
        std::cout << a <<std::endl;
    }

    return EXIT_SUCCESS;
}

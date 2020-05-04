#include "Dvector.h"

/**
 * \file DemoQ2.cpp
 * \brief Illustration des différences entre le passage d'argument par copie et par référence
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

Dvector addition1(Dvector a, Dvector b);
Dvector addition2(const Dvector &a, const Dvector &b);

int main(int argc, char const *argv[])
{
    std::cout << "Création des Dvectors a et b;" << std::endl;
    Dvector a(3, 2.);
    Dvector b(3, 3.);
    std::cout << std::endl;

    std::cout << "Dvector c = addition(Dvector a, Dvector b);" << std::endl;
    Dvector c = addition1(a, b);
    std::cout << std::endl;

    std::cout << "Dvector d = addition(const Dvector &a, const Dvector &b);" << std::endl;
    Dvector d = addition2(a, b);
    std::cout << std::endl;

    std::cout << "Destruction de a, b, c, d" << std::endl;

    return EXIT_SUCCESS;
}

Dvector addition1(Dvector a, Dvector b)
{
    Dvector ret(a);
    ret += b;
    return ret;
}

Dvector addition2(const Dvector &a, const Dvector &b)
{
    Dvector ret(a);
    ret += b;
    return ret;
}
#include "Dvector.h"
#include <iostream>
#include <cassert>
#include <sstream>

/**
 * \file Test_Dvector.cpp
 * \brief Tests sur les Dvectors
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

int main(int argc, char const *argv[])
{

    std::cout << "### Tests Dvector ###" << std::endl << std::endl;

    std::cout << "--- Test Constructeur par défaut ---" << std::endl;
    Dvector a = Dvector();
    assert(a.size() == 0);
    assert(a.coords() == nullptr);
    std::cout << "--- OK ---" << std::endl << std::endl;


    std::cout << "--- Test Constructeur taille / valeur par défaut ---" << std::endl;
    Dvector b = Dvector(3);
    assert(b.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(b.coords()[i] == 0);
    }
    std::cout << "--- OK ---" << std::endl << std::endl;


    std::cout << "--- Test Constructeur taille / valeur ---" << std::endl;
    Dvector c = Dvector(3, 2);
    assert(c.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(c.coords()[i] == 2);
    }
    std::cout << "--- OK ---" << std::endl << std::endl;


    std::cout << "--- Test Constructeur par copie ---" << std::endl;
    Dvector d = Dvector(c);
    assert(d.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(d.coords()[i] == 2);
    }
    std::cout << "--- OK ---" << std::endl << std::endl;


    std::cout << "--- Test Constructeur par fichier ---" << std::endl;
    Dvector e = Dvector("test.txt");
    assert(e.size() == 6);
    for (int i = 0; i < 6; i++)
    {   
        assert(e.coords()[i] == (i+1)/10.0);
    }
    std::cout << "--- OK ---" << std::endl << std::endl;


    std::cout << "--- Test display() ---" << std::endl;
    std::stringstream str;
    d.display(str);
    assert(str.str() == "2\n2\n2\n");
    std::cout << "--- OK ---" << std::endl << std::endl;

    return EXIT_SUCCESS;
}



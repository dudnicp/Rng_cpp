#include "Dvector.h"
#include <iostream>
#include <cassert>
#include <ostream>
#include <string>
#include <sstream>
#include <cstring>

int main(int argc, char const *argv[])
{
    std::cout << "Test default constructor : " << std::endl;
    Dvector a = Dvector();
    assert(a.size() == 0);
    std::cout << "OK" << std::endl;


    std::cout << "Test size constructor : " << std::endl;
    Dvector b = Dvector(3);
    assert(b.size() == 3);
    std::cout << "OK" << std::endl;


    std::cout << "Test size + value constructor : " << std::endl;
    Dvector c = Dvector(3, 2);
    assert(c.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(c.coords()[i] == 2);
    }
    std::cout << "OK" << std::endl;


    std::cout << "Test copy constructor : " << std::endl;
    Dvector d = Dvector(c);
    assert(d.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(d.coords()[i] == 2);
    }
    std::cout << "OK" << std::endl;


    std::cout << "Test file constructor : " << std::endl;
    Dvector e = Dvector("test.txt");
    assert(e.size() == 6);
    for (int i = 0; i < 6; i++)
    {
        assert(e.coords()[i] == (i+1)/10.0);
    }
    std::cout << "OK" << std::endl;


    std::cout << "Test display : " << std::endl;
    std::stringstream str;
    d.display(str);
    assert(str.str() == "2\n2\n2\n");
    std::cout << "Ok" << std::endl;

    return EXIT_SUCCESS;

}



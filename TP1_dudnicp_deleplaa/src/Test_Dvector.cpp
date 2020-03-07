#include "Dvector.h"
#include <iostream>
#include <cassert>
#include <ostream>
#include <string>
#include <sstream>

int main(int argc, char const *argv[])
{
    Dvector x;
    assert(x.size() == 0);
    assert(x.coords() == NULL);
    std::cout << "OK" << std::endl;

    x = Dvector(3);
    assert(x.size() == 3);
    assert(x.coords() != NULL);
    std::cout << "OK" << std::endl;

    x = Dvector(3, 2.);
    assert(x.size() == 3);
    for (int i = 0; i < x.size(); i++)
    {
        assert(x.coords()[i] == 2.);
    }
    std::cout << "OK" << std::endl;

    Dvector y(x);
    assert(y.size() == 3);
    for (int i = 0; i < x.size(); i++)
    {
        assert(y.coords()[i] == 2.);
    }
    std::cout << "OK" << std::endl;
    
    std::string fileName = "test.txt";
    Dvector a(fileName);
    assert(a.size() == 6);
    std::cout << "OK" << std::endl;
    for (int i = 0; i < 6; i++)
    {   
        assert(a.coords()[i] == (i+1)/10.);
    }
    std::cout << "OK" << std::endl;

    std::stringstream str;
    x.display(str);
    assert(str.str() == "2\n2\n2\n");
    std::cout << "OK" << std::endl;

    return 0;
}



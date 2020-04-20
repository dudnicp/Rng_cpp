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


    std::cout << "Test operator () : " << std::endl;
    assert(c(1) == 2.0);
    c(1) = 3.0;
    assert(c(1) = 3.0);
    std::cout << "OK" << std::endl;
    

    std::cout << "Test operator = :" << std::endl;
    Dvector v = Dvector(3, 2);
    Dvector w = Dvector();
    w = v;
    assert(w.size() == 3);
    v(1) = 3;
    for (int i = 0; i < 3; i++)
    {
        assert(w(i) == 2);
    }
    std::cout << "Ok" << std::endl;

    v(1) = 2;


    std::cout << "Test operator == :" << std::endl;
    assert(v == w);
    v(1) = 3;
    assert(!(v == w));
    std::cout << "OK" << std::endl;

    v(1) = 2;


    Dvector x = Dvector(3, 0);

    std::cout << "Test operator += :" << std::endl;
    x += 1;
    assert(x.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(x(i) == 1);
    }
    x += v;
    assert(x.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(x(i) == 3);
    }
    std::cout << "Ok" << std::endl;
    

    std::cout << "Test operator -= :" << std::endl;
    x -= 1;
    assert(x.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(x(i) == 2);
    }
    x -= v;
    assert(x.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(x(i) == 0);
    }
    std::cout << "Ok" << std::endl;


    std::cout << "Test operator -= :" << std::endl;
    x = Dvector(3, 1);
    x *= 2;
    assert(x.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(x(i) == 2);
    }
    std::cout << "Ok" << std::endl;


    std::cout << "Test operator -= :" << std::endl;
    x /= 2;
    assert(x.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(x(i) == 1);
    }
    std::cout << "Ok" << std::endl;


    Dvector y = Dvector();

    std::cout << "Test operator + :" << std::endl;
    y = v + w;
    assert(y.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(y(i) == 4);
    }
    y = v + 1;
    assert(y.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(y(i) == 3);
    }
    std::cout << "Ok" << std::endl;


    std::cout << "Test operator - :" << std::endl;
    y = v - w;
    assert(y.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(y(i) == 0);
    }
    y = v - 1;
    assert(y.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(y(i) == 1);
    }
    std::cout << "Ok" << std::endl;


    std::cout << "Test operator * :" << std::endl;
    y = v * 3;
    assert(y.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(y(i) == 6);
    }
    std::cout << "Ok" << std::endl;


    std::cout << "Test operator / :" << std::endl;
    y = v / 2;
    assert(y.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(y(i) == 1);
    }
    std::cout << "Ok" << std::endl;


    std::cout << "Test operator unary - :" << std::endl;
    y = -y;
    assert(y.size() == 3);
    for (int i = 0; i < 3; i++)
    {
        assert(y(i) == -1);
    }
    std::cout << "Ok" << std::endl;


    std::cout << "Test operator << " << std::endl;
    std::stringstream str2;
    str2 << v;
    assert(str2.str() == "2\n2\n2\n");
    std::cout << "Ok" << std::endl;


    std::cout << "Test operator >> " << std::endl;
    std::stringstream str3("3 3 3");
    str3 >> v;
    for (int i = 0; i < 3; i++)
    {
        assert(v(i) == 3);
    }
    std::cout << "Ok" << std::endl;


    std::cout << "Test resize() : " << std::endl;
    w.resize(2, 3);
    assert(w.size() == 2);
    for (int i = 0; i < 2; i++)
    {
        assert(w(i) == 2);
    }
    w.resize(3,3);
    assert(w.size() == 3);
    for (int i = 0; i < 2; i++)
    {
        assert(w(i) == 2);
    }
    assert(w(2) == 3);
    std::cout << "Ok" << std::endl;

    return EXIT_SUCCESS;

}



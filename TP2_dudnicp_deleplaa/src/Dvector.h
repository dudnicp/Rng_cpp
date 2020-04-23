#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>
#include <random>
#include <fstream>
#include <ostream>
#include <string>
#include <sstream>

class Dvector {
    private:
        double *m_coords;
        int m_size;
    
    public:
        Dvector();
        Dvector(int size);
        Dvector(int size, double val);
        Dvector(const Dvector &other);
        Dvector(std::string fileName);
        ~Dvector();
        void display(std::ostream &str) const;
        int size() const;
        double* coords() const;
        void fillRandomly();
        void resize(int newSize, double val);

        bool operator==(const Dvector& other);

        double& operator()(const int i);

        Dvector& operator=(const Dvector &other);

        Dvector& operator+=(const double x);
        Dvector& operator+=(const Dvector &other);

        Dvector& operator-=(const double x);
        Dvector& operator-=(const Dvector &other);

        Dvector& operator*=(const double x);
        Dvector& operator/=(const double x);

        Dvector operator-(); 
};

Dvector operator+(const Dvector& v, const double x);
Dvector operator+(const Dvector& v1, const Dvector& v2);

Dvector operator-(const Dvector& v, const double x);
Dvector operator-(const Dvector& v1, const Dvector& v2);

Dvector operator*(const Dvector& v, const double x);
Dvector operator/(const Dvector& v, const double x);

std::ostream& operator<<(std::ostream& stream, const Dvector& v);
std::istream& operator>>(std::istream& stream, Dvector& v);


#endif
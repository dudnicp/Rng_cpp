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
        Dvector(Dvector &other);
        Dvector(std::string fileName);
        ~Dvector();
        void display(std::ostream &str) const;
        int size() const;
        double* coords() const;
        void fillRandomly();
};

#endif
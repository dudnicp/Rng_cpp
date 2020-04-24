#include <exception>

class InvalidSeed : public std::exception
{
public:
    virtual const char* what(void) const throw();
};

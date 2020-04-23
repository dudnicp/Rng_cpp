#include "InvalidSeed.h"

const char* InvalidSeed::what() const throw() {
    return "Invalid seed";
}
/**
 * \file TestDisplay.cpp
 * \brief Tests de la fonction display() de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestDispay

#include <boost/test/unit_test.hpp>
#include <sstream>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(display)
{
    std::stringstream str;
    Dvector v(3, 2.);
    v.display(str);
    BOOST_CHECK_EQUAL(str.str(), "2\n2\n2\n");
}
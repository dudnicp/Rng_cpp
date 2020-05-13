/**
 * \file TestOStreamOperator.cpp
 * \brief Test sur l'opérateur << de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestOStreamOperator

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

#include <sstream>

BOOST_AUTO_TEST_CASE(basic)
{
    std::stringstream str;
    str << Dvector(3, 2.);
    BOOST_CHECK_EQUAL(str.str(), "2\n2\n2\n");
}

BOOST_AUTO_TEST_CASE(chained)
{
    std::stringstream str;
    str << Dvector(3, 2.) << Dvector(3, 2.);
    BOOST_CHECK_EQUAL(str.str(), "2\n2\n2\n2\n2\n2\n");
}

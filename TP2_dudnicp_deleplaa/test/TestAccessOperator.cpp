/**
 * \file TestAccessOperator.cpp
 * \brief Tests sur l'opérateur () de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestAccessOperator

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(read_access)
{
    Dvector v(3, 2);
    for (int i = 0; i < 3; i++)
    {
        BOOST_CHECK_EQUAL(v(i), 2.);
    }
}

BOOST_AUTO_TEST_CASE(write_access)
{
    Dvector v(3, 2);
    v(1) = 3.;
    BOOST_CHECK_EQUAL(v(1), 3);
}

BOOST_AUTO_TEST_CASE(invalid_access)
{
    Dvector v(3, 2.);
    BOOST_CHECK_THROW(v(-1), std::out_of_range);
    BOOST_CHECK_THROW(v(3), std::out_of_range);
}

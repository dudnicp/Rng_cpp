/**
 * \file TestResize.cpp
 * \brief Tests sur la méthode resize de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestResize

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(same_size)
{
    Dvector v(3, 2.);
    v.resize(3, 3.);
    BOOST_CHECK_EQUAL(v, Dvector(3, 2.));
}

BOOST_AUTO_TEST_CASE(bigger_size)
{
    Dvector v(3, 2.);
    v.resize(5, 3.);
    BOOST_CHECK_EQUAL(v(0), 2.);
    BOOST_CHECK_EQUAL(v(1), 2.);
    BOOST_CHECK_EQUAL(v(2), 2.);
    BOOST_CHECK_EQUAL(v(3), 3.);
    BOOST_CHECK_EQUAL(v(4), 3.);
}

BOOST_AUTO_TEST_CASE(null_size)
{
    Dvector v(3);
    v.resize(0);
    BOOST_CHECK_EQUAL(v, Dvector());
}

BOOST_AUTO_TEST_CASE(invalid_size)
{
    Dvector v(3);
    BOOST_CHECK_THROW(v.resize(-1), std::invalid_argument);
}

/**
 * \file TestIStreamOperator.cpp
 * \brief Tests sur l'opérateur >> de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestIStreamOperator

#include <boost/test/unit_test.hpp>
#include <sstream>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(equal_sizes) {
    std::stringstream str("1. 1. 1.");
    Dvector v(3);
    str >> v;
    BOOST_CHECK_EQUAL(v, Dvector(3, 1.));
}

BOOST_AUTO_TEST_CASE(greater_size) {
    std::stringstream str("1. 1. 1. 1.");
    Dvector v(3);
    str >> v;
    BOOST_CHECK_EQUAL(v, Dvector(3, 1.));
}

BOOST_AUTO_TEST_CASE(inferior_size) {
    std::stringstream str("1. 1.");
    Dvector v(3);
    str >> v;
    BOOST_CHECK_EQUAL(v(0), 1.);
    BOOST_CHECK_EQUAL(v(1), 1.);
    BOOST_CHECK_EQUAL(v(2), 0.);
}

BOOST_AUTO_TEST_CASE(stream_chain)
{
    std::stringstream str("1. 1. 1. 1.");
    Dvector a(2);
    Dvector b(2);
    str >> a;
    str >> b;
    BOOST_CHECK_EQUAL(a, Dvector(2, 1.));
    BOOST_CHECK_EQUAL(b, Dvector(2, 1.));
}

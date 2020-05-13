/**
 * \file TestSizeValueConstructor.cpp
 * \brief Tests du constructeur taille + valeur de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestSizeValueConstructor

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(size_default_value) {
    Dvector v(3);
    BOOST_CHECK_EQUAL(v.size(), 3);
    BOOST_CHECK(v.coords() != nullptr);
    for (int i = 0; i < 3; i++)
    {
        BOOST_CHECK_EQUAL(v.coords()[i], 0);
    }
}

BOOST_AUTO_TEST_CASE(size_value) {
    Dvector v(3, 2.);
    BOOST_CHECK_EQUAL(v.size(), 3);
    BOOST_CHECK(v.coords() != nullptr);
    for (int i = 0; i < 3; i++)
    {
        BOOST_CHECK_EQUAL(v.coords()[i], 2.);
    }
}

BOOST_AUTO_TEST_CASE(null_size) {
    Dvector v(0);
    BOOST_CHECK_EQUAL(v.size(), 0);
    BOOST_CHECK(v.coords() == nullptr);
}

BOOST_AUTO_TEST_CASE(invalid_size) {
    BOOST_CHECK_THROW(Dvector(-1), std::invalid_argument);
}

/**
 * \file TestCopyConstructor.cpp
 * \brief Tests du constructeur par copie de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestCopyConstructor

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(empty_vect_copy)
{
    Dvector v0;
    Dvector v(v0);
    BOOST_CHECK_EQUAL(v.size(), 0);
    BOOST_CHECK_EQUAL(v.coords(), nullptr);
}

BOOST_AUTO_TEST_CASE(vect_copy)
{
    Dvector v0(3, 2.);
    Dvector v(v0);
    BOOST_CHECK_EQUAL(v.size(), 3);
    BOOST_CHECK_NE(v.coords(), nullptr);
    for (int i = 0; i < 3; i++)
    {
        BOOST_CHECK_EQUAL(v.coords()[i], 2.);
    }
}
/**
 * \file TestMinusOperator.cpp
 * \brief Tests sur l'opérateur - binaire de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestMinusOperator

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(double_subtraction)
{
    BOOST_CHECK_EQUAL(Dvector(3, 2.) - 3., Dvector(3, -1.));
}

BOOST_AUTO_TEST_CASE(vect_subtraction)
{
    BOOST_CHECK_EQUAL(Dvector(3, 2.) - Dvector(3, 3.), Dvector(3, -1.));
}

BOOST_AUTO_TEST_CASE(invalid_subtraction)
{
    BOOST_CHECK_THROW(Dvector(3, 2.) - Dvector(4, 2.), std::domain_error);
}


/**
 * \file TestPlusOperator.cpp
 * \brief Tests sur l'opérateur + de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestPlusOperator

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(double_addition)
{
    BOOST_CHECK_EQUAL(Dvector(3, 2.) + 3, Dvector(3, 5.));
}

BOOST_AUTO_TEST_CASE(vect_addition)
{
    BOOST_CHECK_EQUAL(Dvector(3, 2.) + Dvector(3, 3.), Dvector(3, 5.));
}

BOOST_AUTO_TEST_CASE(invalid_addition)
{
    BOOST_CHECK_THROW(Dvector(3, 2.) + Dvector(4, 2.), std::domain_error);
}

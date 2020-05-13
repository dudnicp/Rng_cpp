/**
 * \file TestUnaryMinusOperator.cpp
 * \brief Tests sur l'opérateur - unaire de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestUnaryMinusOperator

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(minus)
{
    BOOST_CHECK_EQUAL(-Dvector(3, 2.), Dvector(3, -2.));
}

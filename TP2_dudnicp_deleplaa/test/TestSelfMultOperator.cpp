/**
 * \file TestSelfMultOperator.cpp
 * \brief Test sur l'opérateur *= de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestSelfMultOperator

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(real_multiplication)
{
    BOOST_CHECK_EQUAL(Dvector(3, 2.) *= 3, Dvector(3, 6.));
}

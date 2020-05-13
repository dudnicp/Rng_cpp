/**
 * \file TestDivOperator.cpp
 * \brief Test sur l'opérateur / de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestDivOperator

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(real_division)
{
    BOOST_CHECK_EQUAL(Dvector(3, 2.) / 3., Dvector(3, 2. / 3.));
}

BOOST_AUTO_TEST_CASE(zero_division)
{
    BOOST_CHECK_THROW(Dvector(3, 2.) / 0, std::domain_error);
}
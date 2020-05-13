/**
 * \file TestEqualityOperator.cpp
 * \brief Tests sur l'opérateur == de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestEqualityOperator

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(equal)
{
    BOOST_CHECK(Dvector(3, 2.) == Dvector(3, 2.));    // Test Dvector == Dvector true
    BOOST_CHECK(!(Dvector(3, 2.) == Dvector(4, 2.))); // Test Dvector == Dvector false (taille)
    BOOST_CHECK(!(Dvector(3, 2.) == Dvector(3, 3.))); // Test Dvector == Dvector false (coordonnées)
    BOOST_CHECK(Dvector() == Dvector());              // Test Dvector == Dvector true (Dvectors nulls)
    BOOST_CHECK(!(Dvector() == Dvector(3, 2.)));      // Test Dvector == Dvector false (Dvector null)
}

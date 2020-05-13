/**
 * \file TestAffectationOperator.cpp
 * \brief Tests sur l'opérateur d'affectation de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestAffectationOperator

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(affectation)
{
    Dvector v;
    BOOST_CHECK_EQUAL(v = Dvector(3, 2.), Dvector(3, 2.));                  // Test affectation vecteur
    BOOST_CHECK_EQUAL(v = Dvector(), Dvector());                            // Test affectation vecteur null
    BOOST_CHECK_EQUAL(v = Dvector(3, 2.) = Dvector(4, 5.), Dvector(4, 5.)); // Test affectations chainées
}

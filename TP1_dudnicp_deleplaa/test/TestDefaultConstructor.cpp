/**
 * \file TestDefaultConstructor.cpp
 * \brief Tests du constructeur par défaut de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestDefaultConstructor

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(default_constructor)
{
    Dvector v;
    BOOST_CHECK_EQUAL(v.size(), 0);
    BOOST_CHECK_EQUAL(v.coords(), nullptr);
}

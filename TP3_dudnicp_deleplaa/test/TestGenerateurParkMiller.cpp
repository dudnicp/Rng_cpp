/**
 * \file TestGenerateurParkMiller.cpp
 * \brief Tests sur le générateur aléatoire de Park-Miller
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestsGenerateurParkMiller

#include <boost/test/unit_test.hpp>
#include "GenerateurParkMiller.h"

BOOST_AUTO_TEST_CASE(dim_constructor)
{
    GenerateurParkMiller g(3);
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 1llu);
    BOOST_CHECK_THROW(GenerateurParkMiller(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(copy_constructor)
{
    GenerateurParkMiller g0(3);
    GenerateurParkMiller g(g0);
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 1llu);
}

BOOST_AUTO_TEST_CASE(set_dim)
{
    GenerateurParkMiller g(3);
    g.set_dim(1);
    BOOST_CHECK_EQUAL(g.get_dim(), 1);
    BOOST_CHECK_THROW(g.set_dim(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(set_seed)
{
    GenerateurParkMiller g(1);
    g.set_seed(10);
    BOOST_CHECK_EQUAL(g.get_seed(), 10llu);
    BOOST_CHECK_THROW(g.set_seed(0xffffffff), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(assigment_operator)
{
    GenerateurParkMiller g0(3);
    g0.set_seed(3);
    GenerateurParkMiller g(1);
    g = g0;
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 3llu);
}

BOOST_AUTO_TEST_CASE(clone_)
{
    GenerateurParkMiller g0(3);
    g0.set_seed(3);
    GenerateurParkMiller g(1);
    g.clone(g0);
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 3llu);
}

BOOST_AUTO_TEST_CASE(reset_seed)
{
    GenerateurParkMiller g(3);
    g.set_seed(3);
    g.reset_seed();
    BOOST_CHECK_EQUAL(g.get_seed(), 1llu);
}

BOOST_AUTO_TEST_CASE(get_max)
{
    GenerateurParkMiller g(3);
    BOOST_CHECK_EQUAL(g.get_max(), (uint64_t)INT32_MAX);
}

BOOST_AUTO_TEST_CASE(generate)
{
    GenerateurParkMiller g(4);
    uint64_t *data = g.generate();
    BOOST_CHECK_EQUAL(data[0], 16807llu);
    BOOST_CHECK_EQUAL(data[1], 282475249llu);
    BOOST_CHECK_EQUAL(data[2], 1622650073llu);
    BOOST_CHECK_EQUAL(data[3], 984943658llu);

    delete[] data;
}
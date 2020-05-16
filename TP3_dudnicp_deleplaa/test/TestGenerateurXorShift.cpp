/**
 * \file TestGenerateurXorShift.cpp
 * \brief Tests sur le générateur aléatoire XorShift
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestsGenerateurXorShift

#include <boost/test/unit_test.hpp>
#include "GenerateurXorShift.h"

BOOST_AUTO_TEST_CASE(dim_constructor)
{
    GenerateurXorShift g(3);
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 1llu);
    BOOST_CHECK_THROW(GenerateurXorShift(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(copy_constructor)
{
    GenerateurXorShift g0(3);
    GenerateurXorShift g(g0);
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 1llu);
}

BOOST_AUTO_TEST_CASE(set_dim)
{
    GenerateurXorShift g(3);
    g.set_dim(1);
    BOOST_CHECK_EQUAL(g.get_dim(), 1);
    BOOST_CHECK_THROW(g.set_dim(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(set_seed)
{
    GenerateurXorShift g(1);
    g.set_seed(10);
    BOOST_CHECK_EQUAL(g.get_seed(), 10llu);
}

BOOST_AUTO_TEST_CASE(assignment_operator)
{
    GenerateurXorShift g0(3);
    g0.set_seed(3);
    GenerateurXorShift g(1);
    g = g0;
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 3llu);
}

BOOST_AUTO_TEST_CASE(clone_)
{
    GenerateurXorShift g0(3);
    g0.set_seed(3);
    GenerateurXorShift g(1);
    g.clone(g0);
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 3llu);
}

BOOST_AUTO_TEST_CASE(reset_seed)
{
    GenerateurXorShift g(3);
    g.set_seed(3);
    g.reset_seed();
    BOOST_CHECK_EQUAL(g.get_seed(), 1llu);
}

BOOST_AUTO_TEST_CASE(get_max)
{
    GenerateurXorShift g(3);
    BOOST_CHECK_EQUAL(g.get_max(), UINT64_MAX);
}

BOOST_AUTO_TEST_CASE(generate)
{
    GenerateurXorShift g(4);
    uint64_t *data = g.generate();
    BOOST_CHECK_EQUAL(data[0], 33685761llu);
    BOOST_CHECK_EQUAL(data[1], 1125917087301641llu);
    BOOST_CHECK_EQUAL(data[2], 868093111971292453llu);
    BOOST_CHECK_EQUAL(data[3], 13510906257080325llu);

    delete[] data;
}

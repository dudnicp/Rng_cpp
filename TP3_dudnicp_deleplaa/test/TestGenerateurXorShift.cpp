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

BOOST_AUTO_TEST_CASE(TestDimConstructor)
{
    GenerateurXorShift g(3);
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 1);
}

BOOST_AUTO_TEST_CASE(TestCopyConstructor)
{
    GenerateurXorShift g0(3);
    GenerateurXorShift g(g0);
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 1);
}

BOOST_AUTO_TEST_CASE(TestSetDim)
{
    GenerateurXorShift g(3);
    g.set_dim(1);
    BOOST_CHECK_EQUAL(g.get_dim(), 1);
}

BOOST_AUTO_TEST_CASE(TestSetSeed)
{
    GenerateurXorShift g(1);
    g.set_seed(10);
    BOOST_CHECK_EQUAL(g.get_seed(), 10);
}

BOOST_AUTO_TEST_CASE(TestAssignmentOperator)
{
    GenerateurXorShift g0(3);
    g0.set_seed(3);
    GenerateurXorShift g(1);
    g = g0;
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 3);
}

BOOST_AUTO_TEST_CASE(TestClone) {
    GenerateurXorShift g0(3);
    g0.set_seed(3);
    GenerateurXorShift g(1);
    g.clone(g0);
    BOOST_CHECK_EQUAL(g.get_dim(), 3);
    BOOST_CHECK_EQUAL(g.get_seed(), 3);
}

BOOST_AUTO_TEST_CASE(TestResetSeed) {
    GenerateurXorShift g(3);
    g.set_seed(3);
    g.reset_seed();
    BOOST_CHECK_EQUAL(g.get_seed(), 1);
}

BOOST_AUTO_TEST_CASE(TestGetMax) {
    GenerateurXorShift g(3);
    BOOST_CHECK_EQUAL(g.get_max(), UINT64_MAX);
}

BOOST_AUTO_TEST_CASE(TestGenerate) {
    GenerateurXorShift g(4);
    uint64_t* data = g.generate();
    BOOST_CHECK_EQUAL(data[0], 33685761);
    BOOST_CHECK_EQUAL(data[1], 1125917087301641);
    BOOST_CHECK_EQUAL(data[2], 868093111971292453);
    BOOST_CHECK_EQUAL(data[3], 13510906257080325);

    delete[] data;
}

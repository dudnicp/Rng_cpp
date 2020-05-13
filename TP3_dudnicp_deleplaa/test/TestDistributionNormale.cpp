/**
 * \file TestDistributionNormale.cpp
 * \brief Tests sur les distributions normales
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestDistributionNormale

#include <boost/test/unit_test.hpp>
#include "DistributionNormale.h"


BOOST_AUTO_TEST_CASE(default_constructor)
{
    DistributionNormale d;
    BOOST_CHECK_EQUAL(d.mean(), 0.);
    BOOST_CHECK_EQUAL(d.stdev(), 1.);
}

BOOST_AUTO_TEST_CASE(mean_stdev_constructor)
{
    DistributionNormale d(3., 2.);
    BOOST_CHECK_EQUAL(d.mean(), 3.);
    BOOST_CHECK_EQUAL(d.stdev(), 2.);
}

BOOST_AUTO_TEST_CASE(copy_constructor)
{
    DistributionNormale d0(3., 2.);
    DistributionNormale d(d0);
    BOOST_CHECK_EQUAL(d.mean(), 3.);
    BOOST_CHECK_EQUAL(d.stdev(), 2.);
}

BOOST_AUTO_TEST_CASE(assigment_operator)
{
    DistributionNormale d0(3., 2.);
    DistributionNormale d;
    d = d0;
    BOOST_CHECK_EQUAL(d.mean(), 3.);
    BOOST_CHECK_EQUAL(d.stdev(), 2.);
}

BOOST_AUTO_TEST_CASE(var)
{
    DistributionNormale d(3., 2.);
    BOOST_CHECK_EQUAL(d.var(), 4.);
}

BOOST_AUTO_TEST_CASE(pdf)
{
    DistributionNormale d;
    BOOST_CHECK_CLOSE(d.pdf(-2.), 0.05399, 0.01);
    BOOST_CHECK_CLOSE(d.pdf(-1.), 0.24197, 0.01);
    BOOST_CHECK_CLOSE(d.pdf(0.), 0.39894, 0.01);
    BOOST_CHECK_CLOSE(d.pdf(1.), 0.24197, 0.01);
    BOOST_CHECK_CLOSE(d.pdf(2.), 0.05399, 0.01);
}

BOOST_AUTO_TEST_CASE(cdf)
{
    DistributionNormale d;
    BOOST_CHECK_CLOSE(d.cdf(-2.), 0.02275, 0.01);
    BOOST_CHECK_CLOSE(d.cdf(-1.), 0.15865, 0.01);
    BOOST_CHECK_CLOSE(d.cdf(0.), 0.5, 0.01);
    BOOST_CHECK_CLOSE(d.cdf(1.), 0.84134, 0.01);
    BOOST_CHECK_CLOSE(d.cdf(2.), 0.97725, 0.01);
}

BOOST_AUTO_TEST_CASE(inv_cdf)
{
    DistributionNormale d;
    BOOST_CHECK_CLOSE(d.inv_cdf(0.1), -1.28155, 0.01);
    BOOST_CHECK_CLOSE(d.inv_cdf(0.25), -0.67449, 0.01);
    BOOST_CHECK_CLOSE(d.inv_cdf(0.5), 0., 0.01);
    BOOST_CHECK_CLOSE(d.inv_cdf(0.75), 0.67449, 0.01);
    BOOST_CHECK_CLOSE(d.inv_cdf(0.9), 1.28155, 0.01);
}

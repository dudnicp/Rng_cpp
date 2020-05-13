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
#include <boost/math/distributions/normal.hpp>

// Distribution normale de boost prise comme référence
using boost::math::pdf;
using boost::math::cdf;
using boost::math::quantile;
using boost::math::normal_distribution;
using boost::math::complement;


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

BOOST_AUTO_TEST_CASE(pdf_)
{
    DistributionNormale d;
    normal_distribution<double> ref;
    for (double i = -3.; i < 4.; i += 1.)
    {
        BOOST_CHECK_CLOSE(d.pdf(i), pdf(ref, i), 0.01);
    }
}

BOOST_AUTO_TEST_CASE(cdf_)
{
    DistributionNormale d;
    normal_distribution<double> ref;
    for (double i = -3.; i < 4.; i += 1.)
    {
        BOOST_CHECK_CLOSE(d.cdf(i), cdf(ref, i), 0.01);
    }
}

BOOST_AUTO_TEST_CASE(inv_cdf_)
{
    DistributionNormale d;
    normal_distribution<double> ref;
    for (double i = 0.5; i > 0.001; i /= 2.)
    {
        BOOST_CHECK_CLOSE(d.inv_cdf(i), quantile(ref, i), 0.01);
        BOOST_CHECK_CLOSE(d.inv_cdf(1. - i), quantile(complement(ref, i)), 0.01);
    }
    
}

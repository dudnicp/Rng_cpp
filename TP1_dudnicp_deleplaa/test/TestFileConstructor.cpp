/**
 * \file TestFileConstructor.cpp
 * \brief Tests du constructeur par fichier de la classe Dvector
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#define BOOST_TEST_MODULE TestFileConstructor

#include <boost/test/unit_test.hpp>
#include "Dvector.h"

BOOST_AUTO_TEST_CASE(empty_init)
{
    Dvector v("EmptyInit.txt");
    BOOST_CHECK_EQUAL(v.size(), 0);
    BOOST_CHECK_EQUAL(v.coords(), nullptr);
}

BOOST_AUTO_TEST_CASE(file_init)
{
    std::string files[3];;
    files[0] = "LineBreakInit.txt";
    files[1] = "SpaceInit.txt";
    files[2] = "ComplexInit.txt";

    for (int i = 0; i < 3; i++)
    {
        Dvector v(files[i]);
        BOOST_CHECK_EQUAL(v.size(), 6);
        BOOST_CHECK_NE(v.coords(), nullptr);

        for (int j = 0; j < 6; j++)
        {
            BOOST_CHECK_EQUAL(v.coords()[j], j / 10.);
        }
    }
}

BOOST_AUTO_TEST_CASE(invalid_init)
{
    BOOST_CHECK_THROW(Dvector(""), std::invalid_argument);
}
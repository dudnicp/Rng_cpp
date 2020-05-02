#ifndef MYTEST_H
#define MYTEST_H

#include <iostream>

/**
 * \file MyTest.h
 * \brief Ensemble de fonctions pour l'automatisation des tests unitaires
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

/**
 * \brief Teste l'égalité entre deux valeurs
 * \param arg0 Une valeur à comparer
 * \param arg1 Une autre valeur à comparer
 */
template<typename T>
void TEST_EQ(T arg0, T arg1) {
    if (arg0 != arg1)
    {
        exit(EXIT_FAILURE)
    }
}

/**
 * \brief Teste l'inégalité entre deux valeurs
 * \param arg0 Une valeur à comparer
 * \param arg1 Une autre valeur à comparer
 */
template<typename T>
void TEST_NEQ(T arg0, T arg1) {
    if (arg0 == arg1)
    {
        exit(EXIT_FAILURE)
    }
}

#endif
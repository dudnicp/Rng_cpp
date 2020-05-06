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
 * \param[in] arg0 Une valeur à comparer
 * \param[in] arg1 Une autre valeur à comparer
 * \attention Nécessite la définition de l'opérateur != des objets comparés
 */
template <typename T1, typename T2>
void TEST_EQ(const T1 &arg0, const T2 &arg1)
{
    if (arg0 != arg1)
    {
        exit(EXIT_FAILURE);
    }
}

/**
 * \brief Teste l'inégalité entre deux valeurs
 * \param[in] arg0 Une valeur à comparer
 * \param[in] arg1 Une autre valeur à comparer
 * \attention Nécessite la définition de l'opérateur == des objets comparés
 */
template <typename T1, typename T2>
void TEST_NEQ(const T1 &arg0, const T2 &arg1)
{
    if (arg0 == arg1)
    {
        exit(EXIT_FAILURE);
    }
}

#endif
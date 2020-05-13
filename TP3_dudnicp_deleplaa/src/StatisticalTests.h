/**
 * \file StatisticalTests.h
 * \brief Prototypes de fonctions relatives aux tests statistiques
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

#ifndef STATISTICALTESTS_H
#define STATISTICALTESTS_H

/**
 * \brief Calcule la valeur moyenne d'un tableau
 * \param[in] data Un tableau de valeurs
 * \param[in] n La taille du tableau
 * \return La valeur moyenne d'un tableau
 * \throw invalid_argument Si n < 1
double mean(const double* data, const int n);

/**
 * \brief Calcule la valeur d'une variable de loi Chi2
 * \param[in] obtained Le tableau des valeurs obtenues
 * \param[in] expected Le tableau des valeurs attendues
 * \param[in] n La taille des tableaux
 * \return La valeur du chi2 obtenues en comparant les valeurs obtenues avec les valeurs attendues
 * \throw invalid_argument Si n < 1
 */
double chi2(const double* obtained, const double *expected, const int n);

/**
 * \brief Calcule la valeur d'une variable de Kolmogorov-Smirnov à partir des données fournies
 * \param[in] data Le tableau des données obtenues
 * \param[in] n La taille du tableau
 * \return La valeur de la variable de Kolmogorov-Smirnov obtenue à partir des données fournies
 * \throw invalid_argument Si n < 1000 (il faut beaucoup de valeurs pour une valeur significative)
 */
double KS(const double* data, const int n);

/**
 * \brief Calcule la valeur du Chi2 pour un tableau de valeurs supposées uniformes
 * \param[in] data Le tableau de valeurs
 * \param[in] n La taille du tableau
 * \return La valeur du chi2 obtenue en comparant les données obtenues aux données uniformes attendues
 * \throw invalid_argument Si n < 1000 (il faut beaucoup de valeurs pour une valeur significative)
 */
double uniformDistributionChi2(const double* data, const int n);

/**
 * \brief Calcule la valeur du Chi2 pour un tableau de valeurs supposées de loi normale
 * \param[in] data Le tableau de valeurs
 * \param[in] n La taille du tableau
 * \return La valeur du chi2 obtenue en comparant les données obtenues aux données normales attendues
 * \throw invalid_argument Si n < 1000 (il faut beaucoup de valeurs pour une valeur significative)
 */
double normalDistributionChi2(const double* data, const int n);

/**
 * \brief Calcule l'autocorrélation entre les données d'un tableau
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \return Une valeur suivant une loi normale centrée réduite
 * \throw invalid_argument Si n < 1000 (il faut beaucoup de valeurs pour une valeur significative)
 */
double autocorrelationNormalVar(const double* data, const int n);

/**
 * \brief Calcule la valeur d'une variable aléatoire obtenue à partir du nombre de runs up and down d'un tableau de valeurs supposées uniformes
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \return Une valeur suivant une loi normale centrée réduite
 * \throw invalid_argument Si n < 1000 (il faut beaucoup de valeurs pour une valeur significative)
 */
double runsUDNumberNormalVar(const double* data, const int n);

/**
 * \brief Calcule la valeur d'une variable aléatoire obtenue à partir du nombre de runs au dessus et en dessous de la moyenne d'un tableau de valeurs 
 * \brief supposées uniformes
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \return Une valeur suivant une loi normale centrée réduite
 * \throw invalid_argument Si n < 1000 (il faut beaucoup de valeurs pour une valeur significative)
 */
double runsABMNumberNormalVar(const double* data, const int n);

/**
 * \brief Calcule la valeur du Chi2 obtenue à partir de la taille des runs up and down d'un tableau de valeurs supposées uniformes
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \return La valeur du Chi2 obtenue en comparant les tailles des runs up and down aus tailles attendues
 * \throw invalid_argument Si n < 20 ou n > 100 (l'utilisation de factorielles et de puissances impose de limiter n)
 */
double runsUDLengthChi2(const double* data, const int n);

/**
 * \brief Calcule la valeur du Chi2 obtenue à partir de la taille des runs au dessus et en dessous de la moyenne d'un tableau de valeurs supposées uniformes
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \return La valeur du Chi2 obtenue en comparant les tailles des runs au dessus et en dessous aus tailles attendues
 * \throw invalid_argument Si n < 20 ou n > 100 (l'utilisation de factorielles et de puissances impose de limiter n)
 */
double runsABMLengthChi2(const double* data, const int n);

#endif

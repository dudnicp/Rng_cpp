#ifndef STATISTICALTESTS_H
#define STATISTICALTESTS_H

/**
 * \file StatisticalTests.h
 * \brief Fonctions pour tests statistiques
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

/**
 * \brief Effectue un test du Chi2 pour tester l'adéquation entre une série de valeurs obtenues et celles attendues
 * \param[in] obtained Le tableau des valeurs obtenues
 * \param[in] expected Le tableau des valeurs attendues
 * \param[in] n La taille des tableaux de valeurs
 * \param[in] alpha La p-value necessaire pour passer le test (par défaut 0.05)
 */
void chiSquaredTest(const double* obtained, const double *expected, const int n, const double alpha = 0.05);

/**
 * \brief Vérifie qu'une valeur suit bien une loi normale centrée
 * \param[in] z La valeur z à tester
 * \param[in] alpha La p-value nécessaire pour passer le test (par défaut 0.05)
 */
void stdNormalTest(const double z, const double alpha = 0.05);

/**
 * \brief Vérifie que les valeurs d'un tableau suivent une loi uniforme sur [0,1] via la méthode de Kolmogorov-Smirnov
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \throw runtime_error Si n < 1000 (il faut beaucoup de valeurs pour un test significatif)
 */
void uniformFrequencyKSTest(const double* data, const int n);

/**
 * \brief Vérifie que les valeurs d'un tableau suivent une loi uniforme sur [0,1] via la méthode du Chi2
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \throw runtime_error Si n < 1000 (il faut beaucoup de valeurs pour un test significatif)
 */
void uniformFrequencyChiSquaredTest(const double* data, const int n);

/**
 * \brief Vérifie que les valeurs d'un tableau suivent une loi normale centré réduite via la méthode du Chi2
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \throw runtime_error Si n < 1000 (il faut beaucoup de valeurs pour un test significatif)
 */
void normalFrequencyChiSquaredTest(const double* data, const int n);

/**
 * \brief Vérifie qu'il n'y a pas d'auto-corrélation entre les valeurs d'un tableau
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \throw runtime_error Si n < 1000 (il faut beaucoup de valeurs pour un test significatif)
 */
void autocorrelationTest(const double* data, const int n);

/**
 * \brief Vérifie si les valeurs d'un tableau sont vraiment aléatoires en testant le de runs up and down
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \throw runtime_error Si n < 1000 (il faut beaucoup de valeurs pour un test significatif)
 */
void runsUDNumberTest(const double* data, const int n);

/**
 * \brief Vérifie si les valeurs d'un tableau sont vraiment aléatoires en testant le nombre de runs au dessus et en dessous de la moyenne
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \throw runtime_error Si n < 1000 (il faut beaucoup de valeurs pour un test significatif)
 */
void runsABMNumberTest(const double* data, const int n);

/**
 * \brief Vérifie si les valeurs d'un tableau sont vraiment aléatoires en testant la taille des runs up and down
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \throw runtime_error Si n < 1000 (il faut beaucoup de valeurs pour un test significatif)
 */
void runsUDLengthTest(const double* data, const int n);

/**
 * \brief Vérifie si les valeurs d'un tableau sont vraiment aléatoires via en testant la taille des runs au dessus et en dessous de la moyenne
 * \param[in] data Le tableau à tester
 * \param[in] n La taille du tableau
 * \throw runtime_error Si n < 1000 (il faut beaucoup de valeurs pour un test significatif)
 */
void runsABMLengthTest(const double* data, const int n);

#endif

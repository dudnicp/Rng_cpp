#ifndef MATHFUNC_H
#define MATHFUNC_H

/**
 * \file MathFunc.h
 * \brief Fonctions mathématiques
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */


/**
 * \brief Calcule la moyenne d'un tableau de valeurs
 * \param[in] data Un tableau de valeurs
 * \param[in] n La taille du tableau
 * \return La moyenne du tableau
 */
double mean(const double* data, const int n);

/**
 * \brief Fonction Factorielle
 * \param[in] n Un entier
 * \return n!
 * \throw domain_error Si n est négatif
 */
int factorial(const int n);

/**
 * \brief Fonction gamma
 * \param[in] x Un réel strictement positif tel que 2*x soit entier
 * \return La valeur de la fonction gamma au point x
 * \throw domain_error Si x est <= 0 ou si 2*x n'est pas entier
 */
double G(const double x);

/**
 * \brief Fonction Densité de probabilité de la loi du chi2
 * \param[in] x Un réel positif
 * \param[in] df Le nombre de degrés de liberté de la loi
 * \return La densité de probabilité de la loi du chi2 à df degrés de liberté au point x
 * \throw domain_error si x < 0 ou df <= 0;
 */
 double chi2Pdf(const double x, const int df);

 /**
 * \brief Fonction de répartition de la loi du chi2
 * \param[in] x Un réel positif
 * \param[in] df Le nombre de degrés de liberté de la loi
 * \return La valeur de la fonction de répartition de la loi du chi2 à df degrés de liberté au point x
 * \throw domain_error si x < 0 ou df <= 0;
 */
double chi2Cdf(const double x, const int df);

#endif
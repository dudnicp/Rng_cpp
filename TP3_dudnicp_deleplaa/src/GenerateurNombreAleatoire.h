#ifndef GENERATEURNOMBREALEATOIRE_H
#define GENERATEURNOMBREALEATOIRE_H

#include <cstdint>

/**
 * \file GenerateurNombreAleatoire.h
 * \brief Générateur de nombres entiers aléatoires
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */

/**
 * \class GenerateurNombreAleatoire
 * \brief Générateur de nombres entiers aléatoires
 */
class GenerateurNombreAleatoire
{
protected:
    int m_dim; ///< taille du générateur (nombre de coordonnées aléatoires générées)

public:

    /**
     * \brief Crée un générateur aléatoire de la taille spécifiée
     * \param[in] dim La taille du générateur
     * \throw invalid_argument Si la dimension spécifiée est < 1
     */
    GenerateurNombreAleatoire(const int dim);

    /**
     * \brief Detruit le générateur aléatoire libérant la mémoire
     */
    virtual ~GenerateurNombreAleatoire();

    /**
     * \brief Crée un générateur aléatoire identique au générateur spécifié
     * \param[in] other Le générateur à recopier
     */
    GenerateurNombreAleatoire(const GenerateurNombreAleatoire &other);

    /**
     * \brief Modifie ce générateur en recopiant les valeurs du générateur spécifié
     * \param[in] other Le générateur à recopier
     * \return Une référence sur ce générateur (après recopie)
     */
    GenerateurNombreAleatoire& operator=(const GenerateurNombreAleatoire &other);

    /**
     * \brief Modifie la taille du générateur
     * \param[in] dim La nouvelle taille du générateur
     * \throw invalid_argument si la taille spécifiée est < 1
     */
    void set_dim(const int dim);

    /**
     * \brief Accesseur de la taille du générateur
     * \return La taille du générateur
     */
    int get_dim() const;

    /**
     * \brief Identique à \see operator=
     */
    void clone(const GenerateurNombreAleatoire &other);

    /**
     * \brief Renvoie le plus grand nombre pouvant être généré
     * \return Le plus grand nombre pouvant être généré
     */
    virtual uint64_t get_max() const = 0;

    /**
     * \brief Modifie la graine du générateur
     * \param[in] seed La nouvelle graine du générateur
     * \throw invalid_argument Si la graine spécifiée n'est pas une graine valide du générateur
     */
    virtual void set_seed(const uint64_t seed) = 0;

    /**
     * \brief Accesseur à la graine du générateur
     * \return La graine du générateur
     */
    virtual uint64_t get_seed() const = 0;

    /**
     * \brief Modifie la graine du générateur en la réinitialisant à sa valeur par défaut
     */
    virtual void reset_seed() = 0;

    /**
     * \brief Renvoie un tableau de nombre aléatoires de la taille du générateur
     */
    virtual uint64_t* generate() = 0;
};

#endif
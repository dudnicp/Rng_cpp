#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>

/**
 * \file Dvector.h
 * \brief Vecteur de doubles
 * \author Paul Dudnic & Adrien Deleplace
 * \version 1.0
 * \date 19/05/2020
 */


/**
 * \class Dvector
 * \brief Classe de vecteurs de doubles
 * 
 * Classe permettant la manipulation de vecteurs de doubles : initialisation, remplissage, affichage
 */
class Dvector {
    private:
        int m_size; ///< Dimension du vecteur (nombre de coordonnées)
        double *m_coords; ///< Coordonnées du vecteur 
    
    public:
        /**
         * \brief Construit un Dvector de taille nulle
         */
        Dvector();

        /**
         * \brief Construit un Dvector de la taille spécifié, dont toutes les coordonnées ont la même valeur spécifiée (par défaut 0) 
         * \param[in] size La taille désirée du Dvector
         * \param[in] val La valeur désirée des coordonnées (0 par défaut)
         * \throw invalid_argument Si la taille spécifiée est < 0
         */
        Dvector(const int size, const double val = 0.);

        /**
         * \brief Construit un Dvector identique au Dvector spécifié
         * \param[in] other Le Dvector à copier
         */
        Dvector(const Dvector &other);

        /**
         * \brief Construit un Dvector à partir des données contenues dans le fichier spécifié
         * \param[in] fileName Le fichier contenant les données d'initialisation
         * \throw invalid_argument Si le fichier spécifié ne peut pas être ouvert
         */
        Dvector(const std::string fileName);

        /** 
         * \brief Détruit le Dvector en libérant la mémoire
         */
        ~Dvector();

        /**
         * \brief Affiche les coordonnées du Dvector dans le flux spécifié
         * \param[out] str Le flux dans lequel afficher le Dvector
         */
        void display(std::ostream &str) const;

        /**
         * \brief Accesseur de l'attribut m_size
         * \return La dimension du Dvector
         */
        int size() const;

        /**
         * \brief Accesseur de l'attribut m_coords
         * \return Un tableau contenant les coordonnées du Dvector
         */
        double* coords() const;

        /**
         * \brief Rempli les coordonnées du Dvector de valeurs aléatoires suivant une distribution uniforme dans le ségment [0,1]
         */
        void fillRandomly();
};

#endif
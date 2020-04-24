#ifndef DVECTOR_H
#define DVECTOR_H

#include <string>

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
         * \brief Constructeur par défaut
         * 
         * Construit un vecteur de dimension nulle
         */
        Dvector();

        /**
         * \brief Constructeur 
         * \param[in] size La taille désirée du vecteur
         * \param[in] val La valeur désirée des coordonnées (0 par défaut)
         * 
         * Construit un vecteur de la taille spécifié, dont toutes les coordonnées ont la même valeur spécifiée (par défaut 0)
         */
        Dvector(int size, double val = 0);

        /**
         * \brief Constructeur par copie
         * \param[in] other Le vecteur à copier
         * 
         * Construit un vecteur identique au vecteur spécifié
         */
        Dvector(const Dvector &other);

        /**
         * \brief Constructeur
         * \param[in] fileName Le fichier d'initialisation
         * 
         * Construit un vecteur à partir des données contenues dans le fichier spécifié.
         */
        Dvector(std::string fileName);

        /** 
         * \brief Destructeur
         * 
         * Détruit le vecteur en libérant la mémoire
         */
        ~Dvector();

        /**
         * \brief Affiche le vecteur dans un flux
         * \param[out] str Le flux dans lequel afficher le vecteur
         * 
         * Affiche les coordonnées du vecteur dans le flux spécifié
         */
        void display(std::ostream &str) const;

        /**
         * \brief Accesseur de l'attribut m_size
         * \return La dimension du vecteur
         * 
         * Renvoie la dimension du vecteur
         */
        int size() const;

        /**
         * \brief Accesseur de l'attribut m_coords
         * \return Les coordonnées du vecteur
         * 
         * Renvoie le tableau constituant les coordonnées du vecteur
         */
        double* coords() const;

        /**
         * \brief Rempli le vecteur de valeurs aléatoires
         * 
         * Modifie les coordonnées du vecteur en leur assignant des valeurs aléatoires suivant une distribution uniforme dans le segment [0,1]
         */
        void fillRandomly();
};

#endif
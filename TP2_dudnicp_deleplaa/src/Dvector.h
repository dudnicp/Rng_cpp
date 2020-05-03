#ifndef DVECTOR_H
#define DVECTOR_H

#include <iostream>
#include <random>
#include <fstream>
#include <ostream>
#include <string>
#include <sstream>

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
        double *m_coords;
        int m_size;

        /**
         * \brief Modifie la taille du Dvector
         * \param[in] newSize La nouvelle taille du Dvector
         * \throw invalid_argument Si la nouvelle taille est < 0
         */
        void setSize(const int newSize);
    
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
        Dvector(std::string fileName);

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


        /**
         * \brief Modifie la taille du Dvector et assigne une valeur spécifiée (par défaut 0) 
         * \brief aux nouvelles coordonnées si la nouvelle taille est supérieure à la précédente
         * \param[in] newSize La nouvelle taille du Dvector
         * \param[in] val La valeur des nouvelles coordonnées (par défaut 0)
         * \throw invalid_argument Si la nouvelle taille est < 0
         */
        void resize(const int newSize, const double val = 0.);

        /**
         * \brief Teste l'égalité entre le Dvector et un autre
         * \param[in] other Un Dvector
         * \return true si le Dvector est égal au Dvector spécifié, false sinon
         */
        bool operator==(const Dvector &other) const;

         /**
         * \brief Teste l'inégalité entre le Dvector et un autre
         * \param[in] other Un Dvector
         * \return false si le Dvector est égal au Dvector spécifié, true sinon
         */
        bool operator!=(const Dvector &other) const;

        /**
         * \brief Accède à la coordonnée d'indice spécifié du Dvetor
         * \param[in] i L'indice de la coordonnée désirée
         * \return Une référence sur la coordonnée d'indice spécifié du Dvector
         * \throw out_of_range Si l'indice spécifié est < 0 ou > à la taille du Dvector
         */
        double& operator()(const int i) const;

        /**
         * \brief Affecte au Dvector la taille et les coordonnées d'un autre Dvector
         * \param[in] other Le Dvector à recopier
         * \return Une référence sur le Dvector (après recopie)
         */
        Dvector& operator=(const Dvector &other);

        /**
         * \brief Additionne une constante à toutes les coordonnées du Dvector
         * \param[in] x La constante à ajouter
         * \return Une référence sur le Dvector (après addition)
         */
        Dvector& operator+=(const double x);

        /**
         * \brief Additionne les coordonnées d'un Dvector spécifié à celles du Dvector
         * \param[in] other Le Dvector à ajouter
         * \return Une référence sur le Dvector (après addition)
         * \throw domain_error Si les deux Dvectors ne sont pas de la même taille
         */
        Dvector& operator+=(const Dvector &other);

        /**
         * \brief Soustrait une constante à toutes les coordonnées du Dvector
         * \param[in] x La constante à soustraire
         * \return Une référence sur le Dvector (après soustraction)
         */
        Dvector& operator-=(const double x);

        /**
         * \brief Soustrait les coordonnées d'un Dvector spécifié avec celles du Dvector 
         * \param[in] other Le Dvector à soustraire
         * \return Une référence sur le Dvector (après addition)
         * \throw domain_error Si les deux Dvectors ne sont pas de la même taille
         */
        Dvector& operator-=(const Dvector &other);

        /**
         * \brief Multiplie toutes les coordonénes du Dvector par une constante
         * \param[in] x La constante multiplicatrice
         * \return Une référence sur le Dvector (après multiplication)
         */
        Dvector& operator*=(const double x);

        /**
         * \brief Divise toutes les coordonénes du Dvector par une constante
         * \param[in] x Le diviseur
         * \return Une référence sur le Dvector (après division)
         * \throw domain_error Si le diviseur est 0
         */
        Dvector& operator/=(const double x);
};

/**
 * \brief Calcule l'addition d'un Dvector et d'une constante
 * \param[in] v Le Dvector à additionner
 * \param[in] x La constante à additionner
 * \return Un Dvector dont les coordonnées sont la somme des coordonnées du Dvector spécifié et de la constante
 */
Dvector operator+(const Dvector& v, const double x);

/**
 * \brief Calcule l'addition de deux Dvectors
 * \param[in] v1 Un Dvector à additionner
 * \param[in] v2 Un autre Dvector à additionner
 * \return Un Dvector dont les coordonnées sont la somme des coordonnées des deux Dvector spécifiés
 * \throw domain_error Si les deux Dvectors n'ont pas la même taille
 */
Dvector operator+(const Dvector& v1, const Dvector& v2);

/**
 * \brief Calcule la soustraction d'un Dvector et d'une constante
 * \param[in] v Le Dvector à soustraire
 * \param[in] x La constante à soustraire
 * \return Un Dvector dont les coordonnées sont la soustraction des coordonnées du Dvector spécifié et de la constante
 */
Dvector operator-(const Dvector& v, const double x);

/**
 * \brief Calcule la soustraction de deux Dvectors
 * \param[in] v1 Un Dvector à soustraire
 * \param[in] v2 Un autre Dvector à soustraire
 * \return Un Dvector dont les coordonnées sont la soustraction des coordonnées des deux Dvector spécifiés
 * \throw domain_error Si les deux Dvectors n'ont pas la même taille
 */
Dvector operator-(const Dvector& v1, const Dvector& v2);

/**
 * \brief Calcule la multiplication d'un Dvector par une constante
 * \param[in] v Le Dvector à multiplier
 * \param[in] x La constante multiplicatrice
 * \return Un Dvector dont les coordonnées sont la multiplication des coordonnées du Dvector spécifié par la constante
 */
Dvector operator*(const Dvector& v, const double x);

/**
 * \brief Calcule la division d'un Dvector par une constante
 * \param[in] v Le Dvector à Diviser
 * \param[in] x Le diviseur
 * \return Un Dvector dont les coordonnées sont la division des coordonnées du Dvector spécifié par la constante
 * \throw domain_error Si le diviseur est 0
 */
Dvector operator/(const Dvector& v, const double x);

/**
 * \brief Calcule l'opposé d'un Dvector
 * \param[in] v Le Dvector à opposer
 * \return Un Dvector dont les coordonnées sont les opposées des coordonnées du Dvector spécifié
 */
Dvector operator-(const Dvector& v); 

/**
 * \brief Écrit un Dvector dans un flux
 * \param[inout] stream Le flux dans lequel écrire le Dvector
 * \param[in] v Le Dvector à écrire dans le flux
 * \return Une référence sur le flux après écriture
 */
std::ostream& operator<<(std::ostream& stream, const Dvector& v);

/**
 * \brief Ecrit les données d'un flux dans les coordonnées d'un Dvector
 * \param[inout] stream Le flux contenant les données à écrire
 * \param[in] v Le Dvector dans lequel écrire les données
 * \return Une référence sur le flux après écriture
 */
std::istream& operator>>(std::istream& stream, Dvector& v);


#endif
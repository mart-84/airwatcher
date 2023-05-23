/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ----------------
#if !defined(MESURE_H)
#define MESURE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class Mesure
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    Mesure &operator=(const Mesure &autreMesure);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Mesure(const Mesure &autreMesure);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Mesure();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Mesure(string day, int val);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Mesure();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string date;
    int valeur;
};

//-------------------------------- Autres définitions dépendantes de <Mesure>

#endif // MESURE_H

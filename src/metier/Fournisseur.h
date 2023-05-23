/*************************************************************************
                           Fournisseur  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Fournisseur> (fichier Fournisseur.h) ----------------
#if !defined(FOURNISSEUR_H)
#define FOURNISSEUR_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include "Purificateur.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Fournisseur>
//
//
//------------------------------------------------------------------------

class Fournisseur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    string getIdentifiant();

    Purificateur *getPurificateur();

    void setIdentifiant(string id);

    void setPurificateur(Purificateur *purif);

    //------------------------------------------------- Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Fournisseur);

    Fournisseur &operator=(const Fournisseur &autreFournisseur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Fournisseur(const Fournisseur &autreFournisseur);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Fournisseur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Fournisseur(string id, Purificateur *purif);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Fournisseur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string identifiant;
    Purificateur *purificateur;
};

//-------------------------------- Autres définitions dépendantes de <Fournisseur>

#endif // FOURNISSEUR_H

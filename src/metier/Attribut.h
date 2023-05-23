/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if !defined(ATTRIBUT_H)
#define ATTRIBUT_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
//
//------------------------------------------------------------------------

class Attribut
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

    string getUnite();

    string getDescription();

    void setIdentifiant(string id);

    void setUnite(string u);

    void setDescription(string desc);

    //------------------------------------------------- Surcharge d'opérateurs
    Attribut &operator=(const Attribut &autreAttribut);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Attribut(const Attribut &autreAttribut);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Attribut();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Attribut(string id, string u, string desc);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Attribut();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- ATTRIBUTs protégés
    string identifiant;
    string unite;
    string description;
};

//-------------------------------- Autres définitions dépendantes de <Attribut>

#endif // ATTRIBUT_H

/*************************************************************************
                           Purificateur  -  description
                             -------------------
    début                : 23/05/2023 
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <Purificateur> (fichier Purificateur.h) ----------------
#if !defined(PURIFICATEUR_H)
#define PURIFICATEUR_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Purificateur>
//
//
//------------------------------------------------------------------------

class Purificateur
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
    Purificateur &operator=(const Purificateur &autrePurificateur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Purificateur(const Purificateur &autrePurificateur);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Purificateur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Purificateur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Purificateur>

#endif // PURIFICATEUR_H

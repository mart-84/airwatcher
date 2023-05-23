/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : 23/05/2023 
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               : 
*************************************************************************/

//---------- Interface de la classe <Particulier> (fichier Particulier.h) ----------------
#if !defined(PARTICULIER_H)
#define PARTICULIER_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Particulier>
//
//
//------------------------------------------------------------------------

class Particulier
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
    Particulier &operator=(const Particulier &autreParticulier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Particulier(const Particulier &autreParticulier);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Particulier();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Particulier();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Particulier>

#endif // PARTICULIER_H

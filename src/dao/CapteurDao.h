/*************************************************************************
                           CapteurDao  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <CapteurDao> (fichier CapteurDao.h) ----------------
#if !defined(CapteurDao_H)
#define CapteurDao_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CapteurDao>
//
//
//------------------------------------------------------------------------

class CapteurDao
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
    CapteurDao &operator=(const CapteurDao &autreCapteurDao);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    CapteurDao(const CapteurDao &autreCapteurDao);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    CapteurDao();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~CapteurDao();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <CapteurDao>

#endif // CapteurDao_H

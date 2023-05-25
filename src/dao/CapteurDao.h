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
#include <vector>
#include <string>
using namespace std;

#include "../metier/Capteur.h"
#include "Dao.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CapteurDao>
//
//
//------------------------------------------------------------------------

class CapteurDao : public Dao
{
    //----------------------------------------------------------------- PUBLIC

public:
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

    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Capteur *findById(const string &id);
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<Capteur> &findAll();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    vector<Capteur> m_capteurs;
};

//-------------------------------- Autres définitions dépendantes de <CapteurDao>

#endif // CapteurDao_H

/*************************************************************************
                           ParticulierDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <ParticulierDaoCsv> (fichier ParticulierDaoCsv.h) ----------------
#if !defined(PARTICULIERDAOCSV_H)
#define PARTICULIERDAOCSV_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;

#include "IParticulierDao.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ParticulierDaoCsv>
//
// Implémentation d'un Dao de Particulier sur des fichiers CSV
//------------------------------------------------------------------------

class ParticulierDaoCsv : public IParticulierDao
{
public:
    ParticulierDaoCsv();

    virtual ~ParticulierDaoCsv();

    //------------------------------------------------------------------ PRIVE
    virtual Particulier *findById(const string &id);

    virtual vector<Particulier *> &findAll();

protected:
    //----------------------------------------------------- Attributs protégés
    vector<Particulier *> particuliers;
};

//-------------------------------- Autres définitions dépendantes de <ParticulierDaoCsv>

#endif // PARTICULIERDAOCSV_H

/*************************************************************************
                           FournisseurDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <FournisseurDaoCsv> (fichier FournisseurDaoCsv.h) ----------------
#if !defined(FOURNISSEURDAOCSV_H)
#define FOURNISSEURDAOCSV_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
using namespace std;

#include "../IFournisseurDao.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <FournisseurDaoCsv>
//
// Implémentation d'un Dao de Fournisseur sur des fichiers CSV
//------------------------------------------------------------------------

class FournisseurDaoCsv : public IFournisseurDao
{
public:
    FournisseurDaoCsv();

    virtual ~FournisseurDaoCsv();

    virtual Fournisseur *findById(const string &);

    virtual vector<Fournisseur *> &findAll();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Attributs protégés
    vector<Fournisseur *> fournisseurs;
};

//-------------------------------- Autres définitions dépendantes de <FournisseurDaoCsv>

#endif // FOURNISSEURDAOCSV_H

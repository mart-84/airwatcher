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

#include <vector>
using namespace std;

#include "../IFournisseurDao.h"

//------------------------------------------------------------------------
// Rôle de la classe <FournisseurDaoCsv>
//
// Implémentation d'un Dao de Fournisseur sur des fichiers CSV
//------------------------------------------------------------------------

class FournisseurDaoCsv : public IFournisseurDao
{
public:
    FournisseurDaoCsv(const string &filename);

    virtual ~FournisseurDaoCsv();

    void associerPurificateurs(vector<Purificateur *> &purificateurs);
    // Mode d'emploi :
    // Utilise la liste des purificateurs créée par le Dao PurificateurDaoCsv pour faire l'association
    // entre les fournisseurs et leurs purificateurs.

    virtual Fournisseur *findById(const string &);

    virtual vector<Fournisseur *> &findAll();

protected:
    vector<Fournisseur *> fournisseurs;
    vector<string> purificateur_ids;
};

#endif // FOURNISSEURDAOCSV_H

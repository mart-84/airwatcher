/*************************************************************************
                           FakeFournisseurDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <FakeFournisseurDao> (fichier FakeFournisseurDao.h) ----------------
#if !defined(FAKEFOURNISSEURDAO_H)
#define FAKEFOURNISSEURDAO_H

#include <vector>
using namespace std;

#include "../../src/dao/IFournisseurDao.h"

//------------------------------------------------------------------------
// Rôle de la classe <FakeFournisseurDao>
//
//
//------------------------------------------------------------------------

class FakeFournisseurDao : public IFournisseurDao
{
public:
    FakeFournisseurDao();

    virtual ~FakeFournisseurDao();

    virtual Fournisseur *findById(const string &);

    virtual vector<Fournisseur *> &findAll();

    void addFournisseur(Fournisseur *fournisseur);

protected:
    vector<Fournisseur *> fournisseurs;
};

#endif // FAKEFOURNISSEURDAO_H

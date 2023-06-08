/*************************************************************************
                           FakePurificateurDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <FakePurificateurDao> (fichier FakePurificateurDao.h) ----------------
#if !defined(FAKEPURIFICATEURDAO_H)
#define FAKEPURIFICATEURDAO_H

#include <vector>
using namespace std;

#include "../../src/dao/IPurificateurDao.h"

//------------------------------------------------------------------------
// Rôle de la classe <FakePurificateurDao>
//
//
//------------------------------------------------------------------------

class FakePurificateurDao : public IPurificateurDao
{
public:
    FakePurificateurDao();

    virtual ~FakePurificateurDao();

    virtual Purificateur *findById(const string &);

    virtual vector<Purificateur *> &findAll();

    void addPurificateur(Purificateur *purificateur);

protected:
    vector<Purificateur *> purificateurs;
};

#endif // FAKEPURIFICATEURDAO_H

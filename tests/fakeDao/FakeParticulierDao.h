/*************************************************************************
                           FakeParticulierDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <FakeParticulierDao> (fichier FakeParticulierDao.h) ----------------
#if !defined(FAKEPARTICULIERDAO_H)
#define FAKEPARTICULIERDAO_H

#include <vector>
using namespace std;

#include "../../src/dao/IParticulierDao.h"

//------------------------------------------------------------------------
// Rôle de la classe <FakeParticulierDao>
//
//
//------------------------------------------------------------------------

class FakeParticulierDao : public IParticulierDao
{
public:
    FakeParticulierDao();

    virtual ~FakeParticulierDao();

    virtual void update(Particulier &);

    virtual Particulier *findById(const string &);

    virtual vector<Particulier *> &findAll();

    void addParticulier(Particulier *particulier);

protected:
    vector<Particulier *> particuliers;
};

#endif // FAKEPARTICULIERDAO_H

/*************************************************************************
                           FakeAttributDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <FakeAttributDao> (fichier FakeAttributDao.h) ----------------
#if !defined(FAKEATTRIBUTDAO_H)
#define FAKEATTRIBUTDAO_H

#include <vector>
using namespace std;

#include "../../src/dao/IAttributDao.h"

//------------------------------------------------------------------------
// Rôle de la classe <FakeAttributDao>
//
//
//------------------------------------------------------------------------

class FakeAttributDao : public IAttributDao
{
public:
    FakeAttributDao();

    virtual ~FakeAttributDao();

    virtual Attribut *findByName(const string &);

    virtual vector<Attribut *> &findAll();

    void addAttribut(Attribut *attribut);

protected:
    vector<Attribut *> attributs;
};

#endif // FAKEATTRIBUTDAO_H

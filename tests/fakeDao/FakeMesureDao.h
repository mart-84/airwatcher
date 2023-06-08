/*************************************************************************
                           FakeMesureDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <FakeMesureDao> (fichier FakeMesureDao.h) ----------------
#if !defined(FAKEMESUREDAO_H)
#define FAKEMESUREDAO_H

#include <vector>
using namespace std;

#include "../../src/dao/IMesureDao.h"

//------------------------------------------------------------------------
// Rôle de la classe <FakeMesureDao>
//
//
//------------------------------------------------------------------------

class FakeMesureDao : public IMesureDao
{
public:
    FakeMesureDao();

    virtual ~FakeMesureDao();

    vector<Mesure *> &findAll();

    void addMesure(Mesure *mesure);

protected:
    vector<Mesure *> mesures;
};

#endif // FAKEMESUREDAO_H

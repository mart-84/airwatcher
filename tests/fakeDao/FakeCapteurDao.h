/*************************************************************************
                           FakeCapteurDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <FakeCapteurDao> (fichier FakeCapteurDao.h) ----------------
#if !defined(FAKECAPTEURDAO_H)
#define FAKECAPTEURDAO_H

#include <vector>
using namespace std;

#include "../../src/dao/ICapteurDao.h"

//------------------------------------------------------------------------
// Rôle de la classe <FakeCapteurDao>
//
//
//------------------------------------------------------------------------

class FakeCapteurDao : public ICapteurDao
{
public:
    FakeCapteurDao();

    virtual ~FakeCapteurDao();

    virtual void update(Capteur &capteur);

    virtual Capteur *findById(const string &);

    virtual vector<Capteur *> &findAll();

    virtual vector<Capteur *> getCapteursZoneCirculaire(double latitude, double longitude, int rayon);

    void addCapteur(Capteur *capteur);

protected:
    vector<Capteur *> capteurs;
};

#endif // FAKECAPTEURDAO_H

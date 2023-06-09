/*************************************************************************
                           CapteurDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <CapteurDaoCsv> (fichier CapteurDaoCsv.h) ----------------
#if !defined(CAPTEURDAOCSV_H)
#define CAPTEURDAOCSV_H

using namespace std;

#include "../ICapteurDao.h"

//------------------------------------------------------------------------
// Rôle de la classe <CapteurDaoCsv>
//
// Implémentation d'un Dao de Capteur sur des fichiers CSV
//------------------------------------------------------------------------

class CapteurDaoCsv : public ICapteurDao
{
public:
    CapteurDaoCsv(const string &filename, const string &fBanned);

    virtual ~CapteurDaoCsv();

    virtual void update(Capteur &capteur);

    virtual Capteur *findById(const string &id);

    virtual vector<Capteur *> &findAll();

    virtual vector<Capteur*> getCapteursZoneCirculaire(double latitude, double longitude, int rayon);

protected:
    vector<Capteur *> capteurs;
    const string filenameBanned;
};

#endif // CAPTEURDAOCSV_H

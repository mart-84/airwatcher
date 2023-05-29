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

//--------------------------------------------------- Interfaces utilisées
using namespace std;

#include "../ICapteurDao.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CapteurDaoCsv>
//
// Implémentation d'un Dao de Capteur sur des fichiers CSV
//------------------------------------------------------------------------

class CapteurDaoCsv : public ICapteurDao
{
public:
    CapteurDaoCsv();

    virtual ~CapteurDaoCsv();

    //------------------------------------------------------------------ PRIVE
    virtual Capteur *findById(const string &id);

    virtual vector<Capteur *> &findAll();

protected:
    //----------------------------------------------------- Attributs protégés
    vector<Capteur *> capteurs;
};

#endif // CAPTEURDAOCSV_H

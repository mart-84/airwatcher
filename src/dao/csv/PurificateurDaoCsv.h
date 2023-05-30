/*************************************************************************
                           PurificateurDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <PurificateurDaoCsv> (fichier PurificateurDaoCsv.h) ----------------
#if !defined(PURIFICATEURDAOCSV_H)
#define PURIFICATEURDAOCSV_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
using namespace std;

#include "../IPurificateurDao.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PurificateurDaoCsv>
//
// Implémentation d'un Dao de Purificateur sur des fichiers CSV
//------------------------------------------------------------------------

class PurificateurDaoCsv : public IPurificateurDao
{
public:
    PurificateurDaoCsv(const string &filename);

    virtual ~PurificateurDaoCsv();

    //------------------------------------------------------------------ PRIVE
    virtual Purificateur *findById(const string &id);

    virtual vector<Purificateur *> &findAll();

protected:
    //----------------------------------------------------- Attributs protégés
    vector<Purificateur *> purificateurs;
};

#endif // PURIFICATEURDAOCSV_H

/*************************************************************************
                           MesureDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <MesureDaoCsv> (fichier MesureDaoCsv.h) ----------------
#if !defined(MESUREDAOCSV_H)
#define MESUREDAOCSV_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
using namespace std;

#include "../IMesureDao.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MesureDaoCsv>
//
// Implémentation d'un Dao de Mesure sur des fichiers CSV
//------------------------------------------------------------------------

class MesureDaoCsv : public IMesureDao
{
public:
    MesureDaoCsv();

    virtual ~MesureDaoCsv();

    //------------------------------------------------------------------ PRIVE
    virtual vector<Mesure *> &findAll();

protected:
    //----------------------------------------------------- Attributs protégés
    vector<Mesure *> mesures;
};

//-------------------------------- Autres définitions dépendantes de <MesureDaoCsv>

#endif // MESUREDAOCSV_H

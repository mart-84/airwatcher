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
    MesureDaoCsv(const string &filename);

    virtual ~MesureDaoCsv();

    void associerAttributs(vector<Attribut *> &attributs);
    // Mode d'emploi :
    // Utilise la liste des attributs créée par le Dao AttributDaoCsv pour faire l'association
    // entre les mesures et leurs attributs.

    void associerCapteurs(vector<Capteur *> &capteurs);
    // Mode d'emploi :
    // Utilise la liste des capteurs créée par le Dao CapteurDaoCsv pour faire l'association
    // entre les mesures et leurs capteurs.

    virtual vector<Mesure *> &findAll();

protected:
    //----------------------------------------------------- Attributs protégés
    vector<Mesure *> mesures;
    vector<string> attribut_ids;
    vector<string> capteur_ids;
};

//-------------------------------- Autres définitions dépendantes de <MesureDaoCsv>

#endif // MESUREDAOCSV_H

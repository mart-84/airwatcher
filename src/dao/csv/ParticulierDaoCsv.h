/*************************************************************************
                           ParticulierDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <ParticulierDaoCsv> (fichier ParticulierDaoCsv.h) ----------------
#if !defined(PARTICULIERDAOCSV_H)
#define PARTICULIERDAOCSV_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
using namespace std;

#include "../IParticulierDao.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ParticulierDaoCsv>
//
// Implémentation d'un Dao de Particulier sur des fichiers CSV
//------------------------------------------------------------------------

class ParticulierDaoCsv : public IParticulierDao
{
public:
    ParticulierDaoCsv(const string &filename);

    virtual ~ParticulierDaoCsv();

    void associerCapteurs(vector<Capteur *> &capteurs);
    // Mode d'emploi :
    // Utilise la liste des capteurs créée par le Dao CapteurDaoCsv pour faire l'association
    // entre les particuliers et leurs capteurs.

    //------------------------------------------------------------------ PRIVE
    virtual Particulier *findById(const string &id);

    virtual vector<Particulier *> &findAll();

protected:
    //----------------------------------------------------- Attributs protégés
    vector<Particulier *> particuliers;
    vector<string> capteur_ids;
};

//-------------------------------- Autres définitions dépendantes de <ParticulierDaoCsv>

#endif // PARTICULIERDAOCSV_H

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

#include <vector>
using namespace std;

#include "../IParticulierDao.h"

//------------------------------------------------------------------------
// Rôle de la classe <ParticulierDaoCsv>
//
// Implémentation d'un Dao de Particulier sur des fichiers CSV
//------------------------------------------------------------------------

class ParticulierDaoCsv : public IParticulierDao
{
public:
    ParticulierDaoCsv(const string &filename, const string &filenamePoint, const string &filenameBanned);

    virtual ~ParticulierDaoCsv();

    virtual void update(Particulier &particulier);

    void associerCapteurs(vector<Capteur *> &capteurs);
    // Mode d'emploi :
    // Utilise la liste des capteurs créée par le Dao CapteurDaoCsv pour faire l'association
    // entre les particuliers et leurs capteurs.

    virtual Particulier *findById(const string &id);

    virtual vector<Particulier *> &findAll();

protected:
    vector<Particulier *> particuliers;
    vector<string> capteur_ids;
    const string filenamePoint;
    const string filenameBanned;
};

#endif // PARTICULIERDAOCSV_H

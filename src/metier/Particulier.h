/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Particulier> (fichier Particulier.h) ----------------
#if !defined(PARTICULIER_H)
#define PARTICULIER_H

#include <string>
#include <vector>
using namespace std;

#include "Capteur.h"

class Capteur;

//------------------------------------------------------------------------
// Rôle de la classe <Particulier>
//
// Représente un particulier qui possède un ou plusieurs capteurs
//------------------------------------------------------------------------

class Particulier
{
public:
    string getIdentifiant();

    int getPoints();

    bool getEstBanni();

    vector<Capteur *> &getCapteurs();

    void setIdentifiant(string id);

    void setPoints(int pts);

    void setEstBanni(bool banni);

    void ajouterCapteur(Capteur *capt);

    void ajouterPoint();
    
    friend ostream &operator<<(ostream &, Particulier &);

    Particulier();

    Particulier(string id, int pts, bool banni);

    virtual ~Particulier();

protected:
    string identifiant;
    int points;
    bool estBanni;
    vector<Capteur *> capteurs;
};

#endif // PARTICULIER_H

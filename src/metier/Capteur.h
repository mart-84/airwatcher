/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ----------------
#if !defined(CAPTEUR_H)
#define CAPTEUR_H

#include <string>
#include <vector>
using namespace std;

#include "Mesure.h"
#include "Particulier.h"

class Mesure;
class Particulier;

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//
// Représente un capteur physique
//------------------------------------------------------------------------

class Capteur
{
public:
    string getIdentifiant();

    bool getEstFiable();

    double getLatitude();

    double getLongitude();

    vector<Mesure *> getMesures();

    Particulier *getProprietaire();

    void setIdentifiant(string id);

    void setEstFiable(bool fiable);

    void setLatitude(double lat);

    void setLongitude(double longi);

    void setProprietaire(Particulier *part);

    void ajouterMesure(Mesure *mesure);

    float calculerSimilarite(Capteur &capteur);

    bool estDansZoneCirculaire(double longitude, double latitude, int rayon);

    friend ostream &operator<<(ostream &, Capteur &);

    Capteur();

    Capteur(string id, bool fiable, double lat, double longi);

    virtual ~Capteur();

protected:
    string identifiant;
    bool estFiable;
    double latitude;
    double longitude;
    vector<Mesure *> mesures;
    Particulier *proprietaire = nullptr;
};

#endif // CAPTEUR_H

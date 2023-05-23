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

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <vector>
#include "Mesure.h"
#include "Particulier.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Mesure;
class Particulier;

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------

class Capteur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

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

    void setMesures(vector<Mesure *> mes);

    void setProprietaire(Particulier *part);

    void ajouterMesure(Mesure *mesure);

    int calculerSimilarite(Capteur &capteur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Capteur);

    Capteur &operator=(const Capteur &autreCapteur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Capteur(const Capteur &autreCapteur);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Capteur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Capteur(string id, bool fiable, double lat, double longi);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Capteur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string identifiant;
    bool estFiable;
    double latitude;
    double longitude;
    vector<Mesure *> mesures;
    Particulier *proprietaire;
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // CAPTEUR_H

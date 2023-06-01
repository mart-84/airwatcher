/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ----------------
#if !defined(MESURE_H)
#define MESURE_H

#include <string>
using namespace std;

#include "Attribut.h"
#include "Capteur.h"

class Capteur;

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
// Représente une mesure effectuée par un capteur pour un seul attribut à
// une date donnée
//------------------------------------------------------------------------

class Mesure
{
public:
    string getDate();

    double getValeur();

    Attribut *getAttribut();

    Capteur *getCapteur();

    void setDate(string day);

    void setValeur(double val);

    void setAttribut(Attribut *attr);

    void setCapteur(Capteur *capt);

    friend ostream &operator<<(ostream &, Mesure &);

    Mesure();

    Mesure(string day, double val, Attribut *attr, Capteur *capt);

    virtual ~Mesure();

protected:
    string date;
    double valeur;
    Attribut *attribut;
    Capteur *capteur;
};

#endif // MESURE_H

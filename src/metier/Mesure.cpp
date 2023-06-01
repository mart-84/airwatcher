/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

#include <iostream>
using namespace std;

#include "Mesure.h"

string Mesure::getDate()
{
    return date;
}

double Mesure::getValeur()
{
    return valeur;
}

Attribut *Mesure::getAttribut()
{
    return attribut;
}

Capteur *Mesure::getCapteur()
{
    return capteur;
}

void Mesure::setDate(string day)
{
    date = day;
}

void Mesure::setValeur(double val)
{
    valeur = val;
}

void Mesure::setAttribut(Attribut *attr)
{
    attribut = attr;
}

void Mesure::setCapteur(Capteur *capt)
{
    capteur = capt;
}

ostream &operator<<(ostream &os, Mesure &mesure)
{
    os << "date: " << mesure.date
       << ", valeur: " << mesure.valeur;
    if (mesure.attribut != nullptr)
    {
        os << ", attribut: " << mesure.attribut->getIdentifiant();
    }
    if (mesure.capteur != nullptr)
    {
        os << ", capteur:" << mesure.capteur->getIdentifiant();
    }
    return os;
} //----- Fin de operator <<

Mesure::Mesure()
{
#ifdef MAP
    cout << "Appel au constructeur de <Mesure> sur " << this << endl;
#endif
} //----- Fin de Mesure

Mesure::Mesure(string day, double val, Attribut *attr, Capteur *capt)
    : date(day), valeur(val), attribut(attr), capteur(capt)
{
#ifdef MAP
    cout << "Appel au constructeur de <Mesure> sur " << this << endl;
#endif

} //----- Fin de Mesure

Mesure::~Mesure()
{
#ifdef MAP
    cout << "Appel au destructeur de <Mesure> sur " << this << endl;
#endif
} //----- Fin de ~Mesure

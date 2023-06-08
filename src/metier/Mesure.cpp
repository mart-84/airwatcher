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

bool Mesure::compareDate(Mesure &mesure)
{
    int self_annee = stoi(date.substr(0, 4));
    int self_mois = stoi(date.substr(5, 2));
    int self_jour = stoi(date.substr(8, 2));
    int self_heure = stoi(date.substr(11, 2));
    int self_minute = stoi(date.substr(14, 2));

    int other_annee = stoi(mesure.date.substr(0, 4));
    int other_mois = stoi(mesure.date.substr(5, 2));
    int other_jour = stoi(mesure.date.substr(8, 2));
    int other_heure = stoi(mesure.date.substr(11, 2));
    int other_minute = stoi(mesure.date.substr(14, 2));

    return self_annee < other_annee || self_mois < other_mois || self_jour < other_jour || self_heure < other_heure || self_minute < other_minute;
}

int Mesure::compareDate(string other) {
    int self_annee = stoi(date.substr(0, 4));
    int self_mois = stoi(date.substr(5, 2));
    int self_jour = stoi(date.substr(8, 2));
    int self_heure = stoi(date.substr(11, 2));
    int self_minute = stoi(date.substr(14, 2));

    int other_annee = stoi(other.substr(0, 4));
    int other_mois = stoi(other.substr(5, 2));
    int other_jour = stoi(other.substr(8, 2));
    int other_heure = stoi(other.substr(11, 2));
    int other_minute = stoi(other.substr(14, 2));

    if (self_annee < other_annee) {
        return -1;
    } else if (self_annee > other_annee) {
        return 1;
    } else {
        if (self_mois < other_mois) {
            return -1;
        } else if (self_mois > other_mois) {
            return 1;
        } else {
            if (self_jour < other_jour) {
                return -1;
            } else if (self_jour > other_jour) {
                return 1;
            } else {
                if (self_heure < other_heure) {
                    return -1;
                } else if (self_heure > other_heure) {
                    return 1;
                } else {
                    if (self_minute < other_minute) {
                        return -1;
                    } else if (self_minute > other_minute) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }
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

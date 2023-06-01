/*************************************************************************
                           Purificateur  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Purificateur> (fichier Purificateur.cpp) ------------

#include <iostream>
using namespace std;

#include "Purificateur.h"

string Purificateur::getIdentifiant()
{
    return identifiant;
}

string Purificateur::getDateDebut()
{
    return dateDebut;
}

string Purificateur::getDateFin()
{
    return dateFin;
}

double Purificateur::getLatitude()
{
    return latitude;
}

double Purificateur::getLongitude()
{
    return longitude;
}

void Purificateur::setIdentifiant(string id)
{
    identifiant = id;
}

void Purificateur::setDateDebut(string date)
{
    dateDebut = date;
}

void Purificateur::setDateFin(string date)
{
    dateFin = date;
}

void Purificateur::setLatitude(double lat)
{
    latitude = lat;
}

void Purificateur::setLongitude(double longi)
{
    longitude = longi;
}

ostream &operator<<(ostream &os, Purificateur &purificateur)
{
    os << "id: " << purificateur.identifiant
       << ", date de debut: " << purificateur.dateDebut
       << ", date de fin: " << purificateur.dateFin
       << ", latitude: " << purificateur.latitude
       << ", longitude: " << purificateur.longitude;
    return os;
} //----- Fin de operator <<

Purificateur::Purificateur()
{
#ifdef MAP
    cout << "Appel au constructeur de <Purificateur> sur " << this << endl;
#endif
} //----- Fin de Purificateur

Purificateur::Purificateur(string unIdentifiant, string uneDateDebut, string uneDateFin, double uneLatitude, double uneLongitude)
    : identifiant(unIdentifiant), dateDebut(uneDateDebut), dateFin(uneDateFin), latitude(uneLatitude), longitude(uneLongitude)
{
#ifdef MAP
    cout << "Appel au constructeur de <Purificateur> sur " << this << endl;
#endif
} //----- Fin de Purificateur

Purificateur::~Purificateur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Purificateur> sur " << this << endl;
#endif
} //----- Fin de ~Purificateur

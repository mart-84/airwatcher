/*************************************************************************
                           Purificateur  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Purificateur> (fichier Purificateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Purificateur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Purificateur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

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

//------------------------------------------------- Surcharge d'opérateurs
ostream &operator<<(ostream &os, Purificateur purificateur)
{
    os << "Identifiant : " << purificateur.getIdentifiant()
       << " Date de debut : " << purificateur.getDateDebut()
       << " Date de fin : " << purificateur.getDateFin()
       << " Latitude : " << purificateur.getLatitude()
       << " Longitude : " << purificateur.getLongitude() << endl;
    return os;
}

Purificateur &Purificateur::operator=(const Purificateur &autrePurificateur)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Purificateur> sur " << this << " et " << &autrePurificateur << endl;
#endif
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Purificateur::Purificateur(const Purificateur &autrePurificateur)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Purificateur> sur " << this << " et " << &autrePurificateur << endl;
#endif
} //----- Fin de Purificateur (constructeur de copie)

Purificateur::Purificateur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Purificateur> sur " << this << endl;
#endif
} //----- Fin de Purificateur

Purificateur::Purificateur(string unIdentifiant, string uneDateDebut, string uneDateFin, double uneLatitude, double uneLongitude)
// Algorithme :
//
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

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

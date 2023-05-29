/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Capteur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Capteur::getIdentifiant()
{
    return identifiant;
}

bool Capteur::getEstFiable()
{
    return estFiable;
}

double Capteur::getLatitude()
{
    return latitude;
}

double Capteur::getLongitude()
{
    return longitude;
}

vector<Mesure *> Capteur::getMesures()
{
    return mesures;
}

Particulier *Capteur::getProprietaire()
{
    return proprietaire;
}

void Capteur::setIdentifiant(string id)
{
    identifiant = id;
}

void Capteur::setEstFiable(bool fiable)
{
    estFiable = fiable;
}

void Capteur::setLatitude(double lat)
{
    latitude = lat;
}

void Capteur::setLongitude(double longi)
{
    longitude = longi;
}

void Capteur::ajouterMesure(Mesure *mesure)
{
    mesures.push_back(mesure);
}

void Capteur::setProprietaire(Particulier *part)
{
    proprietaire = part;
}

float Capteur::calculerSimilarite(Capteur &capteur)
// Algorithme :
//
{
    return 0.0;
} //----- Fin de calculerSimilarite

//------------------------------------------------- Surcharge d'opérateurs
ostream &operator<<(ostream &os, Capteur &capteur)
{
    os << "id: " << capteur.identifiant
       << ", fiabilite: " << boolalpha << capteur.estFiable
       << ", latitude: " << capteur.latitude
       << ", longitude: " << capteur.longitude
       << ", proprietaire: ";
    if (capteur.proprietaire != nullptr)
    {
        os << capteur.proprietaire->getIdentifiant();
    }
    else
    {
        os << "agence gouvernementale";
    }
    os << ", nb mesure: " << capteur.mesures.size();

    return os;
}

Capteur &Capteur::operator=(const Capteur &autreCapteur)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Capteur> sur " << this << " et " << &autreCapteur << endl;
#endif
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
// Capteur::Capteur(const Capteur &autreCapteur)
// {
// #ifdef MAP
//     cout << "Appel au constructeur de copie de <Capteur> sur " << this << " et " << &autreCapteur << endl;
// #endif

// } //----- Fin de Capteur (constructeur de copie)

Capteur::Capteur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Capteur> sur " << this << endl;
#endif
} //----- Fin de Capteur

Capteur::Capteur(string id, bool fiable, double lat, double longi)
    : identifiant(id), estFiable(fiable), latitude(lat), longitude(longi)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Capteur> sur " << this << endl;
#endif
} //----- Fin de Capteur

Capteur::~Capteur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Capteur> sur " << this << endl;
#endif
} //----- Fin de ~Capteur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

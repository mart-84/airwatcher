/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Mesure::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Mesure::getDate()
{
    return date;
}

int Mesure::getValeur()
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

void Mesure::setValeur(int val)
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

//------------------------------------------------- Surcharge d'opérateurs
ostream &operator<<(ostream &os, Mesure mesure)
{
    os << "date: " << mesure.date << " valeur: " << mesure.valeur << " IDattribut: " << mesure.attribut->getIdentifiant() << " IDcapteur:" << mesure.capteur->getIdentifiant();
    return os;
}

Mesure &Mesure::operator=(const Mesure &autreMesure)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Mesure> sur " << this << " et " << &autreMesure << endl;
#endif
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure(const Mesure &autreMesure)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Mesure> sur " << this << " et " << &autreMesure << endl;
#endif
} //----- Fin de Mesure (constructeur de copie)

Mesure::Mesure()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Mesure> sur " << this << endl;
#endif
} //----- Fin de Mesure

Mesure::Mesure(string day, int val, Attribut &attr, Capteur &capt)
    : date(day), valeur(val), attribut(&attr), capteur(&capt)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Mesure> sur " << this << endl;
#endif

} //----- Fin de Mesure

Mesure::~Mesure()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Mesure> sur " << this << endl;
#endif
} //----- Fin de ~Mesure

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

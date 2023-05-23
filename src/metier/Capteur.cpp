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
using namespace std;
#include <iostream>

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

int Capteur::calculerSimilarite(Capteur &capteur)
// Algorithme :
//
{
} //----- Fin de calculerSimilarite

//------------------------------------------------- Surcharge d'opérateurs
Capteur &Capteur::operator=(const Capteur &autreCapteur)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Capteur> sur " << this << " et " << &autreCapteur << endl;
#endif
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Capteur::Capteur(const Capteur &autreCapteur)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Capteur> sur " << this << " et " << &autreCapteur << endl;
#endif
} //----- Fin de Capteur (constructeur de copie)

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

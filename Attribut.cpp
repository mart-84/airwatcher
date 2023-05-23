/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : 23/05/2023 
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih, Alexis
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Attribut::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Attribut &Attribut::operator=(const Attribut &autreAttribut)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Attribut> sur " << this << " et " << &autreAttribut << endl;
#endif
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Attribut::Attribut(const Attribut &autreAttribut)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Attribut> sur " << this << " et " << &autreAttribut << endl;
#endif
} //----- Fin de Attribut (constructeur de copie)

Attribut::Attribut()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribut> sur " << this << endl;
#endif
} //----- Fin de Attribut

Attribut::~Attribut()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribut> sur " << this << endl;
#endif
} //----- Fin de ~Attribut

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

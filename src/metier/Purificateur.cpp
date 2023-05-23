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

//------------------------------------------------- Surcharge d'opérateurs
Purificateur &Purificateur::operator=(const Purificateur &autrePurificateur)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Purificateur> sur " << this << " et " << &autrePurificateur << endl;
#endif
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

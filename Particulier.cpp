/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : 23/05/2023 
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih, Alexis
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Particulier> (fichier Particulier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Particulier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Particulier::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Particulier &Particulier::operator=(const Particulier &autreParticulier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Particulier> sur " << this << " et " << &autreParticulier << endl;
#endif
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Particulier::Particulier(const Particulier &autreParticulier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Particulier> sur " << this << " et " << &autreParticulier << endl;
#endif
} //----- Fin de Particulier (constructeur de copie)

Particulier::Particulier()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Particulier> sur " << this << endl;
#endif
} //----- Fin de Particulier

Particulier::~Particulier()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Particulier> sur " << this << endl;
#endif
} //----- Fin de ~Particulier

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

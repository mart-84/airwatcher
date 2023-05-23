/*************************************************************************
                           Fournisseur  -  description
                             -------------------
    début                : 23/05/2023 
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih, Alexis
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Fournisseur> (fichier Fournisseur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Fournisseur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Fournisseur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Fournisseur &Fournisseur::operator=(const Fournisseur &autreFournisseur)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Fournisseur> sur " << this << " et " << &autreFournisseur << endl;
#endif
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Fournisseur::Fournisseur(const Fournisseur &autreFournisseur)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Fournisseur> sur " << this << " et " << &autreFournisseur << endl;
#endif
} //----- Fin de Fournisseur (constructeur de copie)

Fournisseur::Fournisseur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Fournisseur> sur " << this << endl;
#endif
} //----- Fin de Fournisseur

Fournisseur::~Fournisseur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Fournisseur> sur " << this << endl;
#endif
} //----- Fin de ~Fournisseur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

/*************************************************************************
                           Fournisseur  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Fournisseur> (fichier Fournisseur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

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

string Fournisseur::getIdentifiant()
{
    return identifiant;
}

Purificateur *Fournisseur::getPurificateur()
{
    return purificateur;
}

void Fournisseur::setIdentifiant(string id)
{
    identifiant = id;
}

void Fournisseur::setPurificateur(Purificateur *purif)
{
    purificateur = purif;
}

//------------------------------------------------- Surcharge d'opérateurs
ostream &operator<<(ostream &os, Fournisseur &fournisseur)
{
    os << "id: " << fournisseur.identifiant
       << ", purificateur: " << fournisseur.purificateur;
    return os;
} //----- Fin de operator <<

Fournisseur &Fournisseur::operator=(const Fournisseur &autreFournisseur)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Fournisseur> sur " << this << " et " << &autreFournisseur << endl;
#endif
    return *this;
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

Fournisseur::Fournisseur(string id, Purificateur *purif)
    : identifiant(id), purificateur(purif)
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

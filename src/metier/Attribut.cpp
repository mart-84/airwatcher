/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
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

string Attribut::getIdentifiant()
{
    return identifiant;
}

string Attribut::getUnite()
{
    return unite;
}

string Attribut::getDescription()
{
    return description;
}

void Attribut::setIdentifiant(string id)
{
    identifiant = id;
}

void Attribut::setUnite(string u)
{
    unite = u;
}

void Attribut::setDescription(string desc)
{
    description = desc;
}

//------------------------------------------------- Surcharge d'opérateurs
ostream& operator<<(ostream & os, Attribut attr)
{
    os << attr.identifiant << " " << attr.unite << " " << attr.description;
    return os;
}

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

Attribut::Attribut(string id, string u, string desc)
    : identifiant(id), unite(u), description(desc)
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

/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

#include <iostream>
using namespace std;

#include "Attribut.h"

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

ostream &operator<<(ostream &os, Attribut &attr)
{
    os << "id: " << attr.identifiant
       << ", unité: " << attr.unite
       << ", description: " << attr.description;
    return os;
} //----- Fin de operator <<

Attribut::Attribut()
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribut> sur " << this << endl;
#endif
} //----- Fin de Attribut

Attribut::Attribut(string id, string u, string desc)
    : identifiant(id), unite(u), description(desc)
{
#ifdef MAP
    cout << "Appel au constructeur de <Attribut> sur " << this << endl;
#endif
} //----- Fin de Attribut

Attribut::~Attribut()
{
#ifdef MAP
    cout << "Appel au destructeur de <Attribut> sur " << this << endl;
#endif
} //----- Fin de ~Attribut

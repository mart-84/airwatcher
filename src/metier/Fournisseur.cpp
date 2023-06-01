/*************************************************************************
                           Fournisseur  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Fournisseur> (fichier Fournisseur.cpp) ------------

#include <iostream>
using namespace std;

#include "Fournisseur.h"

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

ostream &operator<<(ostream &os, Fournisseur &fournisseur)
{
    os << "id: " << fournisseur.identifiant;
    if (fournisseur.purificateur != nullptr)
    {
        os << ", purificateur: " << fournisseur.purificateur->getIdentifiant();
    }
    return os;
} //----- Fin de operator <<

Fournisseur::Fournisseur()
{
#ifdef MAP
    cout << "Appel au constructeur de <Fournisseur> sur " << this << endl;
#endif
} //----- Fin de Fournisseur

Fournisseur::Fournisseur(string id, Purificateur *purif)
    : identifiant(id), purificateur(purif)
{
#ifdef MAP
    cout << "Appel au constructeur de <Fournisseur> sur " << this << endl;
#endif
} //----- Fin de Fournisseur

Fournisseur::~Fournisseur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Fournisseur> sur " << this << endl;
#endif
} //----- Fin de ~Fournisseur

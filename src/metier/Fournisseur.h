/*************************************************************************
                           Fournisseur  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Fournisseur> (fichier Fournisseur.h) ----------------
#if !defined(FOURNISSEUR_H)
#define FOURNISSEUR_H

#include <string>
using namespace std;

#include "Purificateur.h"

//------------------------------------------------------------------------
// Rôle de la classe <Fournisseur>
//
// Représente un fournisseur de purificateur d'air
//------------------------------------------------------------------------

class Fournisseur
{
public:
    string getIdentifiant();

    Purificateur *getPurificateur();

    void setIdentifiant(string id);

    void setPurificateur(Purificateur *purif);

    friend ostream &operator<<(ostream &, Fournisseur &);

    Fournisseur();

    Fournisseur(string id, Purificateur *purif);

    virtual ~Fournisseur();

protected:
    string identifiant;
    Purificateur *purificateur;
};

#endif // FOURNISSEUR_H

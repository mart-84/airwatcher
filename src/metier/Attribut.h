/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if !defined(ATTRIBUT_H)
#define ATTRIBUT_H

#include <string>
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//
// Représente un attribut de qualité de l'air (O3, SO2, NO2, PM10, ...)
//------------------------------------------------------------------------

class Attribut
{
public:
    string getIdentifiant();

    string getUnite();

    string getDescription();

    void setIdentifiant(string id);

    void setUnite(string unite);

    void setDescription(string desc);

    friend ostream &operator<<(ostream &, Attribut &);

    Attribut();

    Attribut(string id, string unite, string desc);

    virtual ~Attribut();

protected:
    string identifiant;
    string unite;
    string description;
};

#endif // ATTRIBUT_H

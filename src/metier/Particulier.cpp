/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Particulier> (fichier Particulier.cpp) ------------

#include <iostream>
using namespace std;

#include "Particulier.h"

string Particulier::getIdentifiant()
{
    return identifiant;
}

int Particulier::getPoints()
{
    return points;
}

bool Particulier::getEstBanni()
{
    return estBanni;
}

vector<Capteur *> &Particulier::getCapteurs()
{
    return capteurs;
}

void Particulier::setIdentifiant(string id)
{
    identifiant = id;
}

void Particulier::setPoints(int pts)
{
    points = pts;
}

void Particulier::setEstBanni(bool banni)
{
    estBanni = banni;
}

void Particulier::ajouterCapteur(Capteur *capteur)
{
    capteurs.push_back(capteur);
}

void Particulier::ajouterPoint()
{
    if (!estBanni)
    {
        points++;
    }
}

ostream &operator<<(ostream &os, Particulier &particulier)
{
    os << boolalpha;
    os << "id: " << particulier.identifiant
       << ", points: " << particulier.points
       << ", banni: " << particulier.estBanni
       << ", capteurs: {";
    for (Capteur *capteur : particulier.getCapteurs())
    {
        os << capteur->getIdentifiant() << "; ";
    }
    os << "}";
    return os;
} //----- Fin de operator <<

Particulier::Particulier()
{
#ifdef MAP
    cout << "Appel au constructeur de <Particulier> sur " << this << endl;
#endif
} //----- Fin de Particulier

Particulier::Particulier(string id, int pts, bool banni)
    : identifiant(id), points(pts), estBanni(banni)
{
#ifdef MAP
    cout << "Appel au constructeur de <Particulier> sur " << this << endl;
#endif
} //----- Fin de Particulier

Particulier::~Particulier()
{
#ifdef MAP
    cout << "Appel au destructeur de <Particulier> sur " << this << endl;
#endif
} //----- Fin de ~Particulier

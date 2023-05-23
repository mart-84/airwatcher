/*************************************************************************
                           Particulier  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
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

vector<Capteur *> Particulier::getCapteurs()
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

//------------------------------------------------- Surcharge d'opérateurs
ostream &operator<<(ostream &os, Particulier particulier)
{
    os << "identifiant : " << particulier.identifiant
       << " points : " << particulier.points
       << " banni : " << particulier.estBanni
       << " capteurs : " << endl;
    for (int i = 0; i < particulier.capteurs.size(); i++)
    {
        os << "\t" << particulier.capteurs[i]->getIdentifiant() << endl;
    }
    return os;
} //----- Fin de operator <<

Particulier &Particulier::operator=(const Particulier &autreParticulier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Particulier> sur " << this << " et " << &autreParticulier << endl;
#endif
    return *this;
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

Particulier::Particulier(string id, int pts, bool banni)
    : identifiant(id), points(pts), estBanni(banni)
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

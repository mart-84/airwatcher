/*************************************************************************
                           FakeCapteurDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <FakeCapteurDao> (fichier FakeCapteurDao.cpp) ------------

#include <iostream>
using namespace std;

#include "FakeCapteurDao.h"

FakeCapteurDao::FakeCapteurDao()
{
#ifdef MAP
    cout << "Appel au constructeur de <FakeCapteurDao> sur " << this << endl;
#endif
} //----- Fin de FakeCapteurDao

FakeCapteurDao::~FakeCapteurDao()
{
#ifdef MAP
    cout << "Appel au destructeur de <FakeCapteurDao> sur " << this << endl;
#endif
} //----- Fin de ~FakeCapteurDao

void FakeCapteurDao::update(Capteur &capteur)
{
    for (auto c : capteurs)
    {
        if (c->getIdentifiant() == capteur.getIdentifiant())
        {
            c = &capteur;
        }
    }
} //----- Fin de update

Capteur *FakeCapteurDao::findById(const string &id)
{
    for (auto capteur : capteurs)
    {
        if (capteur->getIdentifiant() == id)
        {
            return capteur;
        }
    }
    return nullptr;
} //----- Fin de findById

vector<Capteur *> &FakeCapteurDao::findAll()
{
    return capteurs;
} //----- Fin de findAll

vector<Capteur *> FakeCapteurDao::getCapteursZoneCirculaire(double latitude, double longitude, int rayon)
{
    vector<Capteur *> capteursZoneCirculaire;
    for (auto capteur : capteurs)
    {
        if (capteur->estDansZoneCirculaire(latitude, longitude, rayon) && capteur->getEstFiable())
        {
            capteursZoneCirculaire.push_back(capteur);
        }
    }
    return capteursZoneCirculaire;
} //----- Fin de getCapteursZoneCirculaire

void FakeCapteurDao::addCapteur(Capteur *capteur)
{
    capteurs.push_back(capteur);
} //----- Fin de addCapteur
/*************************************************************************
                           FakeParticulierDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <FakeParticulierDao> (fichier FakeParticulierDao.cpp) ------------

#include <iostream>
using namespace std;

#include "FakeParticulierDao.h"

FakeParticulierDao::FakeParticulierDao()
{
#ifdef MAP
    cout << "Appel au constructeur de <FakeParticulierDao> sur " << this << endl;
#endif
} //----- Fin de FakeParticulierDao

FakeParticulierDao::~FakeParticulierDao()
{
#ifdef MAP
    cout << "Appel au destructeur de <FakeParticulierDao> sur " << this << endl;
#endif
} //----- Fin de ~FakeParticulierDao

void FakeParticulierDao::update(Particulier &particulier)
{
    for (auto p : particuliers)
    {
        if (p->getIdentifiant() == particulier.getIdentifiant())
        {
            p = &particulier;
        }
    }
} //----- Fin de update

void FakeParticulierDao::addParticulier(Particulier *particulier)
{
    particuliers.push_back(particulier);
} //----- Fin de addParticulier

Particulier *FakeParticulierDao::findById(const string &id)
{
    for (auto particulier : particuliers)
    {
        if (particulier->getIdentifiant() == id)
        {
            return particulier;
        }
    }
    return nullptr;
} //----- Fin de findById

vector<Particulier *> &FakeParticulierDao::findAll()
{
    return particuliers;
} //----- Fin de findAll

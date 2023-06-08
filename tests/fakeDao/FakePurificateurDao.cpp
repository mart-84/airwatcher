/*************************************************************************
                           FakePurificateurDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <FakePurificateurDao> (fichier FakePurificateurDao.cpp) ------------

#include <iostream>
using namespace std;

#include "FakePurificateurDao.h"

FakePurificateurDao::FakePurificateurDao()
{
#ifdef MAP
    cout << "Appel au constructeur de <FakePurificateurDao> sur " << this << endl;
#endif
} //----- Fin de FakePurificateurDao

FakePurificateurDao::~FakePurificateurDao()
{
#ifdef MAP
    cout << "Appel au destructeur de <FakePurificateurDao> sur " << this << endl;
#endif
} //----- Fin de ~FakePurificateurDao

Purificateur *FakePurificateurDao::findById(const string &id)
{
    for (auto purificateur : purificateurs)
    {
        if (purificateur->getIdentifiant() == id)
        {
            return purificateur;
        }
    }
    return nullptr;
} //----- Fin de findById

vector<Purificateur *> &FakePurificateurDao::findAll()
{
    return purificateurs;
} //----- Fin de findAll

void FakePurificateurDao::addPurificateur(Purificateur *purificateur)
{
    purificateurs.push_back(purificateur);
} //----- Fin de addPurificateur

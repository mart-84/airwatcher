/*************************************************************************
                           FakeAttributDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <FakeAttributDao> (fichier FakeAttributDao.cpp) ------------

#include <iostream>
using namespace std;

#include "FakeAttributDao.h"

FakeAttributDao::FakeAttributDao()
{
#ifdef MAP
    cout << "Appel au constructeur de <FakeAttributDao> sur " << this << endl;
#endif
} //----- Fin de FakeAttributDao

FakeAttributDao::~FakeAttributDao()
{
#ifdef MAP
    cout << "Appel au destructeur de <FakeAttributDao> sur " << this << endl;
#endif
} //----- Fin de ~FakeAttributDao

Attribut *FakeAttributDao::findByName(const string &name)
{
    for (auto attribut : attributs)
    {
        if (attribut->getIdentifiant() == name)
        {
            return attribut;
        }
    }
    return nullptr;
} //----- Fin de findByName

vector<Attribut *> &FakeAttributDao::findAll()
{
    return attributs;
} //----- Fin de findAll

void FakeAttributDao::addAttribut(Attribut *attribut)
{
    attributs.push_back(attribut);
} //----- Fin de addAttribut

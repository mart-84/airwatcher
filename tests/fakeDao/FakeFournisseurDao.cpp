/*************************************************************************
                           FakeFournisseurDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <FakeFournisseurDao> (fichier FakeFournisseurDao.cpp) ------------

#include <iostream>
using namespace std;

#include "FakeFournisseurDao.h"

FakeFournisseurDao::FakeFournisseurDao()
{
#ifdef MAP
    cout << "Appel au constructeur de <FakeFournisseurDao> sur " << this << endl;
#endif
} //----- Fin de FakeFournisseurDao

FakeFournisseurDao::~FakeFournisseurDao()
{
#ifdef MAP
    cout << "Appel au destructeur de <FakeFournisseurDao> sur " << this << endl;
#endif
} //----- Fin de ~FakeFournisseurDao

void FakeFournisseurDao::addFournisseur(Fournisseur *fournisseur)
{
    fournisseurs.push_back(fournisseur);
} //----- Fin de addFournisseur

Fournisseur *FakeFournisseurDao::findById(const string &id)
{
    for (auto fournisseur : fournisseurs)
    {
        if (fournisseur->getIdentifiant() == id)
        {
            return fournisseur;
        }
    }
    return nullptr;
} //----- Fin de findById

vector<Fournisseur *> &FakeFournisseurDao::findAll()
{
    return fournisseurs;
} //----- Fin de findAll

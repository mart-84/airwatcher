/*************************************************************************
                           FournisseurDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <FournisseurDaoCsv> (fichier FournisseurDaoCsv.cpp) ------------

#include <iostream>
#include <fstream>
using namespace std;

#include "FournisseurDaoCsv.h"
#include "CsvParser.h"

FournisseurDaoCsv::FournisseurDaoCsv(const string &filename)
{
#ifdef MAP
    cout << "Appel au constructeur de <FournisseurDaoCsv> sur " << this << endl;
#endif
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier " << filename << endl;
        exit(1);
    }

    vector<vector<string>> lines(CsvParser::parse(file));

    for (auto &line : lines)
    {
        Fournisseur *fournisseur = new Fournisseur(line[0], nullptr);
        fournisseurs.push_back(fournisseur);
        purificateur_ids.push_back(line[1]);
    }
} //----- Fin de FournisseurDaoCsv

FournisseurDaoCsv::~FournisseurDaoCsv()
{
#ifdef MAP
    cout << "Appel au destructeur de <FournisseurDaoCsv> sur " << this << endl;
#endif
    for (Fournisseur *fournisseur : fournisseurs)
    {
        delete fournisseur;
    }
} //----- Fin de ~FournisseurDaoCsv

void FournisseurDaoCsv::associerPurificateurs(vector<Purificateur *> &purificateurs)
{
    for (size_t i = 0; i < fournisseurs.size(); i++)
    {
        for (Purificateur *purificateur : purificateurs)
        {
            if (purificateur->getIdentifiant() == purificateur_ids[i])
            {
                fournisseurs[i]->setPurificateur(purificateur);
            }
        }
    }
} //----- Fin de associerPurificateurs

Fournisseur *FournisseurDaoCsv::findById(const string &id)
{
    for (Fournisseur *fournisseur : fournisseurs)
    {
        if (fournisseur->getIdentifiant() == id)
        {
            return fournisseur;
        }
    }
    return nullptr;
} //----- Fin de findById

vector<Fournisseur *> &FournisseurDaoCsv::findAll()
{
    return fournisseurs;
} //----- Fin de findAll

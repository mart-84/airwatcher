/*************************************************************************
                           ParticulierDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <ParticulierDaoCsv> (fichier ParticulierDaoCsv.cpp) ------------

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "ParticulierDaoCsv.h"
#include "CsvParser.h"

ParticulierDaoCsv::ParticulierDaoCsv(const string &filename)
{
#ifdef MAP
    cout << "Appel au constructeur de <ParticulierDaoCsv> sur " << this << endl;
#endif
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier " << filename << endl;
        exit(1);
    }
    vector<vector<string>> lines(CsvParser::parse(file));

    ifstream fileBanned("dataset/banned-users.csv");
    vector<vector<string>> linesBanned;
    if (fileBanned.is_open())
    {
        linesBanned = CsvParser::parse(fileBanned);
    }

    for (auto &line : lines)
    {
        Particulier *particulier = new Particulier(line[0], 0, false);
        particuliers.push_back(particulier);
        capteur_ids.push_back(line[1]);
    }
} //----- Fin de ParticulierDaoCsv

ParticulierDaoCsv::~ParticulierDaoCsv()
{
#ifdef MAP
    cout << "Appel au destructeur de <ParticulierDaoCsv> sur " << this << endl;
#endif
    for (Particulier *particulier : particuliers)
    {
        delete particulier;
    }
} //----- Fin de ~ParticulierDaoCsv

void ParticulierDaoCsv::update(Particulier &particulier)
{
    const string filename = "dataset/banned-users.csv";
    ofstream file(filename);

    if (!file.is_open()) 
    {
        cerr << "Impossible d'ouvrir le fichier " << filename << endl;
        exit(1);
    }

    file << particulier.getIdentifiant() << endl;
} //----- Fin de update

void ParticulierDaoCsv::associerCapteurs(vector<Capteur *> &capteurs)
{
    for (size_t i = 0; i < particuliers.size(); i++)
    {
        for (Capteur *capteur : capteurs)
        {
            if (capteur->getIdentifiant() == capteur_ids[i])
            {
                particuliers[i]->ajouterCapteur(capteur);
                capteur->setProprietaire(particuliers[i]);
            }
        }
    }
} //----- Fin de associerCapteurs

Particulier *ParticulierDaoCsv::findById(const string &id)
{
    for (Particulier *particulier : particuliers)
    {
        if (particulier->getIdentifiant() == id)
        {
            return particulier;
        }
    }
    return nullptr;
} //----- Fin de findById

vector<Particulier *> &ParticulierDaoCsv::findAll()
{
    return particuliers;
} //----- Fin de findAll

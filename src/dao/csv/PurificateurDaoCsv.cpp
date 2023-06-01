/*************************************************************************
                           PurificateurDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <PurificateurDaoCsv> (fichier PurificateurDaoCsv.cpp) ------------

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "PurificateurDaoCsv.h"
#include "CsvParser.h"

PurificateurDaoCsv::PurificateurDaoCsv(const string &filename)
{
#ifdef MAP
    cout << "Appel au constructeur de <PurificateurDaoCsv> sur " << this << endl;
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
        Purificateur *purificateur = new Purificateur(line[0], line[3], line[4], stod(line[1]), stod(line[2]));
        purificateurs.push_back(purificateur);
    }
} //----- Fin de PurificateurDaoCsv

PurificateurDaoCsv::~PurificateurDaoCsv()
{
#ifdef MAP
    cout << "Appel au destructeur de <PurificateurDaoCsv> sur " << this << endl;
#endif
    for (Purificateur *purificateur : purificateurs)
    {
        delete purificateur;
    }
} //----- Fin de ~PurificateurDaoCsv

Purificateur *PurificateurDaoCsv::findById(const string &id)
{
    for (Purificateur *purificateur : purificateurs)
    {
        if (purificateur->getIdentifiant() == id)
        {
            return purificateur;
        }
    }
    return nullptr;
} //----- Fin de findById

vector<Purificateur *> &PurificateurDaoCsv::findAll()
{
    return purificateurs;
} //----- Fin de findAll

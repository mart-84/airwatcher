/*************************************************************************
                           ParticulierDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <ParticulierDaoCsv> (fichier ParticulierDaoCsv.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ParticulierDaoCsv.h"
#include "CsvParser.h"

//------------------------------------------------------------- Constantes
const char *CHEMIN_PARTICULIER = "dataset/sensors.csv";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
ParticulierDaoCsv::ParticulierDaoCsv()
{
#ifdef MAP
    cout << "Appel au constructeur de <ParticulierDaoCsv> sur " << this << endl;
#endif
    ifstream file(CHEMIN_PARTICULIER);
    if (!file.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier " << CHEMIN_PARTICULIER << endl;
        exit(1);
    }

    vector<vector<string>> lines(CsvParser::parse(file));

    for (auto &line : lines)
    {
        Particulier *particulier = new Particulier(line[0], 0, false);
        particuliers.push_back(particulier);
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

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

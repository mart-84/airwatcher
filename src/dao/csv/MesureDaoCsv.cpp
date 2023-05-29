/*************************************************************************
                           MesureDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <MesureDaoCsv> (fichier MesureDaoCsv.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "MesureDaoCsv.h"
#include "CsvParser.h"

//------------------------------------------------------------- Constantes
const char *CHEMIN_MESURE = "dataset/measurements.csv";

//----------------------------------------------------------------- PUBLIC
MesureDaoCsv::MesureDaoCsv()
{
#ifdef MAP
    cout << "Appel au constructeur de <MesureDaoCsv> sur " << this << endl;
#endif
    ifstream file(CHEMIN_MESURE);
    if (!file.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier " << CHEMIN_MESURE << endl;
        exit(1);
    }

    vector<vector<string>> lines(CsvParser::parse(file));

    for (auto &line : lines)
    {
        Mesure *mesure = new Mesure(line[0], stoi(line[3]), nullptr, nullptr);
        mesures.push_back(mesure);
    }
} //----- Fin de MesureDaoCsv

MesureDaoCsv::~MesureDaoCsv()
{
#ifdef MAP
    cout << "Appel au destructeur de <MesureDaoCsv> sur " << this << endl;
#endif
    for (Mesure *mesure : mesures)
    {
        delete mesure;
    }
} //----- Fin de ~MesureDaoCsv

vector<Mesure *> &MesureDaoCsv::findAll()
{
    return mesures;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

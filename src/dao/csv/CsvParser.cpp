/*************************************************************************
                           CsvParser  -  description
                             -------------------
    début                : 26/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <CsvParser> (fichier CsvParser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "CsvParser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CsvParser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

vector<vector<string>> CsvParser::parse(ifstream &file)
{
    string line;
    vector<vector<string>> result;

    while (getline(file, line))
    {
        vector<string> values;
        stringstream lineStream(line);
        string cell;
        while (getline(lineStream, cell, ';'))
        {
            values.push_back(cell);
        }
        result.push_back(values);
    }

    return result;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

/*************************************************************************
                           CsvParser  -  description
                             -------------------
    début                : 26/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <CsvParser> (fichier CsvParser.cpp) ------------

using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>

#include "CsvParser.h"

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
} //----- Fin de parse

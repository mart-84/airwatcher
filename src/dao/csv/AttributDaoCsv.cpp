/*************************************************************************
                           AttributDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <AttributDaoCsv> (fichier AttributDaoCsv.cpp) ------------

#include <iostream>
#include <fstream>
using namespace std;

#include "AttributDaoCsv.h"
#include "CsvParser.h"

AttributDaoCsv::AttributDaoCsv(const string &filename)
{
#ifdef MAP
    cout << "Appel au constructeur de <AttributDaoCsv> sur " << this << endl;
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
        Attribut *attribut = new Attribut(line[0], line[1], line[2]);
        attributs.push_back(attribut);
    }
} //----- Fin de AttributDaoCsv

AttributDaoCsv::~AttributDaoCsv()
{
#ifdef MAP
    cout << "Appel au destructeur de <AttributDaoCsv> sur " << this << endl;
#endif
    for (Attribut *attr : attributs)
    {
        delete attr;
    }
} //----- Fin de ~AttributDaoCsv

Attribut *AttributDaoCsv::findByName(const string &nom)
{
    for (Attribut *attr : attributs)
    {
        if (attr->getIdentifiant() == nom)
        {
            return attr;
        }
    }
    return nullptr;
} //----- Fin de findByName

vector<Attribut *> &AttributDaoCsv::findAll()
{
    return attributs;
} //----- Fin de findAll

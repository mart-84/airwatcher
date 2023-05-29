/*************************************************************************
                           AttributDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <AttributDaoCsv> (fichier AttributDaoCsv.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "AttributDaoCsv.h"
#include "CsvParser.h"

//------------------------------------------------------------- Constantes
const char *CHEMIN_ATTRIBUT = "dataset/attributes.csv";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
AttributDaoCsv::AttributDaoCsv()
{
#ifdef MAP
    cout << "Appel au constructeur de <AttributDaoCsv> sur " << this << endl;
#endif
    ifstream file(CHEMIN_ATTRIBUT);
    if (!file.is_open())
    {
        cerr << "Impossible d'ouvrir le fichier " << CHEMIN_ATTRIBUT << endl;
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
// Algorithme :
//
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
}

vector<Attribut *> &AttributDaoCsv::findAll()
{
    return attributs;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

/*************************************************************************
                           CapteurDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <CapteurDaoCsv> (fichier CapteurDaoCsv.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "CapteurDaoCsv.h"
#include "CsvParser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
CapteurDaoCsv::CapteurDaoCsv(const string &filename)
{
#ifdef MAP
    cout << "Appel au constructeur de <CapteurDaoCsv> sur " << this << endl;
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
        Capteur *capteur = new Capteur(line[0], true, stod(line[1]), stod(line[2]));
        capteurs.push_back(capteur);
    }
} //----- Fin de CapteurDaoCsv

CapteurDaoCsv::~CapteurDaoCsv()
{
#ifdef MAP
    cout << "Appel au destructeur de <CapteurDaoCsv> sur " << this << endl;
#endif
    for (Capteur *capteur : capteurs)
    {
        delete capteur;
    }
} //----- Fin de ~CapteurDaoCsv

Capteur *CapteurDaoCsv::findById(const string &id)
// Algorithme :
// Parcours linéaire de la liste des capteurs
{
    for (Capteur *capteur : capteurs)
    {
        if (capteur->getIdentifiant() == id)
        {
            return capteur;
        }
    }

    return nullptr;
} //----- Fin de findById

vector<Capteur *> &CapteurDaoCsv::findAll()
{
    return capteurs;
} //----- Fin de findAll

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

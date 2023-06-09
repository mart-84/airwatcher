/*************************************************************************
                           CapteurDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <CapteurDaoCsv> (fichier CapteurDaoCsv.cpp) ------------

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "CapteurDaoCsv.h"
#include "CsvParser.h"

vector<Capteur *> CapteurDaoCsv::getCapteursZoneCirculaire(double latitude, double longitude, int rayon)
{
    vector<Capteur *> capteursZoneCirculaire;

    for (Capteur *capteur : capteurs)
    {
        if (capteur->estDansZoneCirculaire(latitude, longitude, rayon) && capteur->getEstFiable())
        {
            capteursZoneCirculaire.push_back(capteur);
        }
    }

    return capteursZoneCirculaire;
}

CapteurDaoCsv::CapteurDaoCsv(const string &filename, const string &fBanned)
    : filenameBanned(fBanned)
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

    ifstream fileBanned(fBanned);
    vector<vector<string>> linesBanned;
    if (fileBanned.is_open())
    {
        linesBanned = CsvParser::parse(fileBanned);
    }

    for (auto &line : lines)
    {
        Capteur *capteur = new Capteur(line[0], true, stod(line[1]), stod(line[2]));
        for (auto &lineBanned : linesBanned)
        {
            if (lineBanned[0] == line[0])
            {
                capteur->setEstFiable(false);
                break;
            }
        }
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

void CapteurDaoCsv::update(Capteur &capteur)
{
    if (!capteur.getEstFiable())
    {
        ofstream file(filenameBanned, ios::app);

        if (!file.is_open())
        {
            cerr << "Impossible d'ouvrir le fichier " << filenameBanned << endl;
            exit(1);
        }

        file << capteur.getIdentifiant() << endl;
    }
} //----- Fin de update

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

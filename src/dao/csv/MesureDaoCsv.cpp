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

//----------------------------------------------------------------- PUBLIC
MesureDaoCsv::MesureDaoCsv(const string &filename)
{
#ifdef MAP
    cout << "Appel au constructeur de <MesureDaoCsv> sur " << this << endl;
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
        Mesure *mesure = new Mesure(line[0], stoi(line[3]), nullptr, nullptr);
        mesures.push_back(mesure);
        attribut_ids.push_back(line[2]);
        capteur_ids.push_back(line[1]);
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

void MesureDaoCsv::associerAttributs(vector<Attribut *> &attributs)
{
    for (size_t i = 0; i < mesures.size(); i++)
    {
        for (Attribut *attribut : attributs)
        {
            if (attribut->getIdentifiant() == attribut_ids[i])
            {
                mesures[i]->setAttribut(attribut);
            }
        }
    }
}

void MesureDaoCsv::associerCapteurs(vector<Capteur *> &capteurs)
{
    for (size_t i = 0; i < mesures.size(); i++)
    {
        for (Capteur *capteur : capteurs)
        {
            if (capteur->getIdentifiant() == capteur_ids[i])
            {
                mesures[i]->setCapteur(capteur);
                capteur->ajouterMesure(mesures[i]);
            }
        }
    }
}

vector<Mesure *> &MesureDaoCsv::findAll()
{
    return mesures;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

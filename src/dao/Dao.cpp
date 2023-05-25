/*************************************************************************
                           Dao  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Dao> (fichier Dao.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Dao.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Dao::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Dao &Dao::operator=(const Dao &autreDao)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Dao> sur " << this << " et " << &autreDao << endl;
#endif
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Dao::Dao()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Dao> sur " << this << endl;
#endif
} //----- Fin de Dao

Dao::~Dao()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Dao> sur " << this << endl;
#endif
} //----- Fin de ~Dao

void Dao::parse_csv(const string &path)
// Algorithme :
// On lit chaque ligne du fichier dont le chemin est donné en paramètre
// On sépare chaque ligne par une virgule
{
    ifstream read(path);

    if (read)
    {
        string line;
        while (getline(read, line))
        {
            m_lines.emplace_back();

            istringstream stream(line);
            string stoken;
            while (getline(stream, stoken, ';'))
            {
                m_lines.back().push_back(stoken);
            }

            if (m_lines.back().empty())
            {
                m_lines.pop_back();
            }
        }
    }
    else
    {
        cerr << "Cannot open file: " << path << endl;
    }
} //----- Fin de parse_csv

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

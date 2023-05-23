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
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

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
Dao::Dao(const Dao &autreDao)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Dao> sur " << this << " et " << &autreDao << endl;
#endif
} //----- Fin de Dao (constructeur de copie)

Dao::Dao()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Dao> sur " << this << endl;
#endif
} //----- Fin de Dao

Dao::Dao()
// Algorithme :
//
{
    parse_csv(get_path());
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

void Dao::parse_csv(const std::string& path)
// Algorithme :
// On lit chaque ligne du fichier dont le chemin est donné en paramètre
// On sépare chaque ligne par une virgule
{
    std::ifstream read(path);

    if(read)
    {
        std::string line;
        while(std::getline(read, line))
        {
            m_lines.emplace_back();

            std::stringstream stream(line);
            std::string stoken;
            while(std::getline(stream, stoken, ",")) 
            {
                m_lines.back().push_back(stoken);
            }
        }
    }
    else 
    {
        std::cerr << "Cannot open file: " << path << std::endl;
    }
} //----- Fin de parse_csv

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

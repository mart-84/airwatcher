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
#include <ifstream>

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

void parse_csv(const std::string& path)
{
    std::ifstream read(path);

    if(path)
    {
        std::string line;
        while(std::getline(path, line))
        {
            std::stringstream stream(line);
            std::string stoken;
            while(std::getline(stream, stoken, ",")) 
            {
                
            }
        }
    }
    else 
    {
        throw std::exception("Cannot read file: " + path);
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

/*************************************************************************
                           CapteurDao  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <CapteurDao> (fichier CapteurDao.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "CapteurDao.h"

//------------------------------------------------------------- Constantes
static const string CHEMIN = "dataset/sensors.csv";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CapteurDao::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
CapteurDao &CapteurDao::operator=(const CapteurDao &autreCapteurDao)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <CapteurDao> sur " << this << " et " << &autreCapteurDao << endl;
#endif
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
CapteurDao::CapteurDao(const CapteurDao &autreCapteurDao)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <CapteurDao> sur " << this << " et " << &autreCapteurDao << endl;
#endif
} //----- Fin de CapteurDao (constructeur de copie)

CapteurDao::CapteurDao()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <CapteurDao> sur " << this << endl;
#endif

    this->parse_csv(CHEMIN);

    for (auto &&line : m_lines)
    {
        Capteur capteur(line[0], false, stol(line[1]), stol(line[2]));
        m_capteurs.push_back(capteur);
    }
} //----- Fin de CapteurDao

CapteurDao::~CapteurDao()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CapteurDao> sur " << this << endl;
#endif
} //----- Fin de ~CapteurDao

Capteur *CapteurDao::findById(const string &id)
// Algorithme :
// Recherche par id simple
{
    for (auto &&capteur : m_capteurs)
    {
        if (capteur.getIdentifiant() == id)
        {
            return &capteur;
        }
    }

    return nullptr;
} //----- Fin de findById

vector<Capteur> &CapteurDao::findAll()
// Algorithme :
// Retourne tous les capteurs
{
    return m_capteurs;
} //----- Fin de findAll

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

/*************************************************************************
                           Service  -  description
                             -------------------
    début                : 23/05/2023 
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Service.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Service::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Service &Service::operator=(const Service &autreService)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Service> sur " << this << " et " << &autreService << endl;
#endif
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Service::Service(const Service &autreService)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Service> sur " << this << " et " << &autreService << endl;
#endif
} //----- Fin de Service (constructeur de copie)

Service::Service()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Service> sur " << this << endl;
#endif
} //----- Fin de Service

Service::~Service()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Service> sur " << this << endl;
#endif
} //----- Fin de ~Service

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

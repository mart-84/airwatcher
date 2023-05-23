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
int Service::calculerIndiceATMO(int o3, int so2, int no2, int pm10)
{
    int pire = 0;

    // qualité de O3
    int qualite_o3;
    if (o3 >= 240) {
        qualite_o3 = 10;
    } else if (o3 >= 210) {
        qualite_o3 = 9;
    } else if (o3 >= 180) {
        qualite_o3 = 8;
    } else if (o3 >= 150) {
        qualite_o3 = 7;
    } else if (o3 >= 130) {
        qualite_o3 = 6;
    } else if (o3 >= 105) {
        qualite_o3 = 5;
    } else if (o3 >= 80) {
        qualite_o3 = 4;
    } else if (o3 >= 55) {
        qualite_o3 = 3;
    } else if (o3 >= 30) {
        qualite_o3 = 2;
    } else {
        qualite_o3 = 1;
    }

    if (qualite_o3 > pire) pire = qualite_o3;

    // qualité de SO2
    int qualite_so2;
    if (o3 >= 500) {
        qualite_so2 = 10;
    } else if (o3 >= 400) {
        qualite_so2 = 9;
    } else if (o3 >= 300) {
        qualite_so2 = 8;
    } else if (o3 >= 250) {
        qualite_so2 = 7;
    } else if (o3 >= 200) {
        qualite_so2 = 6;
    } else if (o3 >= 160) {
        qualite_so2 = 5;
    } else if (o3 >= 120) {
        qualite_so2 = 4;
    } else if (o3 >= 80) {
        qualite_so2 = 3;
    } else if (o3 >= 40) {
        qualite_so2 = 2;
    } else {
        qualite_so2 = 1;
    }

    if (qualite_so2 > pire) pire = qualite_so2;

    // qualité de NO2
    int qualite_no2;
    if (o3 >= 400) {
        qualite_no2 = 10;
    } else if (o3 >= 275) {
        qualite_no2 = 9;
    } else if (o3 >= 200) {
        qualite_no2 = 8;
    } else if (o3 >= 165) {
        qualite_no2 = 7;
    } else if (o3 >= 135) {
        qualite_no2 = 6;
    } else if (o3 >= 110) {
        qualite_no2 = 5;
    } else if (o3 >= 85) {
        qualite_no2 = 4;
    } else if (o3 >= 55) {
        qualite_no2 = 3;
    } else if (o3 >= 30) {
        qualite_no2 = 2;
    } else {
        qualite_no2 = 1;
    }

    if (qualite_no2 > pire) pire = qualite_no2;

    // qualité de PM10
    int qualite_pm10;
    if (o3 >= 80) {
        qualite_pm10 = 10;
    } else if (o3 >= 65) {
        qualite_pm10 = 9;
    } else if (o3 >= 50) {
        qualite_pm10 = 8;
    } else if (o3 >= 42) {
        qualite_pm10 = 7;
    } else if (o3 >= 35) {
        qualite_pm10 = 6;
    } else if (o3 >= 28) {
        qualite_pm10 = 5;
    } else if (o3 >= 21) {
        qualite_pm10 = 4;
    } else if (o3 >= 14) {
        qualite_pm10 = 3;
    } else if (o3 >= 7) {
        qualite_pm10 = 2;
    } else {
        qualite_pm10 = 1;
    }

    if (qualite_pm10 > pire) pire = qualite_pm10;

    return pire;
}

//------------------------------------------------- Surcharge d'opérateurs
Service &Service::operator=(const Service &autreService)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Service> sur " << this << " et " << &autreService << endl;
#endif
    return *this;
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

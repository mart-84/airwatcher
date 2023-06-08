/*************************************************************************
                           FakeMesureDao  -  description
                             -------------------
    début                : 08/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <FakeMesureDao> (fichier FakeMesureDao.cpp) ------------

#include <iostream>
using namespace std;

#include "FakeMesureDao.h"

FakeMesureDao::FakeMesureDao()
{
#ifdef MAP
    cout << "Appel au constructeur de <FakeMesureDao> sur " << this << endl;
#endif
} //----- Fin de FakeMesureDao

FakeMesureDao::~FakeMesureDao()
{
#ifdef MAP
    cout << "Appel au destructeur de <FakeMesureDao> sur " << this << endl;
#endif
} //----- Fin de ~FakeMesureDao

vector<Mesure *> &FakeMesureDao::findAll()
{
    return mesures;
} //----- Fin de findAll

void FakeMesureDao::addMesure(Mesure *mesure)
{
    mesures.push_back(mesure);
} //----- Fin de addMesure

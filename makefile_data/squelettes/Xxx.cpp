/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : %DATE%
    copyright            : (C) %YEAR% par %AUTHOR%
    e-mail               : %EMAIL%
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

#include <iostream>
using namespace std;

#include "Xxx.h"

Xxx::Xxx()
{
#ifdef MAP
    cout << "Appel au constructeur de <Xxx> sur " << this << endl;
#endif
} //----- Fin de Xxx

Xxx::~Xxx()
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx> sur " << this << endl;
#endif
} //----- Fin de ~Xxx

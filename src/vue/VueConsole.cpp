/*************************************************************************
                           VueConsole  -  description
                             -------------------
    début                : 01/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <VueConsole> (fichier VueConsole.cpp) ------------

#include <iostream>
using namespace std;

#include "VueConsole.h"

void VueConsole::afficherMenu()
{
    cout << "Bienvenue sur Airwatcher !" << endl;
} //----- Fin de afficherMenu

VueConsole::VueConsole(Service &s)
    : service(s)
{
#ifdef MAP
    cout << "Appel au constructeur de <VueConsole> sur " << this << endl;
#endif
} //----- Fin de VueConsole

VueConsole::~VueConsole()
{
#ifdef MAP
    cout << "Appel au destructeur de <VueConsole> sur " << this << endl;
#endif
} //----- Fin de ~VueConsole

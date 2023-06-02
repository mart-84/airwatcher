/*************************************************************************
                           VueConsole  -  description
                             -------------------
    début                : 01/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <VueConsole> (fichier VueConsole.h) ----------------
#if !defined(VUE_H)
#define VUE_H

using namespace std;

#include "../service/Service.h"

//------------------------------------------------------------------------
// Rôle de la classe <VueConsole>
//
// VueConsole générale du programme, gère l'interaction avec l'utilisateur en
// mode console
//------------------------------------------------------------------------

class VueConsole
{
public:
    void afficherMenu();

    VueConsole(Service &);

    virtual ~VueConsole();

protected:
    int saisirEntier();

    Service &service;
};

#endif // VUE_H

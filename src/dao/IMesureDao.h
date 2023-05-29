/*************************************************************************
                           IMesureDao  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <IMesureDao> (fichier IMesureDao.h) ----------------
#if !defined(IMesureDao_H)
#define IMesureDao_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
using namespace std;

#include "../metier/Mesure.h"

//------------------------------------------------------------------------
// Rôle de la classe <IMesureDao>
//
// Interface pour un Dao de Mesure
//------------------------------------------------------------------------

class IMesureDao
{
public:
    virtual ~IMesureDao(){};

    //----------------------------------------------------- Méthodes publiques
    virtual vector<Mesure *> &findAll() = 0;
    // Mode d'emploi :
    // Renvoie la liste de toutes les mesures
};

#endif // IMesureDao_H

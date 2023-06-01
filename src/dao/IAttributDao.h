/*************************************************************************
                           IAttributDao  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <IAttributDao> (fichier IAttributDao.h) ----------------
#if !defined(IAttributDao_H)
#define IAttributDao_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
using namespace std;

#include "../metier/Attribut.h"

//------------------------------------------------------------------------
// Rôle de la classe <IAttributDao>
//
// Interface pour un Dao de Attribut
//------------------------------------------------------------------------

class IAttributDao
{
public:
    virtual ~IAttributDao(){};

    virtual Attribut *findByName(const string &) = 0;
    // Mode d'emploi :
    // Renvoie l'attribut avec le nom spécifié. Si l'attribut n'est pas trouvé, renvoie null

    virtual vector<Attribut *> &findAll() = 0;
    // Mode d'emploi :
    // Renvoie la liste de tous les attributs
};

#endif // IAttributDao_H

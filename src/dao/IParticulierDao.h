/*************************************************************************
                           IParticulierDao  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <IParticulierDao> (fichier IParticulierDao.h) ----------------
#if !defined(IParticulierDao_H)
#define IParticulierDao_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
using namespace std;

#include "../metier/Particulier.h"

//------------------------------------------------------------------------
// Rôle de la classe <IParticulierDao>
//
// Interface pour un Dao de Particulier
//------------------------------------------------------------------------

class IParticulierDao
{
public:
    virtual ~IParticulierDao(){};

    //----------------------------------------------------- Méthodes publiques
    virtual Particulier *findById(const string &id) = 0;
    // Mode d'emploi :
    // Renvoie le particulier avec l'id spécifie. Si le particulier n'est pas trouvé, renvoie null

    virtual vector<Particulier *> &findAll() = 0;
    // Mode d'emploi :
    // Renvoie la liste de tous les particuliers
};

#endif // IParticulierDao_H

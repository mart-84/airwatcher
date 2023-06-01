/*************************************************************************
                           IFournisseurDao  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <IFournisseurDao> (fichier IFournisseurDao.h) ----------------
#if !defined(IFournisseurDao_H)
#define IFournisseurDao_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
using namespace std;

#include "../metier/Fournisseur.h"

//------------------------------------------------------------------------
// Rôle de la classe <IFournisseurDao>
//
// Interface pour un Dao de Fournisseur
//------------------------------------------------------------------------

class IFournisseurDao
{
public:
    virtual ~IFournisseurDao(){};

    virtual Fournisseur *findById(const string &) = 0;
    // Mode d'emploi :
    // Renvoie le fournisseur avec l'id spécifié. Si le fournisseur n'est pas trouvé, renvoie null

    virtual vector<Fournisseur *> &findAll() = 0;
    // Mode d'emploi :
    // Renvoie la liste de tous les fournisseurs
};

#endif // IFournisseurDao_H

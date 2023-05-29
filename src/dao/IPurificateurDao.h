/*************************************************************************
                           IPurificateurDao  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <IPurificateurDao> (fichier IPurificateurDao.h) ----------------
#if !defined(IPurificateurDao_H)
#define IPurificateurDao_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
using namespace std;

#include "../metier/Purificateur.h"

//------------------------------------------------------------------------
// Rôle de la classe <IPurificateurDao>
//
// Interface pour un Dao de Purificateur
//------------------------------------------------------------------------

class IPurificateurDao
{
public:
    virtual ~IPurificateurDao(){};

    //----------------------------------------------------- Méthodes publiques
    virtual Purificateur *findById(const string &id) = 0;
    // Mode d'emploi :
    // Renvoie le purificateur avec l'id spécifie. Si le purificateur n'est pas trouvé, renvoie null

    virtual vector<Purificateur *> &findAll() = 0;
    // Mode d'emploi :
    // Renvoie la liste de tous les purificateurs
};

#endif // IPurificateurDao_H

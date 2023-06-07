/*************************************************************************
                           ICapteurDao  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <ICapteurDao> (fichier ICapteurDao.h) ----------------
#if !defined(ICapteurDao_H)
#define ICapteurDao_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
using namespace std;

#include "../metier/Capteur.h"

//------------------------------------------------------------------------
// Rôle de la classe <ICapteurDao>
//
// Interface pour un Dao de Capteur
//------------------------------------------------------------------------

class ICapteurDao
{
public:
    virtual ~ICapteurDao(){};

    virtual void update(Capteur &capteur) = 0;

    virtual Capteur *findById(const string &id) = 0;
    // Mode d'emploi :
    // Renvoie le capteur avec l'id spécifie. Si le capteur n'est pas trouvé, renvoie null

    virtual vector<Capteur *> &findAll() = 0;
    // Mode d'emploi :
    // Renvoie la liste de tous les capteurs

    virtual vector<Capteur *> getCapteursZoneCirculaire(double latitude, double longitude, int rayon) = 0;
};

#endif // ICapteurDao_H

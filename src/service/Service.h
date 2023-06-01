/*************************************************************************
                           Service  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Service> (fichier Service.h) ----------------
#if !defined(Service_H)
#define Service_H

//--------------------------------------------------- Interfaces utilisées
#include "../dao/IAttributDao.h"
#include "../dao/ICapteurDao.h"
#include "../dao/IFournisseurDao.h"
#include "../dao/IMesureDao.h"
#include "../dao/IParticulierDao.h"
#include "../dao/IPurificateurDao.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Service>
//
//
//------------------------------------------------------------------------

class Service
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    int calculerIndiceATMO(int o3, int so2, int no2, int pm10);

    //-------------------------------------------- Constructeurs - destructeur
    Service(IAttributDao &,
            ICapteurDao &,
            IFournisseurDao &,
            IMesureDao &,
            IParticulierDao &,
            IPurificateurDao &);

    virtual ~Service();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    IAttributDao &attributDao;
    ICapteurDao &capteurDao;
    IFournisseurDao &fournisseurDao;
    IMesureDao &mesureDao;
    IParticulierDao &particulierDao;
    IPurificateurDao &purificateurDao;
};

//-------------------------------- Autres définitions dépendantes de <Service>

#endif // Service_H

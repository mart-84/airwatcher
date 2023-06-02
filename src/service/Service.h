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

#include "../dao/IAttributDao.h"
#include "../dao/ICapteurDao.h"
#include "../dao/IFournisseurDao.h"
#include "../dao/IMesureDao.h"
#include "../dao/IParticulierDao.h"
#include "../dao/IPurificateurDao.h"

#include <array>
#include <algorithm>

//------------------------------------------------------------------------
// Rôle de la classe <Service>
//
// Service métier général de l'application
// Est au sommet de la hiérarchie des dépendances
//------------------------------------------------------------------------

class Service
{
public:
    int calculerIndiceATMO(int o3, int so2, int no2, int pm10);

    std::array<double, 3> statistiquesZoneCirculaire(double longitude, double latitude, int rayon, std::string date_debut, std::string date_fin = "", double* tps = nullptr);

    Service(IAttributDao &,
            ICapteurDao &,
            IFournisseurDao &,
            IMesureDao &,
            IParticulierDao &,
            IPurificateurDao &);

    virtual ~Service();

protected:
    IAttributDao &attributDao;
    ICapteurDao &capteurDao;
    IFournisseurDao &fournisseurDao;
    IMesureDao &mesureDao;
    IParticulierDao &particulierDao;
    IPurificateurDao &purificateurDao;
};

#endif // Service_H

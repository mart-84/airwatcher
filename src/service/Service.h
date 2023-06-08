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
    int calculerIndiceATMO(double o3, double so2, double no2, double pm10);
    // Mode d'emploi :
    // Renvoie l'indice ATMO entre 0 et 5 (bon à extrêmement mauvais) en fonction des valeurs des polluants

    Capteur *obtenirCapteur(string idCapteur);

    void marquerCapteurNonFiable(Capteur &capteur);

    array<double, 3> statistiquesZoneCirculaire(double longitude, double latitude, int rayon, string date_debut, string date_fin = "");
    // Mode d'emploi :
    // Renvoie un tableau contenant le nombre de mesures, la moyenne et la médiane des mesures de la zone circulaire

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

/*************************************************************************
                           Service  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.cpp) ------------

#include <iostream>
using namespace std;

#include "Service.h"

int Service::calculerIndiceATMO(int o3, int so2, int no2, int pm10)
{
    int atmo = 0;

    if (o3 > 380 || so2 > 750 || no2 > 340 || pm10 > 75)
    {
        atmo = 5;
    }
    else if (o3 > 240 || so2 > 500 || no2 > 230 || pm10 > 50)
    {
        atmo = 4;
    }
    else if (o3 > 130 || so2 > 350 || no2 > 120 || pm10 > 25)
    {
        atmo = 3;
    }
    else if (o3 > 100 || so2 > 200 || no2 > 90 || pm10 > 20)
    {
        atmo = 2;
    }
    else if (o3 > 50 || so2 > 100 || no2 > 40 || pm10 > 10)
    {
        atmo = 1;
    }

    return atmo;
} //----- Fin de calculerIndiceATMO

Capteur *Service::obtenirCapteur(string idCapteur)
{
    return capteurDao.findById(idCapteur);
} //----- Fin de obtenirCapteur


void Service::marquerCapteurNonFiable(Capteur & capteur){
    capteur.setEstFiable(false);
    capteurDao.update(capteur);
    if (capteur.getProprietaire() != nullptr)
    {
        capteur.getProprietaire()->setEstBanni(true);
        particulierDao.update(*capteur.getProprietaire());
        for (Capteur *c : capteur.getProprietaire()->getCapteurs())
        {
            c->setEstFiable(false);
            capteurDao.update(*c);
        }
    }

} //----- Fin de marquerCommeNonFIable

Service::Service(IAttributDao &attDao,
                 ICapteurDao &capDao,
                 IFournisseurDao &fouDao,
                 IMesureDao &mesDao,
                 IParticulierDao &parDao,
                 IPurificateurDao &purDao)
    : attributDao(attDao), capteurDao(capDao), fournisseurDao(fouDao), mesureDao(mesDao), particulierDao(parDao), purificateurDao(purDao)
{
#ifdef MAP
    cout << "Appel au constructeur de <Service> sur " << this << endl;
#endif
} //----- Fin de Service

Service::~Service()
{
#ifdef MAP
    cout << "Appel au destructeur de <Service> sur " << this << endl;
#endif
} //----- Fin de ~Service

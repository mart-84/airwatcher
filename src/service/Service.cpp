/*************************************************************************
                           Service  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.cpp) ------------

#include <iostream>
#include <chrono>
using namespace std;

#include "Service.h"

int Service::calculerIndiceATMO(double o3, double so2, double no2, double pm10)
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
    Capteur *capteur = capteurDao.findById(idCapteur);
    if (capteur == nullptr)
    {
        return nullptr;
    }
    if (capteur->getProprietaire() != nullptr)
    {
        capteur->getProprietaire()->ajouterPoint();
        particulierDao.update(*capteur->getProprietaire());
    }
    return capteur;
} //----- Fin de obtenirCapteur

void Service::marquerCapteurNonFiable(Capteur &capteur)
{
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

array<double, 3> Service::statistiquesZoneCirculaire(double longitude, double latitude, int rayon, string date_debut, string date_fin)
{

    this->capteurDao.findAll();

    auto capteurs = this->capteurDao.getCapteursZoneCirculaire(latitude, longitude, rayon);

    if (capteurs.size() == 0)
    {
        return array<double, 3>({0., 0., 0.});
    }

    vector<double> indices;

    for (auto capteur : capteurs)
    {
        if (capteur->getProprietaire() != nullptr)
        {
            capteur->getProprietaire()->ajouterPoint();
            particulierDao.update(*capteur->getProprietaire());
        }

        auto mesures = capteur->getMesures();

        for (unsigned int i = 0; i < mesures.size(); ++i)
        {
            if (mesures[i]->compareDate(date_debut) > 0 || (!date_fin.empty() && mesures[i]->compareDate(date_fin)<=0))
            {
                break;
            }

            for (unsigned int i = 0; i < mesures.size() / 4; ++i)
            {
                double o3 = mesures[i * 4]->getValeur();
                double so2 = mesures[i * 4 + 1]->getValeur();
                double no2 = mesures[i * 4 + 2]->getValeur();
                double pm10 = mesures[i * 4 + 3]->getValeur();

                indices.push_back(calculerIndiceATMO(o3, so2, no2, pm10));
            }
        }
    }

    double moyenne = 0.;
    for (auto indice : indices)
    {
        moyenne += indice;
    }
    moyenne /= indices.size();

    double mediane = 0.;
    sort(indices.begin(), indices.end());
    if (indices.size() % 2 == 0)
    {
        mediane = (indices[indices.size() / 2 - 1] + indices[indices.size() / 2]) / 2;
    }
    else
    {
        mediane = indices[indices.size() / 2];
    }

    return array<double, 3>({double(capteurs.size()), moyenne, mediane});
} //----- Fin de statistiquesZoneCirculaire

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

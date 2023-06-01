#include <iostream>
using namespace std;

#include "dao/ICapteurDao.h"
#include "dao/csv/CapteurDaoCsv.h"
#include "dao/IAttributDao.h"
#include "dao/csv/AttributDaoCsv.h"
#include "dao/IFournisseurDao.h"
#include "dao/csv/FournisseurDaoCsv.h"
#include "dao/IMesureDao.h"
#include "dao/csv/MesureDaoCsv.h"
#include "dao/IParticulierDao.h"
#include "dao/csv/ParticulierDaoCsv.h"
#include "dao/IPurificateurDao.h"
#include "dao/csv/PurificateurDaoCsv.h"

#include "service/Service.h"

int main(int argc, char **argv)
{
    // Initialisation des DAO CSV
    // Récupération des données et création des objets
    AttributDaoCsv attributDaoCsv("dataset/attributes.csv");
    CapteurDaoCsv capteurDaoCsv("dataset/sensors.csv");
    FournisseurDaoCsv fournisseurDaoCsv("dataset/providers.csv");
    MesureDaoCsv mesureDaoCsv("dataset/measurements.csv");
    ParticulierDaoCsv particulierDaoCsv("dataset/users.csv");
    PurificateurDaoCsv purificateurDaoCsv("dataset/cleaners.csv");

    // Création des associations entre les objets
    fournisseurDaoCsv.associerPurificateurs(purificateurDaoCsv.findAll());
    mesureDaoCsv.associerAttributs(attributDaoCsv.findAll());
    mesureDaoCsv.associerCapteurs(capteurDaoCsv.findAll());
    particulierDaoCsv.associerCapteurs(capteurDaoCsv.findAll());

    Service service(attributDaoCsv,
                    capteurDaoCsv,
                    fournisseurDaoCsv,
                    mesureDaoCsv,
                    particulierDaoCsv,
                    purificateurDaoCsv);

    return 0;
}

#include "dao/csv/CapteurDaoCsv.h"
#include "dao/csv/AttributDaoCsv.h"
#include "dao/csv/FournisseurDaoCsv.h"
#include "dao/csv/MesureDaoCsv.h"
#include "dao/csv/ParticulierDaoCsv.h"
#include "dao/csv/PurificateurDaoCsv.h"
#include "service/Service.h"
#include "vue/VueConsole.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Initialisation des DAO CSV
    // Récupération des données et création des objets
    AttributDaoCsv attributDaoCsv("dataset/attributes.csv");
    CapteurDaoCsv capteurDaoCsv("dataset/sensors.csv", "dataset/banned-sensors.csv");
    FournisseurDaoCsv fournisseurDaoCsv("dataset/providers.csv");
    MesureDaoCsv mesureDaoCsv("dataset/measurements.csv");
    ParticulierDaoCsv particulierDaoCsv("dataset/users.csv", "dataset/points-users.csv", "dataset/banned-users.csv");
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

    VueConsole vue(service);
    vue.afficherMenu();

    return 0;
}

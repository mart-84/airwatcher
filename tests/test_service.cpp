#include <vector>
#include <string>
#include <cassert>
#include <functional>

#include "../src/dao/csv/CapteurDaoCsv.h"
#include "../src/dao/csv/AttributDaoCsv.h"
#include "../src/dao/csv/FournisseurDaoCsv.h"
#include "../src/dao/csv/MesureDaoCsv.h"
#include "../src/dao/csv/ParticulierDaoCsv.h"
#include "../src/dao/csv/PurificateurDaoCsv.h"
#include "../src/service/Service.h"

using namespace std;

void contexte_service(std::function<void(Service &)> callback)
{
    // Initialisation des DAO CSV
    // Récupération des données et création des objets
    AttributDaoCsv attributDaoCsv("tests/data/attributes.csv");
    CapteurDaoCsv capteurDaoCsv("tests/data/sensors.csv", "tests/data/banned-sensors.csv");
    FournisseurDaoCsv fournisseurDaoCsv("tests/data/providers.csv");
    MesureDaoCsv mesureDaoCsv("tests/data/measurements.csv");
    ParticulierDaoCsv particulierDaoCsv("tests/data/users.csv", "tests/data/points-users.csv", "tests/data/banned-users.csv");
    PurificateurDaoCsv purificateurDaoCsv("tests/data/cleaners.csv");

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
    callback(service);
}

void test_service_zone_rayon_nul()
{
    contexte_service([](Service &service)
                     {
        auto donnees = service.statistiquesZoneCirculaire(0, 0, 0, "2019-01-01 12:00:00");
        assert(donnees[0] == 0); });
}

void test_service_zone_rayon_univers()
{
    contexte_service([](Service &service)
                     {
        auto donnees = service.statistiquesZoneCirculaire(0, 0, 100000000, "2019-01-01 12:00:00");
        assert(donnees[0] == 100); });
}

void test_service_zone_deux_capteurs()
{
    contexte_service([](Service &service)
                     {
        auto donnees = service.statistiquesZoneCirculaire(44, -1, 0, "2019-01-01 12:00:00", "2019-05-01 12:00:00");
        assert(donnees[0] == 2);
        assert(donnees[1] == 3.9002);
        assert(donnees[2] == 4); });
}

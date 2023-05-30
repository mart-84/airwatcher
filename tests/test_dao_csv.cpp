#include <vector>
#include <string>
#include <cassert>
using namespace std;

#include "../src/dao/csv/AttributDaoCsv.h"
#include "../src/dao/csv/CapteurDaoCsv.h"
#include "../src/dao/csv/FournisseurDaoCsv.h"
#include "../src/dao/csv/MesureDaoCsv.h"
#include "../src/dao/csv/ParticulierDaoCsv.h"
#include "../src/dao/csv/PurificateurDaoCsv.h"

void test_attribut_dao()
{
    string filename = "tests/data/attributes.csv";
    AttributDaoCsv attributDaoCsv(filename);
    vector<Attribut *> attributs = attributDaoCsv.findAll();
    assert(attributs.size() == 2);
    assert(attributs[0]->getIdentifiant() == "O3");
    assert(attributs[0]->getUnite() == "µg/m3");
    assert(attributs[0]->getDescription() == "concentration d'ozone");
    assert(attributs[1]->getIdentifiant() == "PM10");
    assert(attributs[1]->getUnite() == "µg/m3");
    assert(attributs[1]->getDescription() == "concentration de particules fines");
}

void test_capteur_dao()
{
    string filename = "tests/data/sensors.csv";
    CapteurDaoCsv capteurDaoCsv(filename);
    vector<Capteur *> capteurs = capteurDaoCsv.findAll();
    assert(capteurs.size() == 2);
    assert(capteurs[0]->getIdentifiant() == "Sensor0");
    assert(capteurs[0]->getLatitude() == 44);
    assert(capteurs[0]->getLongitude() == -1);
    assert(capteurs[0]->getEstFiable() == true);
    assert(capteurs[0]->getMesures().size() == 0);
    assert(capteurs[0]->getProprietaire() == nullptr);
    assert(capteurs[1]->getIdentifiant() == "Sensor36");
    assert(capteurs[1]->getLatitude() == 45.2);
    assert(capteurs[1]->getLongitude() == 3.2);
    assert(capteurs[1]->getEstFiable() == true);
    assert(capteurs[1]->getMesures().size() == 0);
    assert(capteurs[1]->getProprietaire() == nullptr);
}

void test_fournisseur_dao()
{
    string filename = "tests/data/providers.csv";
    FournisseurDaoCsv fournisseurDaoCsv(filename);
    vector<Fournisseur *> fournisseurs = fournisseurDaoCsv.findAll();
    assert(fournisseurs.size() == 1);
    assert(fournisseurs[0]->getIdentifiant() == "Provider0");
    assert(fournisseurs[0]->getPurificateur() == nullptr);
}

void test_mesure_dao()
{
    string filename = "tests/data/measurements.csv";
    MesureDaoCsv mesureDaoCsv(filename);
    vector<Mesure *> mesures = mesureDaoCsv.findAll();
    assert(mesures.size() == 2);
    assert(mesures[0]->getDate() == "2019-01-01 12:00:00");
    assert(mesures[0]->getValeur() == 50.25);
    assert(mesures[0]->getCapteur() == nullptr);
    assert(mesures[0]->getAttribut() == nullptr);
    assert(mesures[1]->getDate() == "2019-01-01 12:00:00");
    assert(mesures[1]->getValeur() == 44.75);
    assert(mesures[1]->getCapteur() == nullptr);
    assert(mesures[1]->getAttribut() == nullptr);
}

void test_particulier_dao()
{
    string filename = "tests/data/users.csv";
    ParticulierDaoCsv particulierDaoCsv(filename);
    vector<Particulier *> particuliers = particulierDaoCsv.findAll();
    assert(particuliers.size() == 1);
    assert(particuliers[0]->getIdentifiant() == "User0");
    assert(particuliers[0]->getCapteurs().size() == 0);
}

void test_purificateur_dao()
{
    string filename = "tests/data/cleaners.csv";
    PurificateurDaoCsv purificateurDaoCsv(filename);
    vector<Purificateur *> purificateurs = purificateurDaoCsv.findAll();
    assert(purificateurs.size() == 1);
    assert(purificateurs[0]->getIdentifiant() == "Cleaner0");
    assert(purificateurs[0]->getDateDebut() == "2019-02-01 12:00:00");
    assert(purificateurs[0]->getDateFin() == "2019-03-01 00:00:00");
    assert(purificateurs[0]->getLatitude() == 45.333333);
    assert(purificateurs[0]->getLongitude() == 1.333333);
}

void test_association_fournisseur_purificateur()
{
    FournisseurDaoCsv fournisseurDaoCsv("tests/data/providers.csv");
    PurificateurDaoCsv purificateurDaoCsv("tests/data/cleaners.csv");
    fournisseurDaoCsv.associerPurificateurs(purificateurDaoCsv.findAll());
    vector<Fournisseur *> fournisseurs = fournisseurDaoCsv.findAll();
    Purificateur *purificateur = fournisseurs[0]->getPurificateur();
    assert(purificateur->getIdentifiant() == "Cleaner0");
    assert(purificateur->getDateDebut() == "2019-02-01 12:00:00");
    assert(purificateur->getDateFin() == "2019-03-01 00:00:00");
    assert(purificateur->getLatitude() == 45.333333);
    assert(purificateur->getLongitude() == 1.333333);
}

void test_association_mesure_attribut()
{
    MesureDaoCsv mesureDaoCsv("tests/data/measurements.csv");
    AttributDaoCsv attributDaoCsv("tests/data/attributes.csv");
    mesureDaoCsv.associerAttributs(attributDaoCsv.findAll());
    vector<Mesure *> mesures = mesureDaoCsv.findAll();
    Attribut *attribut = mesures[0]->getAttribut();
    assert(attribut->getIdentifiant() == "O3");
    assert(attribut->getUnite() == "µg/m3");
    assert(attribut->getDescription() == "concentration d'ozone");
    attribut = mesures[1]->getAttribut();
    assert(attribut->getIdentifiant() == "PM10");
    assert(attribut->getUnite() == "µg/m3");
    assert(attribut->getDescription() == "concentration de particules fines");
}

void test_association_mesure_capteur()
{
    MesureDaoCsv mesureDaoCsv("tests/data/measurements.csv");
    CapteurDaoCsv capteurDaoCsv("tests/data/sensors.csv");
    mesureDaoCsv.associerCapteurs(capteurDaoCsv.findAll());
    vector<Mesure *> mesures = mesureDaoCsv.findAll();
    Capteur *capteur = mesures[0]->getCapteur();
    assert(capteur->getIdentifiant() == "Sensor0");
    assert(capteur->getLatitude() == 44);
    assert(capteur->getLongitude() == -1);
    assert(capteur->getEstFiable() == true);
    assert(capteur->getProprietaire() == nullptr);
    capteur = mesures[1]->getCapteur();
    assert(capteur->getIdentifiant() == "Sensor0");
    assert(capteur->getLatitude() == 44);
    assert(capteur->getLongitude() == -1);
    assert(capteur->getEstFiable() == true);
    assert(capteur->getProprietaire() == nullptr);

    vector<Capteur *> capteurs = capteurDaoCsv.findAll();
    assert(capteurs[0]->getMesures().size() == 2);
    Mesure *mesure = capteurs[0]->getMesures()[0];
    assert(mesure->getDate() == "2019-01-01 12:00:00");
    assert(mesure->getValeur() == 50.25);
    assert(mesure->getCapteur() == capteurs[0]);
    assert(capteurs[1]->getMesures().size() == 0);
}

void test_association_particulier_capteur()
{
    ParticulierDaoCsv particulierDaoCsv("tests/data/users.csv");
    CapteurDaoCsv capteurDaoCsv("tests/data/sensors.csv");
    particulierDaoCsv.associerCapteurs(capteurDaoCsv.findAll());
    vector<Particulier *> particuliers = particulierDaoCsv.findAll();
    Capteur *capteur = particuliers[0]->getCapteurs()[0];
    assert(capteur->getIdentifiant() == "Sensor36");
    assert(capteur->getLatitude() == 45.2);
    assert(capteur->getLongitude() == 3.2);
    assert(capteur->getEstFiable() == true);
    assert(capteur->getProprietaire() == particuliers[0]);
    assert(particuliers[0]->getCapteurs().size() == 1);
}

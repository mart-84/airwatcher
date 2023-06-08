#include <vector>
#include <string>
#include <cassert>
#include <functional>
using namespace std;

#include "fakeDao/FakeAttributDao.h"
#include "fakeDao/FakeCapteurDao.h"
#include "fakeDao/FakeFournisseurDao.h"
#include "fakeDao/FakeMesureDao.h"
#include "fakeDao/FakeParticulierDao.h"
#include "fakeDao/FakePurificateurDao.h"
#include "../src/service/Service.h"

void test_zone_rayon_nul()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);

    auto stats = service.statistiquesZoneCirculaire(0, 0, 0, "2019-01-01 12:00:00");
    assert(stats[0] == 0);
    assert(stats[1] == 0);
    assert(stats[2] == 0);
}

void test_zone_un_capteur()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Capteur capteur1("Sensor1", true, 0, 0);
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteurDao.addCapteur(&capteur1);

    Capteur capteur2("Sensor2", true, 20, 1);
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur2));
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur2));
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur2));
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur2));
    capteurDao.addCapteur(&capteur2);

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);

    auto stats = service.statistiquesZoneCirculaire(0, 0, 10, "2019-01-01 12:00:00");
    assert(stats[0] == 1);
    assert(stats[1] == 0);
    assert(stats[2] == 0);
}

void test_zone_tous_capteurs()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Capteur capteur1("Sensor1", true, 1, 1);
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteurDao.addCapteur(&capteur1);

    Capteur capteur2("Sensor2", true, 2, 1);
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 10000, nullptr, &capteur2));
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 10000, nullptr, &capteur2));
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 10000, nullptr, &capteur2));
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 10000, nullptr, &capteur2));
    capteurDao.addCapteur(&capteur2);

    Capteur capteur3("Sensor3", true, 3, 1);
    capteur3.ajouterMesure(new Mesure("2019-01-01 12:00:00", 100000000, nullptr, &capteur3));
    capteur3.ajouterMesure(new Mesure("2019-01-01 12:00:00", 100000000, nullptr, &capteur3));
    capteur3.ajouterMesure(new Mesure("2019-01-01 12:00:00", 100000000, nullptr, &capteur3));
    capteur3.ajouterMesure(new Mesure("2019-01-01 12:00:00", 100000000, nullptr, &capteur3));
    capteurDao.addCapteur(&capteur3);

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);

    auto stats = service.statistiquesZoneCirculaire(0, 0, 100000000, "2019-01-01 12:00:00");
    assert(stats[0] == 3);
    assert(stats[1] == 10 / 3.0);
    assert(stats[2] == 5);
}

void test_zone_capteurs_bannis()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Capteur capteur1("Sensor1", true, 1, 1);
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteur1.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur1));
    capteurDao.addCapteur(&capteur1);

    Capteur capteur2("Sensor2", false, 2, 1);
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur2));
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur2));
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur2));
    capteur2.ajouterMesure(new Mesure("2019-01-01 12:00:00", 1, nullptr, &capteur2));
    capteurDao.addCapteur(&capteur2);

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);

    auto stats = service.statistiquesZoneCirculaire(0, 0, 100000000, "2019-01-01 12:00:00");
    assert(stats[0] == 1);
    assert(stats[1] == 0);
    assert(stats[2] == 0);
}
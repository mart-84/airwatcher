#include <cassert>
using namespace std;

#include "fakeDao/FakeAttributDao.h"
#include "fakeDao/FakeCapteurDao.h"
#include "fakeDao/FakeFournisseurDao.h"
#include "fakeDao/FakeMesureDao.h"
#include "fakeDao/FakeParticulierDao.h"
#include "fakeDao/FakePurificateurDao.h"
#include "../src/service/Service.h"

void test_marquer_capteur_non_fiable()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Capteur capteur("Sensor1", true, 0, 0);
    capteurDao.addCapteur(&capteur);

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);
    service.marquerCapteurNonFiable(capteur);

    assert(capteur.getEstFiable() == false);
}

void test_marquer_capteur_non_fiable_avec_proprietaire()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Capteur capteur("Sensor1", true, 0, 0);
    Particulier particulier("User1", 0, false);
    capteur.setProprietaire(&particulier);
    capteurDao.addCapteur(&capteur);

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);
    service.marquerCapteurNonFiable(capteur);

    assert(capteur.getEstFiable() == false);
    assert(particulier.getEstBanni() == true);
}

void test_marquer_capteur_non_fiable_avec_proprietaire_et_autres_capteurs()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Capteur capteur("Sensor1", true, 0, 0);
    Particulier particulier("User1", 0, false);
    Capteur autreCapteur("Sensor2", true, 0, 1);
    particulier.ajouterCapteur(&autreCapteur);
    capteur.setProprietaire(&particulier);
    capteurDao.addCapteur(&capteur);

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);
    service.marquerCapteurNonFiable(capteur);

    assert(capteur.getEstFiable() == false);
    assert(particulier.getEstBanni() == true);
    assert(autreCapteur.getEstFiable() == false);
}

void test_ajout_point()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Capteur capteur("Sensor1", true, 0, 0);
    Particulier particulier("User1", 0, false);
    capteur.setProprietaire(&particulier);
    capteurDao.addCapteur(&capteur);

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);
    service.obtenirCapteur("Sensor1");

    assert(particulier.getPoints() == 1);
}
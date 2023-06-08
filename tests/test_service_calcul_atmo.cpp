#include <cassert>
using namespace std;

#include "fakeDao/FakeAttributDao.h"
#include "fakeDao/FakeCapteurDao.h"
#include "fakeDao/FakeFournisseurDao.h"
#include "fakeDao/FakeMesureDao.h"
#include "fakeDao/FakeParticulierDao.h"
#include "fakeDao/FakePurificateurDao.h"

void test_atmo_bon()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);

    int atmo = service.calculerIndiceATMO(0, 0, 0, 0);
    assert(atmo == 0);
}

void test_atmo_moyen()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);

    int atmo = service.calculerIndiceATMO(0, 0, 0, 15);
    assert(atmo == 1);
}

void test_atmo_extremement_mauvais()
{
    FakeAttributDao attributDao;
    FakeCapteurDao capteurDao;
    FakeFournisseurDao fournisseurDao;
    FakeMesureDao mesureDao;
    FakeParticulierDao particulierDao;
    FakePurificateurDao purificateurDao;

    Service service(attributDao, capteurDao, fournisseurDao, mesureDao, particulierDao, purificateurDao);

    int atmo = service.calculerIndiceATMO(400, 0, 60, 0);
    assert(atmo == 5);
}
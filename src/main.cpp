#include <iostream>
using namespace std;

#include "dao/ICapteurDao.h"
#include "dao/CapteurDaoCsv.h"
#include "dao/IAttributDao.h"
#include "dao/AttributDaoCsv.h"
#include "dao/IFournisseurDao.h"
#include "dao/FournisseurDaoCsv.h"
#include "dao/IMesureDao.h"
#include "dao/MesureDaoCsv.h"

void test_dao();

int main(int argc, char **argv)
{

    test_dao();

    return 0;
}

void test_dao()
{
    cout << "---test dao---" << endl;
    {
        CapteurDaoCsv capteurDaoCsv;
        ICapteurDao &capteurDao = capteurDaoCsv;
        vector<Capteur *> &capteurs = capteurDao.findAll();
        for (Capteur *capteur : capteurs)
        {
            cout << *capteur << endl;
        }
    }

    {
        AttributDaoCsv attributDaoCsv;
        IAttributDao &attributDao = attributDaoCsv;
        vector<Attribut *> &attributs = attributDao.findAll();
        for (Attribut *attribut : attributs)
        {
            cout << *attribut << endl;
        }
    }

    {
        FournisseurDaoCsv fournisseurDaoCsv;
        IFournisseurDao &fournisseurDao = fournisseurDaoCsv;
        vector<Fournisseur *> &fournisseurs = fournisseurDao.findAll();
        for (Fournisseur *fournisseur : fournisseurs)
        {
            cout << *fournisseur << endl;
        }
    }

    {
        MesureDaoCsv mesureDaoCsv;
        IMesureDao &mesureDao = mesureDaoCsv;
        vector<Mesure *> &mesures = mesureDao.findAll();
        for (Mesure *mesure : mesures)
        {
            cout << *mesure << endl;
        }
    }
    cout << "---fin test dao---" << endl;
}
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

void test_dao();

int main(int argc, char **argv)
{
    // Initialisation des DAO CSV
    // Récupération des données et création des objets
    FournisseurDaoCsv fournisseurDaoCsv;
    PurificateurDaoCsv purificateurDaoCsv;
    AttributDaoCsv attributDaoCsv;
    MesureDaoCsv mesureDaoCsv;
    CapteurDaoCsv capteurDaoCsv;
    ParticulierDaoCsv particulierDaoCsv;

    // Création des associations entre les objets
    fournisseurDaoCsv.associerPurificateurs(purificateurDaoCsv.findAll());
    mesureDaoCsv.associerAttributs(attributDaoCsv.findAll());
    mesureDaoCsv.associerCapteurs(capteurDaoCsv.findAll());
    particulierDaoCsv.associerCapteurs(capteurDaoCsv.findAll());

    for (Capteur *capteur : capteurDaoCsv.findAll())
    {
        cout << *capteur << endl;
    }
    for (Particulier *particulier : particulierDaoCsv.findAll())
    {
        cout << *particulier << endl;
    }

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
        // for (Mesure *mesure : mesures)
        // {
        //     cout << *mesure << endl;
        // }
        cout << "mesures.size() = " << mesures.size() << endl;
    }

    {
        ParticulierDaoCsv particulierDaoCsv;
        IParticulierDao &particulierDao = particulierDaoCsv;
        vector<Particulier *> &particuliers = particulierDao.findAll();
        for (Particulier *particulier : particuliers)
        {
            cout << *particulier << endl;
        }
    }

    {
        PurificateurDaoCsv purificateurDaoCsv;
        IPurificateurDao &purificateurDao = purificateurDaoCsv;
        vector<Purificateur *> &purificateurs = purificateurDao.findAll();
        for (Purificateur *purificateur : purificateurs)
        {
            cout << *purificateur << endl;
        }
    }
    cout << "---fin test dao---" << endl;
}
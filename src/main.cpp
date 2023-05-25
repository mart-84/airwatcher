#include <iostream>
using namespace std;

#include "dao/CapteurDao.h"

void test_dao();

int main(int argc, char **argv)
{
    cout << "AIRWATCHER 😋" << endl;

    test_dao();

    return 0;
}

void test_dao()
{
    cout << "---test dao---" << endl;
    CapteurDao capteur_dao;
    vector<Capteur> &capteurs = capteur_dao.findAll();
    for (Capteur &capteur : capteurs)
    {
        cout << capteur << endl;
    }
    cout << "---fin test dao---" << endl;
}
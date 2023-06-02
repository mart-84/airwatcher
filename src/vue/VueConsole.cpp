/*************************************************************************
                           VueConsole  -  description
                             -------------------
    début                : 01/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Réalisation de la classe <VueConsole> (fichier VueConsole.cpp) ------------

#include <iostream>
#include <limits>
using namespace std;

#include "VueConsole.h"

void VueConsole::afficherMenu()
{
    cout << "Bienvenue sur Airwatcher !" << endl;
} //----- Fin de afficherMenu

void VueConsole::consulterDonneesCapteur()
{
    cout << "Veuillez entrer l'identifiant du capteur : ";
    string idCapteur;
    cin >> idCapteur;

    double start = clock();

    Capteur *capteur = service.obtenirCapteur(idCapteur);
    if (capteur == nullptr)
    {
        cout << "Le capteur n'existe pas." << endl;
        return;
    }
    if (!capteur->getEstFiable())
    {
        cout << "/!\\ Ce capteur n'est pas fiable." << endl;
    }
    if (capteur->getProprietaire() != nullptr)
    {
        cout << "Ce capteur appartient à un individu privé." << endl;
    }
    else
    {
        cout << "Ce capteur appartient à l'agence." << endl;
    }

    cout << "Les données du capteur : " << endl;
    cout << "Latitude : " << capteur->getLatitude() << endl;
    cout << "Longitude : " << capteur->getLongitude() << endl;
    const unsigned int max = 10;
    cout << "Mesures (les " << max << " premières):" << endl;
    vector<Mesure *> mesure = capteur->getMesures();
    unsigned int i;
    float moyenneO3 = 0;
    float moyenneSO2 = 0;
    float moyenneNO2 = 0;
    float moyennePM10 = 0;
    for (i = 0; i < max && i < mesure.size() / 4; i++)
    {
        moyenneO3 += mesure[4 * i]->getValeur();
        moyenneSO2 += mesure[4 * i + 1]->getValeur();
        moyenneNO2 += mesure[4 * i + 2]->getValeur();
        moyennePM10 += mesure[4 * i + 3]->getValeur();
        int atmo = service.calculerIndiceATMO(mesure[4 * i]->getValeur(), mesure[4 * i + 1]->getValeur(), mesure[4 * i + 2]->getValeur(), mesure[4 * i + 3]->getValeur());
        cout << "date : " << mesure[4 * i]->getDate() << " "
             << "valeur d'O3 : " << mesure[4 * i]->getValeur() << " "
             << "valeur de s02 : " << mesure[4 * i + 1]->getValeur() << " "
             << "valeur de no2 : " << mesure[4 * i + 2]->getValeur() << " "
             << "valeur de pm10 : " << mesure[4 * i + 3]->getValeur() << " "
             << "indice ATMO : " << atmo
             << endl;
    }
    cout << endl;
    cout << "Résumé : " << endl;
    cout << "moyenne d'O3 : " << moyenneO3 / max << endl;
    cout << "moyenne de SO2 : " << moyenneSO2 / max << endl;
    cout << "moyenne de NO2 : " << moyenneNO2 / max << endl;
    cout << "moyenne de PM10 : " << moyennePM10 / max << endl;
    cout << "indice ATMO : " << service.calculerIndiceATMO(moyenneO3 / max, moyenneSO2 / max, moyenneNO2 / max, moyennePM10 / max) << endl;

    double end = clock();
    double time = (end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Temps d'exécution : " << time << " ms" << endl;

    cout << endl;
    cout << "Menu : " << endl;
    cout << "1. Marquer comme non fiable" << endl;
    cout << "2. Consulter la liste des capteurs simialires" << endl;
    cout << "3. Retour au menu" << endl;
    int choix = saisirEntier();
    switch (choix)
    {
    case 1:
        service.marquerCapteurNonFiable(*capteur);
        cout << "Le capteur a été marqué comme non fiable." << endl;
        break;
    case 2:
        cout << "Cette fonctionnalité n'est pas encore implémentée." << endl;
        break;
    }
} //----- Fin de consulterDonneesCapteur

VueConsole::VueConsole(Service &s)
    : service(s)
{
#ifdef MAP
    cout << "Appel au constructeur de <VueConsole> sur " << this << endl;
#endif
} //----- Fin de VueConsole

VueConsole::~VueConsole()
{
#ifdef MAP
    cout << "Appel au destructeur de <VueConsole> sur " << this << endl;
#endif
} //----- Fin de ~VueConsole

int VueConsole::saisirEntier()
{
    int entier;
    cin >> entier;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Veuillez entrer un entier : ";
        cin >> entier;
    }
    return entier;
} //----- Fin de saisirEntier

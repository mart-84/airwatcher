/*************************************************************************
                           VueConsole  -  description
                             -------------------
    debut                : 01/06/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Realisation de la classe <VueConsole> (fichier VueConsole.cpp) ------------

#include <iostream>
#include <limits>
#include <chrono>
using namespace std;

#include "VueConsole.h"

void VueConsole::afficherMenu()
{
    cout << "+-------------------------------------------------+" << endl
         << "|                    AirWatcher                   |" << endl
         << "+-------------------------------------------------+" << endl
         << endl
         << "Choisissez votre role :" << endl
         << "1. Agence gouvernementale" << endl
         << "2. Fournisseur de purificateur" << endl
         << "3. Particulier" << endl
         << endl;

    int choix = saisirEntier();
    switch (choix)
    {
    case 1:
        afficherMenuAgence();
        break;

    default:
        cout << "Choix invalide ou fonctionnalitee pas encore implementee." << endl;
        afficherMenu();
        break;
    }
} //----- Fin de afficherMenu

void VueConsole::afficherMenuAgence()
{
    cout << "+-------------------------------------------------+" << endl
         << "|       Bienvenue sur l'espace de l'agence        |" << endl
         << "+-------------------------------------------------+" << endl
         << endl
         << "Menu :" << endl
         << "1. Consulter les donnees d'un capteur" << endl
         << "2. Consulter les donnees d'un purificateur" << endl
         << "3. Consulter les statistiques" << endl
         << endl;

    int choix = saisirEntier();
    switch (choix)
    {
    case 1:
        consulterDonneesCapteur();
        break;

    case 3:
        afficherMenuStatistiques();
        break;

    default:
        cout << "Choix invalide ou fonctionnalitee pas encore implementee" << endl;
        afficherMenuAgence();
        break;
    }
} //----- Fin de afficherMenuAgence

void VueConsole::afficherMenuStatistiques()
{
    cout << "Quel type d'informations souhaitez-vous consulter ?" << endl
         << "1. Statistiques sur l'impact des purificateurs sur la qualite de l'air" << endl
         << "2. Statistiques sur la qualite de l'air pour une zone circulaire" << endl
         << "3. Retour menu principal" << endl
         << endl;

    int choix = saisirEntier();
    switch (choix)
    {
    case 2:
        afficherMenuStatistiquesZoneCirculaire();
        break;

    case 3:
        afficherMenuAgence();
        break;

    default:
        cout << "Choix invalide ou fonctionnalitee pas encore implementee" << endl;
        afficherMenuStatistiques();
        break;
    }

} //----- Fin de afficherMenuStatistiques

void VueConsole::afficherMenuStatistiquesZoneCirculaire()
{
    double latitude, longitude;
    int rayon;
    string date_debut, date_fin;

    cout << "Veuillez indiquer les informations de la zone geographique : " << endl;
    cout << "Latitude : ";
    latitude = saisirDouble();

    cout << "Longitude : ";
    longitude = saisirDouble();

    cout << "Rayon : ";
    rayon = saisirEntier();

    cout << "Date de debut (format : AAAA-MM-JJ hh:mm:ss) : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, date_debut);

    cout << "Date de fin (format : AAAA-MM-JJ hh:mm:ss) (optionnelle) : ";
    getline(cin, date_fin);

    cout << endl;

    auto start = chrono::high_resolution_clock::now();
    auto donnees = service.statistiquesZoneCirculaire(longitude, latitude, rayon, date_debut, date_fin);
    auto end = chrono::high_resolution_clock::now();

    if (donnees[0] == 0. && donnees[1] == 0. && donnees[2] == 0.)
    {
        cout << "Aucune donnee trouvee pour ces parametres." << endl;
        cout << endl;
    }
    else
    {
        double temps = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "(les donnees ont ete generees en : " << temps << "ms)" << endl
             << endl;

        cout << "Voici nos resultats pour la zone de centre (" << latitude << "; " << longitude << ") et pour rayon " << rayon << " km, le " << date_debut;

        if (date_fin != "")
        {
            cout << " jusqu'au " << date_fin;
        }

        cout << "." << endl
             << endl;

        cout << "Nombre de capteurs trouvees : " << donnees[0] << endl
             << endl;

        cout << "+-------------------------------------------------+" << endl;
        cout << "|         Statistique         |      Valeur       |" << endl;
        cout << "+-------------------------------------------------+" << endl;
        cout << "| Moyenne indice ATMO         | " << donnees[1] << endl;
        cout << "| Mediane indice ATMO         | " << donnees[2] << endl;
        cout << "+-------------------------------------------------+" << endl
             << endl;
    }

    cout << "1. Retour menu principal" << endl
         << endl;

    int choix = saisirEntier();

    switch (choix)
    {
    case 1:
        afficherMenuStatistiques();
        break;

    default:
        cout << "Choix invalide ou fonctionnalitee pas encore implementee" << endl;
        afficherMenuStatistiquesZoneCirculaire();
        break;
    }

} //----- Fin de afficherMenuStatistiquesZoneCirculaire

void VueConsole::consulterDonneesCapteur()
{
    cout << "Veuillez entrer l'identifiant du capteur : ";
    string idCapteur;
    cin >> idCapteur;

    auto start = chrono::high_resolution_clock::now();

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
        cout << "Ce capteur appartient a un individu prive." << endl;
    }
    else
    {
        cout << "Ce capteur appartient a l'agence." << endl;
    }

    cout << "Les donnees du capteur : " << endl;
    cout << "Latitude : " << capteur->getLatitude() << endl;
    cout << "Longitude : " << capteur->getLongitude() << endl;
    const unsigned int max = 10;
    cout << "Mesures (les " << max << " premieres):" << endl;
    vector<Mesure *> mesures = capteur->getMesures();
    float moyenneO3 = 0;
    float moyenneSO2 = 0;
    float moyenneNO2 = 0;
    float moyennePM10 = 0;
    for (unsigned int i = 0; i < max && i < mesures.size() / 4; i++)
    {
        double o3 = mesures[i * 4]->getValeur();
        double so2 = mesures[i * 4 + 1]->getValeur();
        double no2 = mesures[i * 4 + 2]->getValeur();
        double pm10 = mesures[i * 4 + 3]->getValeur();

        moyenneO3 += o3;
        moyenneSO2 += so2;
        moyenneNO2 += no2;
        moyennePM10 += pm10;

        int atmo = service.calculerIndiceATMO(o3, so2, no2, pm10);
        cout << "date : " << mesures[4 * i]->getDate() << " "
             << "valeur d'O3 : " << mesures[4 * i]->getValeur() << " "
             << "valeur de s02 : " << mesures[4 * i + 1]->getValeur() << " "
             << "valeur de no2 : " << mesures[4 * i + 2]->getValeur() << " "
             << "valeur de pm10 : " << mesures[4 * i + 3]->getValeur() << " "
             << "indice ATMO : " << atmo
             << endl;
    }
    cout << endl
         << "Resume des mesures : " << endl
         << "moyenne d'O3 : " << moyenneO3 / max << endl
         << "moyenne de SO2 : " << moyenneSO2 / max << endl
         << "moyenne de NO2 : " << moyenneNO2 / max << endl
         << "moyenne de PM10 : " << moyennePM10 / max << endl
         << "indice ATMO moyen : " << service.calculerIndiceATMO(moyenneO3 / max, moyenneSO2 / max, moyenneNO2 / max, moyennePM10 / max) << endl;

    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << endl
         << "(les donnees ont ete generees en : " << time << "ms)" << endl;

    cout << endl;
    cout << "Menu : " << endl;
    cout << "1. Marquer comme non fiable" << endl;
    cout << "2. Consulter la liste des capteurs similaires" << endl;
    cout << "3. Retour au menu" << endl;
    int choix = saisirEntier();
    switch (choix)
    {
    case 1:
        service.marquerCapteurNonFiable(*capteur);
        cout << "Le capteur a ete marque comme non fiable." << endl;
        break;
    case 2:
        cout << "Cette fonctionnalite n'est pas encore implementee." << endl;
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
        cout << "> ";
        cin >> entier;
    }
    return entier;
} //----- Fin de saisirEntier

double VueConsole::saisirDouble()
{
    double d;
    cin >> d;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "> ";
        cin >> d;
    }
    return d;
} //----- Fin de saisirDouble

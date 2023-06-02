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
using namespace std;

#include "VueConsole.h"

void VueConsole::afficherMenu()
{
    cout << "+-------------------------------------------------+" << endl;
    cout << "|                    AirWatcher                   |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    cout << endl;

    cout << "Choisissez votre role :" << endl;
    cout << "1. Agence gouvernementale" << endl;
    cout << "2. Fournisseur de purificateur" << endl;
    cout << "3. Particulier" << endl;

    cout << endl;

    int choix = saisirEntier();

    switch(choix) 
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
    cout << "+-------------------------------------------------+" << endl;
    cout << "|       Bienvenue sur l'espace de l'agence        |" << endl;
    cout << "+-------------------------------------------------+" << endl;

    cout << endl;

    cout << "Menu :" << endl;

    cout << "1. Consulter les donnees d'un capteur" << endl;
    cout << "2. Consulter les donnees d'un purificateur" << endl;
    cout << "3. Consulter les statistiques" << endl;

    cout << endl;

    int choix = saisirEntier();

    switch(choix) 
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
    cout << "Quel type d'informations souhaitez-vous consulter ?" << endl;

    cout << "1. Statistiques sur l'impact des purificateurs sur la qualite de l'air" << endl;
    cout << "2. Statistiques sur la qualite de l'air pour une zone circulaire" << endl;
    cout << "3. Retour menu principal" << endl;

    cout << endl;

    int choix = saisirEntier();

    switch(choix) 
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
    std::string date_debut, date_fin;

    cout << "Veuillez indiquer les informations de la zone geographique : " << endl;
    cout << "Latitude : ";
    latitude = saisirDouble();

    cout << "Longitude : ";
    longitude = saisirDouble();

    cout << "Rayon : ";
    rayon = saisirEntier();

    cout << "Date de debut (format : AAAA-MM-JJ hh:mm:ss) : ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(cin, date_debut);

    cout << "Date de fin (format : AAAA-MM-JJ hh:mm:ss) (optionnelle) : ";
    std::getline(cin, date_fin);

    cout << endl;

    double temps = 0.;
    auto donnees = service.statistiquesZoneCirculaire(latitude, longitude, rayon, date_debut, date_fin, &temps);

    if(donnees[0] == 0. && donnees[1] == 0. && donnees[2] == 0.)
    {
        cout << "Aucune donnee trouvee pour ces parametres." << endl;
        cout << endl;
    }
    else
    {
        cout << "(les donnees ont ete generees en : " << temps << "ms)" << endl << endl;

        cout << "Voici nos resultats pour la zone de centre (" << latitude << "; " << longitude << ") et pour rayon " << rayon << " km, le " << date_debut;

        if(date_fin != "")
        {
            cout << " jusqu'au " << date_fin;
        }

        cout << "." << endl << endl;

        cout << "Nombre de capteurs trouvees : " << donnees[0] << endl << endl;

        cout << "+-------------------------------------------------+" << endl;
        cout << "|         Statistique         |      Valeur       +" << endl;
        cout << "+-------------------------------------------------+" << endl;
        cout << "| Moyenne indice ATMO         | " << donnees[1] << endl;
        cout << "| Mediane indice ATMO         | " << donnees[2] << endl;
        cout << "+-------------------------------------------------+" << endl << endl;
    }

    cout << "1. Retour menu principal" << endl << endl;

    int choix = saisirEntier();

    switch(choix) 
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
    cout << "Resume : " << endl;
    cout << "moyenne d'O3 : " << moyenneO3 / max << endl;
    cout << "moyenne de SO2 : " << moyenneSO2 / max << endl;
    cout << "moyenne de NO2 : " << moyenneNO2 / max << endl;
    cout << "moyenne de PM10 : " << moyennePM10 / max << endl;
    cout << "indice ATMO : " << service.calculerIndiceATMO(moyenneO3 / max, moyenneSO2 / max, moyenneNO2 / max, moyennePM10 / max) << endl;

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
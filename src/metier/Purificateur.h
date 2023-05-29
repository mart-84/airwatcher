/*************************************************************************
                           Purificateur  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Purificateur> (fichier Purificateur.h) ----------------
#if !defined(PURIFICATEUR_H)
#define PURIFICATEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Purificateur>
//
//
//------------------------------------------------------------------------

class Purificateur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getIdentifiant();

    string getDateDebut();

    string getDateFin();

    double getLatitude();

    double getLongitude();

    void setIdentifiant(string id);

    void setDateDebut(string date);

    void setDateFin(string date);

    void setLatitude(double lat);

    void setLongitude(double lon);

    //------------------------------------------------- Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Purificateur &);

    Purificateur &operator=(const Purificateur &autrePurificateur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Purificateur(const Purificateur &autrePurificateur);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Purificateur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Purificateur(string unIdentifiant, string uneDateDebut, string uneDateFin, double uneLatitude, double uneLongitude);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Purificateur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string identifiant;
    string dateDebut;
    string dateFin;
    double latitude;
    double longitude;
};

//-------------------------------- Autres définitions dépendantes de <Purificateur>

#endif // PURIFICATEUR_H

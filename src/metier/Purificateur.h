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

#include <string>
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Purificateur>
//
// Représente un purificateur d'air
//------------------------------------------------------------------------

class Purificateur
{
public:
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

    friend ostream &operator<<(ostream &, Purificateur &);

    Purificateur();

    Purificateur(string unIdentifiant, string uneDateDebut, string uneDateFin, double uneLatitude, double uneLongitude);

    virtual ~Purificateur();

protected:
    string identifiant;
    string dateDebut;
    string dateFin;
    double latitude;
    double longitude;
};

#endif // PURIFICATEUR_H

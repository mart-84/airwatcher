/*************************************************************************
                           Dao  -  description
                             -------------------
    début                : 23/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <Dao> (fichier Dao.h) ----------------
#if !defined(Dao_H)
#define Dao_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Dao>
//
//
//------------------------------------------------------------------------

class Dao
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    Dao &operator=(const Dao &autreDao);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Dao(const Dao &autreDao);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Dao();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Dao();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void parse_csv(const std::string& path);

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    std::vector<std::vector<std::string>> m_lines;
};

//-------------------------------- Autres définitions dépendantes de <Dao>

#endif // Dao_H

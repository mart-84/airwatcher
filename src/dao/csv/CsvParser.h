/*************************************************************************
                           CsvParser  -  description
                             -------------------
    début                : 26/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <CsvParser> (fichier CsvParser.h) ----------------
#if !defined(CSVPARSER_H)
#define CSVPARSER_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <CsvParser>
//
//
//------------------------------------------------------------------------

class CsvParser
{
public:
    static vector<vector<string>> parse(ifstream &file);
    // Mode d'emploi :
    // Parse le fichier CSV et retourne un vecteur de vecteur de string
    // Chaque vecteur de string correspond à une ligne du fichier CSV
    // Chaque string correspond à un champ du fichier CSV
    // Contrat :
    // file doit être ouvert en lecture

protected:
};

#endif // CSVPARSER_H

/*************************************************************************
                           AttributDaoCsv  -  description
                             -------------------
    début                : 29/05/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier, Fatih Kilic, Alexis Bruneau
    e-mail               :
*************************************************************************/

//---------- Interface de la classe <AttributDaoCsv> (fichier AttributDaoCsv.h) ----------------
#if !defined(ATTRIBUTDAOCSV_H)
#define ATTRIBUTDAOCSV_H

using namespace std;

#include "../IAttributDao.h"

//------------------------------------------------------------------------
// Rôle de la classe <AttributDaoCsv>
//
// Implémentation d'un Dao d'Attribut sur des fichiers CSV
//------------------------------------------------------------------------

class AttributDaoCsv : public IAttributDao
{
public:
    AttributDaoCsv(const string &filename);

    virtual ~AttributDaoCsv();

    virtual Attribut *findByName(const string &);

    virtual vector<Attribut *> &findAll();

protected:
    vector<Attribut *> attributs;
}; //----- Fin de AttributDaoCsv

#endif // ATTRIBUTDAOCSV_H

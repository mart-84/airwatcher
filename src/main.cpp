#include <iostream>

#ifdef MAP
#include "metier/Capteur.h"

void test_dao();
#endif

int main(int argc, char **argv)
{
    std::cout << "AIRWATCHER 😋" << std::endl;

    #ifdef MAP
    test_dao();
    #endif

    return 0;
}

#ifdef MAP
void test_dao()
{
    std::cout << "---test dao---" << std::endl;
    CapteurDao capteur_dao;
    auto&& capteurs = capteur_dao.findAll();
    for(auto&& capteur: capteurs)
    {
        std::cout << capteur << std::endl;
    }

    std::cout << "---fin test dao---" << std::endl;
}
#endif
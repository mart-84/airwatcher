#include "test.h"

#include "test_csv_parser.cpp"
#include "test_dao_csv.cpp"
#include "test_service.cpp"

int main(int argc, char **argv)
{
    // CSV parser tests
    REGISTER_TEST(test_empty_file)
    REGISTER_TEST(test_parse_one_line)
    REGISTER_TEST(test_parse_many_lines)

    // DAO CSV tests
    REGISTER_TEST(test_attribut_dao)
    REGISTER_TEST(test_capteur_dao)
    REGISTER_TEST(test_fournisseur_dao)
    REGISTER_TEST(test_mesure_dao)
    REGISTER_TEST(test_particulier_dao)
    REGISTER_TEST(test_purificateur_dao)

    // DAO CSV associations tests
    REGISTER_TEST(test_association_fournisseur_purificateur)
    REGISTER_TEST(test_association_mesure_attribut)
    REGISTER_TEST(test_association_mesure_capteur)
    REGISTER_TEST(test_association_particulier_capteur)

    // service statistiques zone circulaire tests
    REGISTER_TEST(test_service_zone_rayon_nulle)
    REGISTER_TEST(test_service_zone_rayon_univers)
    REGISTER_TEST(test_service_zone_deux_capteurs)

    RUN_TESTS()

    return 0;
}
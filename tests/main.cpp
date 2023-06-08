#include "test.h"

#include "test_csv_parser.cpp"
#include "test_dao_csv.cpp"
#include "test_service_calcul_atmo.cpp"

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

    // DAO CSV methods tests
    REGISTER_TEST(test_attribut_find_by_name)
    REGISTER_TEST(test_attribut_find_by_name_non_existing)
    REGISTER_TEST(test_capteur_find_by_id)
    REGISTER_TEST(test_capteur_find_by_id_non_existing)
    REGISTER_TEST(test_capteur_dans_zone_circulaire)
    REGISTER_TEST(test_capteur_dans_zone_circulaire_vide)
    REGISTER_TEST(test_fournisseur_find_by_id)
    REGISTER_TEST(test_fournisseur_find_by_id_non_existing)
    REGISTER_TEST(test_particulier_find_by_id)
    REGISTER_TEST(test_particulier_with_points)
    REGISTER_TEST(test_particulier_banned)
    REGISTER_TEST(test_particulier_find_by_id_non_existing)
    REGISTER_TEST(test_particulier_update_points)
    REGISTER_TEST(test_particulier_update_banned)
    REGISTER_TEST(test_purificateur_find_by_id)
    REGISTER_TEST(test_purificateur_find_by_id_non_existing)

    // service calcul indice atmo tests
    REGISTER_TEST(test_atmo_bon)
    REGISTER_TEST(test_atmo_moyen)
    REGISTER_TEST(test_atmo_extremement_mauvais)

    // service statistiques zone circulaire tests
    // REGISTER_TEST(test_service_zone_rayon_nul)
    // REGISTER_TEST(test_service_zone_rayon_univers)
    // REGISTER_TEST(test_service_zone_deux_capteurs)

    RUN_TESTS()

    return 0;
}
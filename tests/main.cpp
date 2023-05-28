#include "test.h"

#include "test_csv_parser.cpp"

int main(int argc, char **argv)
{
    REGISTER_TEST(test_empty_file)
    REGISTER_TEST(test_parse_one_line)
    REGISTER_TEST(test_parse_many_lines)

    RUN_TESTS()

    return 0;
}
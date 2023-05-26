#include "test_csv_parser.cpp"

int main(int argc, char **argv)
{
    test_empty_file();
    test_parse_one_line();
    // vector<string> files = {"dataset/empty.csv", "dataset/attributes.csv", "dataset/cleaners.csv", "dataset/measurements.csv", "dataset/providers.csv", "dataset/sensors.csv", "dataset/users.csv"};
    // for (string &filename : files)
    // {
    //     ifstream file(filename);
    //     vector<vector<string>> result = CsvParser::parse(file);
    //     cout << "File : " << filename << endl;
    //     cout << "Lines parsed : " << result.size() << endl;
    // }

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

#include "../src/dao/CsvParser.h"

void test_empty_file()
{
    string filename = "tests/data/empty.csv";
    ifstream file(filename);
    vector<vector<string>> result = CsvParser::parse(file);
    assert(result.size() == 0);
    cout << "test_empty_file passed" << endl;
}

void test_parse_one_line()
{
    string filename = "tests/data/one.csv";
    ifstream file(filename);
    vector<vector<string>> result = CsvParser::parse(file);
    assert(result.size() == 1);
    assert(result[0].size() == 3);
    assert(result[0][0] == "aaaaa");
    assert(result[0][1] == "bbbbb");
    assert(result[0][2] == "ccccc");
    cout << "test_parse_one_line passed" << endl;
}

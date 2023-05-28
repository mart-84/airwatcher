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
}

void test_parse_many_lines()
{
    string filename = "tests/data/many.csv";
    ifstream file(filename);
    vector<vector<string>> result = CsvParser::parse(file);
    assert(result.size() == 3);
    assert(result[0].size() == 2);
    assert(result[0][0] == "aaa");
    assert(result[0][1] == "bbb");
    assert(result[1].size() == 2);
    assert(result[1][0] == "ccc");
    assert(result[1][1] == "ddd");
    assert(result[2].size() == 2);
    assert(result[2][0] == "eee");
    assert(result[2][1] == "fff");
}

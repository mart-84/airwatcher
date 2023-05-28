#include <vector>
#include <string>
#include <utility>
using namespace std;

vector<pair<string, void (*)()>> tests = {};

#define REGISTER_TEST(test) tests.push_back(make_pair(#test, test));

#define RUN_TESTS()                                      \
    {                                                    \
        for (auto &test : tests)                         \
        {                                                \
            test.second();                               \
            cout << test.first << " passed" << endl;     \
        }                                                \
        cout << tests.size() << " tests passed" << endl; \
    }

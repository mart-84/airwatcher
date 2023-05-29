#include <vector>
#include <string>
#include <utility>
#include <iostream>

std::vector<std::pair<std::string, void (*)()>> tests = {};

#define REGISTER_TEST(test) tests.push_back(make_pair(#test, test));

#define RUN_TESTS()                                                \
    {                                                              \
        for (auto &test : tests)                                   \
        {                                                          \
            test.second();                                         \
            std::cout << test.first << " passed" << std::endl;     \
        }                                                          \
        std::cout << tests.size() << " tests passed" << std::endl; \
    }

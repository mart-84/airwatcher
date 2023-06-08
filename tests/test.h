#include <vector>
#include <string>
#include <utility>
#include <iostream>

std::vector<std::pair<std::string, void (*)()>> tests = {};

#define REGISTER_TEST(test) tests.push_back(make_pair(#test, test));

#define RUN_TESTS()                                                                    \
    {                                                                                  \
        for (auto &test : tests)                                                       \
        {                                                                              \
            test.second();                                                             \
            std::cout << test.first << " \033[1;32mpassed\033[0m" << std::endl;        \
        }                                                                              \
        std::cout << tests.size() << " tests passed" << std::endl;                     \
        std::cout << "                                   .''. " << endl;               \
        std::cout << "       .''.      .        *''*    :_\\/_:     . " << endl;       \
        std::cout << "      :_\\/_:   _\\(/_  .:.*_\\/_*   : /\\ :  .'.:.'. " << endl; \
        std::cout << "  .''.: /\\ :   ./)\\   ':'* /\\ * :  '..'.  -=:o:=- " << endl;  \
        std::cout << " :_\\/_:'.:::.    ' *''*    * '.\'/.' _\\(/_'.':'.' " << endl;   \
        std::cout << " : /\\ : :::::     *_\\/_*     -= o =-  /)\\    '  * " << endl;  \
        std::cout << "  '..'  ':::'     * /\\ *     .'/.\'.   ' " << endl;             \
        std::cout << "      *            *..*         : " << endl;                     \
        std::cout << "        * " << endl;                                             \
    }

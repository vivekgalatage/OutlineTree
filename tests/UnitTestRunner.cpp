#include "testing/Test.h"
#include "testing/TestFramework.h"

#include <string>
#include <iostream>
using namespace std;

using namespace otree::testing;

typedef std::map<std::string, TestGenerator> TestMap;

namespace otree {
namespace testing {
class UnitTestRunner
{
public:
    bool execute();
};

bool UnitTestRunner::execute()
{
    TestMap& map = TestFramework::instance().m_registry;
    cout << "Running unit tests...\n";

    for (TestMap::iterator it = map.begin(); it != map.end(); ++it) {
        TestGenerator tg = (*it).second;
        if (tg) {
            Test* tc = (*tg)();
            if (tc) {
                bool result = tc->run();
                cout << "\t" << tc->description() << ": " << (result ? "Passed" : "Failed") << endl;
            }
        }
    }
    return true;
}

}; // namespace testing
}; // namespace otree

int main(int argc, char** argv)
{
    UnitTestRunner ut;
    ut.execute();
    return 0;
}

#include "TestFramework.h"

namespace otree {
namespace testing {

TestFramework& TestFramework::instance()
{
    static TestFramework inst;
    return inst;
}

Test* TestFramework::create(const std::string& id)
{
    Test* test = 0;

    TestFramework& inst = TestFramework::instance();

    std::map<std::string, TestGenerator>::iterator value = inst.m_registry.find(id);
    if (value != inst.m_registry.end()) {
        TestGenerator generator = value->second;
        if (generator)
            test = (*generator)();
    }

    return test;
}

bool TestFramework::addToRegistry(const std::string& id, TestGenerator testGenerator)
{
    TestFramework& inst = TestFramework::instance();
    inst.m_registry[id] = testGenerator;
    return true;
}

}; // namespace testframework
}; // namespace ds

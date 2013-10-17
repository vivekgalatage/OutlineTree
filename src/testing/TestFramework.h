#ifndef OTREE_TESTING_TESTFRAMEWORK_H
#define OTREE_TESTING_TESTFRAMEWORK_H

#include <string>
#include <map>

namespace otree {
namespace testing {

class Test;
class UnitTestRunner;

typedef Test* (*TestGenerator)();

class TestFramework
{
public:
    static Test* create(const std::string& id);
    static bool addToRegistry(const std::string& id, TestGenerator);

private:
    static TestFramework& instance();

private:
    std::map<std::string, TestGenerator> m_registry;

    friend class UnitTestRunner;
};

template <typename T>
Test* testGenerator()
{
    return new T();
}

#define REGISTER_TEST(className) \
    bool _id##className = ds::testing::TestFramework::addToRegistry(#className, ds::testing::testGenerator<className>)

}; // namespace testing
}; // namespace otree

#endif // OTREE_TESTING_TESTFRAMEWORK_H

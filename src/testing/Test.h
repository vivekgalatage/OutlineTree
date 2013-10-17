#ifndef OTREE_TESTING_TEST_H
#define OTREE_TESTING_TEST_H

#include <string>

namespace otree {
namespace testing {
class Test
{
public:
    virtual ~Test() { }
    virtual bool run() = 0;
    virtual std::string description() = 0;
};

}; // namespace testing
}; // namespace otree

#endif // OTREE_TESTING_TEST_H


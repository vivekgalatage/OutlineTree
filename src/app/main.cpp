#include "CommandLine.h"
#include "utils/Log.h"

using namespace otree;

#define USAGE_INFORMATION \
"\n" \
"otree: Displays outline information for the C++ source code.\n" \
"Usage:\n" \
"    -h, --help: Dispalys this message.\n" \

inline void displayUsageInformation()
{
    INFO(USAGE_INFORMATION);
}

int main(int argc, char* argv[])
{
    CommandLine::Error error;
    CommandLine::initialize(argc, argv, error);
    if (error.code == CommandLine::Error::kInvalidArgumentError) {
        ERROR("Invalid argument" << (error.arguments.size() > 1 ? "s" : "")) ;
        for (unsigned i = 0; i < error.arguments.size(); ++i)
            ERROR("    " << error.arguments[i]);
        displayUsageInformation();
        return -1;
    }

    CommandLine& cmdLine = CommandLine::current();
    if (cmdLine.hasArgument("help") || cmdLine.hasArgument("h")) {
        displayUsageInformation();
        return 0;
    }

    if (!cmdLine.arguments().size()) {
        cmdLine.addArgument("working-directory", ".");
    }

    for (auto arg : cmdLine.arguments())
        LOG(arg);

    return 0;
}


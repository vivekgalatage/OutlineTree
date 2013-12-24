#include "CommandLine.h"
#include "utils/Log.h"

using namespace otree;

#define USAGE_INFORMATION \
"otree: Displays outline information for the C++ source code.\n" \
"\n" \
"Usage:\n" \
"    -h, --help                 Dispalys this message.\n" \
"    -i, --ignore-case          Ignore case.\n" \
"    -w, --working-directory    Working directory in which the command should be run.\n"

inline void displayUsageInformation()
{
    INFO(USAGE_INFORMATION);
}

const char* kSupportedArguments[] = {
    "h",
    "help",
    "i",
    "ignore-case",
    "w",
    "working-directory"
};

inline bool isSupportedArgument(const string& arg)
{
    const int length = sizeof(kSupportedArguments)/sizeof(char*);
    for (int i = 0; i < length; ++i) {
        if (arg == kSupportedArguments[i])
            return true;
    }
    return false;
}

inline bool isSupportedArgument(char arg)
{
    return isSupportedArgument(string(&arg));
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

    for (auto arg : cmdLine.arguments()) {
        if (!isSupportedArgument(arg)) {
            bool validCombination = true;
            for (unsigned i = 0; i < arg.size(); ++i) {
                if (!isSupportedArgument(arg[i])) {
                    validCombination = false;
                    break;
                } else {
                    cmdLine.addArgument(arg[i]);
                }
            }
            if (!validCombination) {
                ERROR("Invalid argument \"" << arg << "\"\n");
                displayUsageInformation();
                break;
            }
        }
    }
    return 0;
}


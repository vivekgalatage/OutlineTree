#include "CommandLine.h"
#include "utils/Log.h"
namespace otree {

inline bool startsWith(const string& src, const string& prefix)
{
    // FIXME: Convert this into an ASSERT.
    if (prefix.size() > src.size())
        return false;

    if (src.compare(0, prefix.size(), prefix) == 0) {
        string tmp = src;
        tmp.erase(0, prefix.size());
        return tmp.size() == (src.size() - src.find_first_not_of(prefix[0]));
    } else {
        return false;
    }
}

void CommandLine::initialize(int argc, char** argv, Error& error)
{
    current().parseFrom(argc, argv, error);
}

CommandLine& CommandLine::current()
{
    static CommandLine instance;
    return instance;
}

bool CommandLine::parseFrom(int argc, char** argv, Error& error)
{
    for (int i = 1; i < argc; ++i) {
        string arg(argv[i]);
        if (startsWith(arg, "--")) {
            arg.erase(0, 2);
        } else if (startsWith(arg, "-")) {
            arg.erase(0, 1);
        } else {
            error.code = Error::kInvalidArgumentError;
            error.arguments.push_back(arg);
        }

        if (error.code == Error::kNoError) {
            unsigned delimeterPosition = arg.find_first_of("=");
            string key = arg.substr(0, delimeterPosition);
            string value;
            if (delimeterPosition < arg.size())
                value = arg.substr(delimeterPosition + 1, arg.size());
            arguments_[key] = value;
        }
    }
    return true;
}

vector<string> CommandLine::arguments() const
{
    vector<string> listOfArguments;
    for (auto imap: arguments_)
        listOfArguments.push_back(imap.first);
    return listOfArguments;
}

bool CommandLine::hasArgument(const string& arg) const
{
    auto it = arguments_.find(arg);
    return it != arguments_.end();
}

void CommandLine::addArgument(const string& arg, const string& value)
{
    arguments_[arg] = value;
}

}; // namespace otree

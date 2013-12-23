#ifndef APP_COMMANDLINE_H_
#define APP_COMMANDLINE_H_

#include <map>
#include <string>
#include <vector>

using namespace std;

namespace otree {

class CommandLine {
public:
    struct Error {
        typedef enum {
            kNoError,
            kInvalidArgumentError
        } Code;

        Error() : code(kNoError) { }

        int code;
        vector<string> arguments;
    };

public:
    static void initialize(int argc, char** argv, Error& error);
    static CommandLine& current();

    vector<string> arguments() const;
    bool hasArgument(const string& argument) const;

    void addArgument(const string& arg, const string& value = "");

private:
    CommandLine() { }

    void parseFrom(int argc, char** argv, Error& error);

private:
    map<string, string> arguments_;
};

}; // namespace otree

#endif // APP_COMMANDLINE_H_

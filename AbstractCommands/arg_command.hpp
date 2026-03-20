#ifndef ARG_COMMAND_HPP
#define ARG_COMMAND_HPP
#include "command.hpp"

class ArgCommand : public Command {
public:
    ArgCommand(Emulator* e);

    void setIn() override;

    void setOut() override;

    std::string getQuotes();

    virtual void getArg();

    std::string argument;

    bool allow_redirection;
};

#endif
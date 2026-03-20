#ifndef OPT_COMMAND_HPP
#define OPT_COMMAND_HPP
#include "arg_command.hpp"

class OptCommand : public ArgCommand {
public:
    OptCommand(Emulator* e) 
    : ArgCommand(e),
      operation("") {};

    virtual void getOpt() = 0;

    std::string operation;
};

#endif
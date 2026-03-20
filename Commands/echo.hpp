#ifndef ECHO_HPP
#define ECHO_HPP
#include "../AbstractCommands/arg_command.hpp"

class Echo : public ArgCommand {
public:
    Echo(Emulator* e);

    void process() override;

    void run() override;
};

#endif
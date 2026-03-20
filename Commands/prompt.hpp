#ifndef PROMPT_HPP
#define PROMPT_HPP
#include "../AbstractCommands/arg_command.hpp"

class Prompt : public ArgCommand {
public:
    Prompt(Emulator* e);

    void process() override;

    void run() override;

    void setOut() override;
};

#endif
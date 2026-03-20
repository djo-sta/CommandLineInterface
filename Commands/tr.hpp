#ifndef TR_HPP
#define TR_HPP
#include "../AbstractCommands/opt_command.hpp"

class Tr : public OptCommand {
public:
    Tr(Emulator* e);

    void setIn() override;

    void getOpt() override;

    void getWith();

    void process() override;

    void run() override;

    std::string with;
};

#endif
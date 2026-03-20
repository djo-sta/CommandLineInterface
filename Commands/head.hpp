#ifndef HEAD_HPP
#define HEAD_HPP
#include "../AbstractCommands/opt_command.hpp"

class Head : public OptCommand {
public:
    Head(Emulator* e);

    void getOpt() override;

    void process() override;

    void run() override;

    int num_of_lines;
};

#endif
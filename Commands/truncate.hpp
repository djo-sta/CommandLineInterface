#ifndef TRUNCATE_HPP
#define TRUNCATE_HPP
#include "../AbstractCommands/file_command.hpp"

class Truncate : public FileCommand {
public:
    Truncate(Emulator* e);

    void process() override;

    void run() override;
};


#endif
#ifndef RM_HPP
#define RM_HPP
#include "../AbstractCommands/file_command.hpp"

class Rm : public FileCommand {
public:
    Rm(Emulator* e);

    void process() override;

    void run() override;
};

#endif
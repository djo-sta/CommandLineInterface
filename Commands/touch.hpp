#ifndef TOUCH_HPP
#define TOUCH_HPP
#include "../AbstractCommands/file_command.hpp"

class Touch : public FileCommand {
public:
    Touch(Emulator* e);

    void process() override;

    void run() override;
};

#endif
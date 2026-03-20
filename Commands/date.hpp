#ifndef DATE_HPP
#define DATE_HPP
#include "../AbstractCommands/time_command.hpp"

class Date : public TimeCommand {

public:

    Date(Emulator* e);

    void process() override;

    void run() override;
};

#endif
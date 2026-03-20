#ifndef TIME_HPP
#define TIME_HPP
#include "../AbstractCommands/time_command.hpp"

class Time : public TimeCommand {

public:

    Time(Emulator* e);

    void process() override;

    void run() override;
};

#endif
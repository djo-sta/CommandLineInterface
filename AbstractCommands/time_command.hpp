#ifndef TIME_COMMAND
#define TIME_COMMAND
#include "command.hpp"
#include <ctime>

class TimeCommand : public Command {

public:
    
    TimeCommand(Emulator* e);

    void setIn() override;

    void setOut() override;

    time_t now;

    tm* t;
};

#endif
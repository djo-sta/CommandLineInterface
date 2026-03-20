#ifndef BATCH_HPP
#define BATCH_HPP
#include "../AbstractCommands/file_command.hpp"
#include <sstream>

class Batch : public FileCommand {
public:
    Batch(Emulator* e);

    void setOut() override;

    void process() override;

    void run() override;
};

#endif
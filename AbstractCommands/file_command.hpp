#ifndef FILE_COMMAND_HPP
#define FILE_COMMAND_HPP
#include "command.hpp"

class FileCommand : public Command {

public:

    FileCommand(Emulator* e);

    void setIn() override;

    void setOut() override;

    void getFile();

    std::string filename;
};

#endif
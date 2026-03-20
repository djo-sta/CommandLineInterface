#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <iostream>
#include <fstream>
#include <string>

class Emulator;

class Command {

public:

    ~Command() = default;

    Command(Emulator* e);

    virtual void run() = 0;

protected:

    virtual void process() = 0;

    virtual void setIn() = 0;

    virtual void setOut() = 0;

    void checkExcess();

    std::string getFilename();

    Emulator* emulator;

    std::istream* in;

    std::ostream* out;

    std::ifstream ifile;

    std::ofstream ofile;
};

#endif
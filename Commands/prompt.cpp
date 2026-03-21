#include "prompt.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Prompt::Prompt(Emulator* e)
    : ArgCommand(e) {}

void Prompt::process() {
    if (argument.empty()) {
        *emulator->out << "\nArgument is empty!" << endl;
        throw 2;
    }
    emulator->prompt_sign = argument;
}

void Prompt::setOut() {
    char c = emulator->peek();
    if (c != 0 && !isspace(c)) {
        *emulator->out << "\nThis command has no output stream!(6)" << endl;
        throw 0;
    }
}

void Prompt::run() {
    setIn();
    getArg();
    setOut();
    process();
}
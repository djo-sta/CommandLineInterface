#include "prompt.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Prompt::Prompt(Emulator* e)
    : ArgCommand(e) {}

void Prompt::process() {
    if (argument.empty()) {
        cout << "Argument is empty!" << endl;
        throw 0;
    }
    emulator->prompt_sign = argument;
}

void Prompt::setOut() {
    char c = emulator->peek();
    if (c != 0 && !isspace(c)) {
        cout << "This command has no output stream!(6)" << endl;
        throw 0;
    }
}

void Prompt::run() {
    setIn();
    getArg();
    setOut();
    process();
}
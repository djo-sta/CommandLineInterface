#include "echo.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Echo::Echo(Emulator* e)
    : ArgCommand(e) {}


void Echo::process() {
    if (argument.empty()) {
        *emulator->out << "Argument is empty!" << endl;
        throw 2;
    }
    *out << argument;
    if (out == &cout) *emulator->out << endl;
}

void Echo::run() {
    setIn();
    getArg();
    setOut();
    checkExcess();
    process();
}
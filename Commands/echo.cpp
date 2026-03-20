#include "echo.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Echo::Echo(Emulator* e)
    : ArgCommand(e) {}


void Echo::process() {
    if (argument.empty()) {
        cout << "Argument is empty!" << endl;
        throw 0;
    }
    *out << argument;
    if (out == &cout) cout << endl;
}

void Echo::run() {
    setIn();
    getArg();
    setOut();
    checkExcess();
    process();
}
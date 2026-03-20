#include "command.hpp"
#include "../Emulator/emulator.hpp"
#include <cctype>
using namespace std;

Command::Command(Emulator* e)
    : emulator(e),
      in(nullptr),
      out(nullptr) {}

void Command::checkExcess() {
    char c;
    emulator->eatSpaces();
    if (emulator->is_piping) {
        return;
    }
    while(1) {
        c = emulator->get();
        if (c == '\0') {
            return;
        }
        else if (c == ' ') {
            continue;
        }
        else {
            cout << "Command has too many arguments!(1)" << endl;
            throw 1;
        }
    }
}

string Command::getFilename() {
    string word = "";
    emulator->eatSpaces();
    char c = emulator->get();
    while (!iswordend(c)) {
        word += c;
        c = emulator->get();
    }
    if (word.empty()) {
        cout << "Filename not entered!(2)" << endl;
        throw 0;
    }
    return word;
}


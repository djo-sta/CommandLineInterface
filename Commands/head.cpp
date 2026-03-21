#include "head.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Head::Head(Emulator* e)
    : num_of_lines(0),
      OptCommand(e) {}

void Head::getOpt() {
    emulator->eatSpaces();
    char c = emulator->get();
    if (c == '-') {
        c = emulator->get();
        if (c == 'n') {
            int digits = 0;
            while (1) {
                c = emulator->get();
                if (isspace(c) || c==0) {
                    break;
                }
                else if (c>47 && c<58) {
                    digits++;
                    if (digits > 5) {
                        *emulator->out << "Number is too big!" << endl;
                        throw -6;
                    }
                    num_of_lines = num_of_lines*10 + c - 48;
                }
                else {
                    *emulator->out << "Syntax error: expected a number!" << (int)c << endl;
                    throw 1;
                }
            }
            if (num_of_lines == 0) {
                *emulator->out << "Number must be higher than 0!" << endl;
                throw 0;
            }
        }
        else {
            *emulator->out << "Syntax error: expected 'n'" << endl;
            throw 1;
        }
    }
    else {
        *emulator->out << "Syntax error: expected '-'" << endl;
        throw 1;
    }
}

void Head::process() {
    if (argument.empty()) {
        *emulator->out << "Argument is empty!" << endl;
        throw 2;
    }
    string lines = "";
    int num = 0;
    for (char c : argument) {
        if (c == '\n') {
            num++;
        }
        lines += c;
        if (num == num_of_lines) break;
    }
    *out << lines;
}

void Head::run() {
    getOpt();
    setIn();
    getArg();
    setOut();
    checkExcess();
    process();
}
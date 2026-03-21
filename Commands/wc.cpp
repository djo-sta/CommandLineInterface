#include "wc.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Wc::Wc(Emulator* e)
    : OptCommand(e) {}

void Wc::getOpt() {
    emulator->eatSpaces();
    char c = emulator->get();
    if (c == '-') {
        c = emulator->get();
        if (c!='w' && c!='c') {
            while(c!=' ' && c!='\0') {
                operation.push_back(c);
                c = emulator->get();
            }
            *emulator->out << "\nUnknown operation: " << operation << endl;
            throw 1;
        }
        else {
            operation.push_back(c);
        }
    }
    else {
        *emulator->out << "\nSyntax error: expected '-'!" << endl;
        throw 1;
    }
}

void Wc::wordCount() {
    if (argument.empty()) {
        *emulator->out << "\nArgument is empty!" << endl;
        throw 2;
    }
    int num = 1;
    int size = argument.size();
    for (int i=0; i<size; i++) {
        if (isspace(argument[i]) && i<size-1) {
            if (!isspace(argument[i+1])) num++;
        }
    }
    *out << num << endl;
}

void Wc::charCount() {
    if (argument.empty()) {
        *emulator->out << "\nArgument is empty!" << endl;
        throw 2;
    }
    *out << argument.size() << endl;
}

void Wc::process() {
    if (operation == "w")
        wordCount();
    else if (operation == "c")
        charCount();
    else
        throw 0;
}

void Wc::run() {
    getOpt();
    setIn();
    getArg();
    setOut();
    checkExcess();
    process();
}
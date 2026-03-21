#include "time_command.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

TimeCommand::TimeCommand(Emulator* e)
    : Command(e)
{
    now = time(nullptr);
    t = localtime(&now);
}

void TimeCommand::setIn() {
    if (emulator->is_piping) {
        *emulator->out << endl << "\nThis command has no in stream" << endl;
        throw 6;
    }
}

void TimeCommand::setOut() {
    emulator->eatSpaces();
    char c = emulator->get();
    if (c == 0) {
        out = emulator->out;
    }
    else if (c == '<') {
        *emulator->out << endl << "\nThis command has no in stream" << endl;
        throw 1;
    }
    else if (c == '>') {
        string word;
        c = emulator->peek();
        if (c == '>') {
            c = emulator->get();
            word = getFilename();
            ofile = ofstream(word, ios::app);
        }
        else {
            word = getFilename();
            ofile = ofstream(word);
        }
        out = &ofile;
    }
    else if (c == '|') {
        out = &emulator->pipe;
        emulator->is_piping = 1;
    }
    else {
        *emulator->out << endl << "\nThis command has too many arguments" << endl;
        throw 0;
    }
}


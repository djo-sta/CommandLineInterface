#include "emulator.hpp"
#include <memory>
#include <cctype>
#include "../AbstractCommands/command.hpp"
#include "../Commands/date.hpp"
#include "../Commands/time.hpp"
#include "../Commands/rm.hpp"
#include "../Commands/truncate.hpp"
#include "../Commands/touch.hpp"
#include "../Commands/echo.hpp"
#include "../Commands/prompt.hpp"
#include "../Commands/wc.hpp"
#include "../Commands/tr.hpp"
#include "../Commands/head.hpp"
#include "../Commands/batch.hpp"
using namespace std;

bool iswordend(char c) {
    if (isspace(c) || c=='\0')
        return 1;
    else
        return 0;
}

Emulator::Emulator(istream* i, ostream* o)
    : in(i),
      out(o),
      q(""),
      is_piping(0),
      position(0),
      prompt_sign("$") {}

void Emulator::eatSpaces() {
    char c;
    while(1) {
        c = peek();
        if (isspace(c)) {
            c = get();
        }
        else {
            break;
        }
    }
}

void Emulator::fillQ() {
    if (!getline(*in, q)) {
        cout << "Error";
        throw 0;
    }
}

char Emulator::get() {
    if (position >= q.size()) {
        return '\0';
    }
    else {
        return q[position++];
    }
}

char Emulator::peek() {
    if (position >= q.size()) {
        return '\0';
    }
    else {
        return q[position];
    }
}

void Emulator::createCommand() {
    eatSpaces();
    string word = "";
    char c;
    while(1) {
        c = get();
        if (iswordend(c)) {
            break;
        }
        else {
            word += c;
        }
    }
    unique_ptr<Command> cmd;
    if (word == "time") {
        cmd = make_unique<Time>(this);
        cmd->run();
    }
    else if (word == "date") {
        cmd = make_unique<Date>(this);
        cmd->run();
    }
    else if (word == "touch") {
        cmd = make_unique<Touch>(this);
        cmd->run();
    }
    else if (word == "rm") {
        cmd = make_unique<Rm>(this);
        cmd->run();
    }
    else if (word == "truncate") {
        cmd = make_unique<Truncate>(this);
        cmd->run();
    }
    else if (word == "echo") {
        cmd = make_unique<Echo>(this);
        cmd->run();
    }
    else if (word == "prompt") {
        cmd = make_unique<Prompt>(this);
        cmd->run();
    }
    else if (word == "tr") {
        cmd = make_unique<Tr>(this);
        cmd->run();
    }
    else if (word == "wc") {
        cmd = make_unique<Wc>(this);
        cmd->run();
    }
    else if (word == "head") {
        cmd = make_unique<Head>(this);
        cmd->run();
    }
    else if (word == "batch") {
        cmd = make_unique<Batch>(this);
        cmd->run();
    }
    else if (word == "exit") {
        throw 99;
    }
    else if (word.empty()) {
        
    }
    else {
        cout << "Unknown command" << word << endl;
        throw 0;
    }
}

void Emulator::process() {
    if (in == &cin) cout << endl << prompt_sign << ' ';
    fillQ();
    createCommand();
    while (is_piping) {
        createCommand();
    }
    reset();
}

void Emulator::reset() {
    q = "";
    position = 0;
    is_piping = 0;
    pipe.str("");
    pipe.clear();
    cin.clear();
}

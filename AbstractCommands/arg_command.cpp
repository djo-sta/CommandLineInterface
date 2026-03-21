#include "arg_command.hpp"
#include "../Emulator/emulator.hpp"
#include <limits>
using namespace std;

ArgCommand::ArgCommand(Emulator* e)
    : Command(e),
      allow_redirection(0),
      argument("") {}

void ArgCommand::setIn() {
    if (emulator->is_piping) {
        in = &emulator->pipe;
        emulator->is_piping = 0;
        allow_redirection = 1;
    }
    else {
        emulator->eatSpaces();
        char c = emulator->peek();
        if (c == '<') {
            emulator->get();
            string word = getFilename();
            ifile = ifstream(word);
            if (ifile) {
                in = &ifile;
            }
            else {
                *emulator->out << "File " << word << " doesnt exist!" << endl;
                throw -(int)word.size();
            }
            allow_redirection = 1;
        }
        else if (c == 0) {
            in = &cin;
        }
        else if (c == '"') {
            allow_redirection = 1;
        }
        else {
            string word = getFilename();
            ifile = ifstream(word);
            if (ifile) {
                in = &ifile;
            }
            else {
                *emulator->out << "File " << word << " doesnt exist!" << endl;
                throw -1*word.size();
            }
        }
    }
}

void ArgCommand::setOut() {
    emulator->eatSpaces();
    if (allow_redirection) {
        char c = emulator->get();
        if (c == 0) {
            out = emulator->out;
        }
        else if (c == '|') {
            out = &emulator->pipe;
            emulator->is_piping = 1;
        }
        else if (c == '>') {
            c = emulator->peek();
            if (c == '>') {
                emulator->get();
                string word = getFilename();
                ofile = ofstream(word, ios::app);
            }
            else {
                string word = getFilename();
                ofile = ofstream(word);
            }
            out = &ofile;
        }
        else {
            *emulator->out << "Command has too many arguments" << endl;
            throw 1;
        }
    }
    else {
        out = emulator->out;
        char c = emulator->get();
        if (c != 0) {
            *emulator->out << "Redirection is not allowed!" << endl;
            throw 1;
        }
    }
}

string ArgCommand::getQuotes() {
    emulator->eatSpaces();
    char c = emulator->get();

    if (c != '"') {
        *emulator->out << "Syntax error: quotes missing" << endl;
        throw 1;
    }

    bool quotes_closed = 0;
    string word = "";

    while(1) {
        c = emulator->get();
        if (c == '"') {
            quotes_closed = 1;
            break;
        }
        else if (c == 0) {
            break;
        }
        else {
            word += c;
        }
    }
    if (quotes_closed)
        return word;
    else {
        *emulator->out << "Syntax error: quotes not closed!" << endl;
        throw 0;
    }
}

void ArgCommand::getArg() {
    if (!in) {
        argument = getQuotes();
    }
    else {
        if (in == &cin) {
            char c;
            while(1) {
                c = cin.get();
                if (c == 24) {
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                else {
                    argument += c;
                }
            }
        }
        else {
            string line;
            while(getline(*in, line)) {
                argument = argument + line + '\n';
            }
            if (argument.back() == '\n') argument.pop_back();
            in->clear();
        }
    }
}
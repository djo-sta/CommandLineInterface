#include "tr.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Tr::Tr(Emulator* e)
    : with(""),
      OptCommand(e) {}

void Tr::setIn() {
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
                cout << "File " << word << " doesnt exist!" << endl;
                throw 0;
            }
            allow_redirection = 1;
        }
        else if (c == '-') {
            in = &cin;
        }
        else if (c == '"') {
            allow_redirection = 1;
        }
        else if (c == 0) {
            cout << "Command has too few arguments!" << endl;
            throw 0;
        }
        else {
            string word = getFilename();
            ifile = ifstream(word);
            if (ifile) {
                in = &ifile;
            }
            else {
                cout << "File " << word << " doesnt exist!" << endl;
                throw 0;
            }
        }
    }
}

void Tr::process() {
    char c;
    int i, j;
    string word;
    string tmp = "";
    for (i=0; i<argument.size(); i++) {
        if (argument[i] == operation.front()) {
            if (i+operation.size() <= argument.size()) {
                word = "";
                for (j=0; j<operation.size(); j++) {
                    word = word + argument[i+j];
                }
                if (word == operation) {
                    tmp = tmp + with;
                    i = i+operation.size()-1;
                }
                else {
                    tmp = tmp + argument[i];
                }
            }
            else {
                tmp = tmp + argument[i];
            }
        }
        else {
            tmp = tmp + argument[i];
        }
    }
    //cout << argument << endl << operation << endl << with << endl;
    *out << tmp;
    if (out == &cout) cout << endl;
}

void Tr::getOpt() {
    emulator->eatSpaces();
    char c = emulator->get();
    if (c == '-') {
        operation = getQuotes();
        if (operation.empty()) {
            cout << "Operation is empty!" << endl;
            throw 0;
        }
    }
    else {
        cout << "Syntax error, expected: '-'" << endl;
        throw 0;
    }
}

void Tr::getWith() {
    emulator->eatSpaces();
    char c = emulator->peek();
    if (c==0 || c=='|' || c=='>') {
        with = "";
    }
    else if (c == '"') {
        with = getQuotes();
    }
    else {
        cout << "Syntax error: quotes expected!" << endl;
        throw 0;
    } 
}

void Tr::run() {
    setIn();
    getArg();
    getOpt();
    getWith();
    setOut();
    checkExcess();
    process();
}
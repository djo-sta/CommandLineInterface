#include "batch.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Batch::Batch(Emulator* e)
    : FileCommand(e) {}

void Batch::setOut() {
    emulator->eatSpaces();
    char c = emulator->get();
    if (c == 0) {
        out = emulator->out;
    }
    else if (c == '|') {
        cout << "Batch command can't be piped!" << endl;
        throw 0;
    }
    else if (c == '>') {
        c = emulator->peek();
        if (c == '>') {
            c = emulator->get();
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
        cout << "Command has too many arguments" << endl;
        throw 0;
    }
}

void Batch::process() {
    ifile = ifstream(filename);
    string line;
    int num = 0;
    Emulator* konsole;
    if (!ifile) {
        cout << "File doesnt exist!";
        throw 1;
    }
    stringstream buffer;
    while (getline(ifile, line)) {
        num++;
    }
    ifile.clear();
    ifile.seekg(0);
    for (int i=0; i<num; i++) {
        konsole = new Emulator(&ifile, &buffer);
        try {
            konsole->process();
            }
        catch (int x) {
            //ERROR HANDLE
            if (x == 99) 
                break;
            else
                konsole->reset(); 
        }
        delete konsole;
        konsole = nullptr;
    }
    *out << buffer.str();
}

void Batch::run() {
    setIn();
    getFile();
    setOut();
    process();
}
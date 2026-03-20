#include "truncate.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Truncate::Truncate(Emulator* e)
    : FileCommand(e) {}

void Truncate::process() {
    ifstream ifajl = ifstream(filename);
    if (ifajl) {
        ofile = ofstream(filename);
        ofile << "";
    }
    else {
        cout << "File " << filename << " doesn't exist!" << endl;
        throw 0;
    }
}

void Truncate::run() {
    setIn();
    getFile();
    setOut();
    process();
}
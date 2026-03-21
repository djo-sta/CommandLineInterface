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
        *emulator->out << "File " << filename << " doesn't exist!" << endl;
        throw -(int)filename.size();
    }
}

void Truncate::run() {
    setIn();
    getFile();
    setOut();
    process();
}
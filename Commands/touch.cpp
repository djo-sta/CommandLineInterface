#include "touch.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Touch::Touch(Emulator* e)
    : FileCommand(e) {}

void Touch::process() {
    ifstream ifajl = ifstream(filename);
    if (ifajl) {
        *emulator->out << "\nFile " << filename << " already exists!" << endl;
        if (emulator->out != &cout) emulator->position--;
        throw -(int)filename.size();
    }
    else {
        ofile = ofstream(filename);
    }
}

void Touch::run() {
    setIn();
    getFile();
    setOut();
    process();
}
#include "touch.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Touch::Touch(Emulator* e)
    : FileCommand(e) {}

void Touch::process() {
    ifstream ifajl = ifstream(filename);
    if (ifajl) {
        *emulator->out << "File " << filename << " already exists!" << endl << '-' << filename.size() << '-' << endl;
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
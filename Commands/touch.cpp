#include "touch.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Touch::Touch(Emulator* e)
    : FileCommand(e) {}

void Touch::process() {
    ifstream ifajl = ifstream(filename);
    if (ifajl) {
        cout << "File " << filename << " already exists!" << endl;
        throw 0;
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
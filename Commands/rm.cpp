#include "rm.hpp"
#include "../Emulator/emulator.hpp"
#include <filesystem>
using namespace std;

Rm::Rm(Emulator* e)
    : FileCommand(e) {}

void Rm::process() {
    ifile = ifstream(filename);
    if (ifile) {
        if (!filesystem::remove(filename)) {
            cout << "File couldnt be deleted!";
            throw 1;
        }
    }
    else {
        cout << "File doesnt exist!";
        throw 1;
    }
}

void Rm::run() {
    setIn();
    getFile();
    setOut();
    process();
}

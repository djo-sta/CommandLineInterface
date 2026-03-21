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
            *emulator->out << "\nFile couldnt be deleted!";
            throw 0;
        }
    }
    else {
        *emulator->out << "\nFile doesnt exist!";
        throw -(int)filename.size();
    }
}

void Rm::run() {
    setIn();
    getFile();
    setOut();
    process();
}

#include "file_command.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

FileCommand::FileCommand(Emulator* e)
    : Command(e),
      filename("") {};

void FileCommand::setIn() {
    if (emulator->is_piping) {
        in = &emulator->pipe;
        emulator->is_piping = 0;
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
                *emulator->out << "\nFile " << filename << " doesn't exist!(3)" << endl;
                throw -(int)filename.size();
            }
        }
        else if (c == 0) {
            *emulator->out << "\nCommand has too few arguments!(4)" << endl;
            throw 0;
        }
    }
}

void FileCommand::setOut() {
    char c = emulator->peek();
    if (c != 0) {
        *emulator->out << "\nCommand has too many arguments!(5)" << endl;
        throw 1;
    }
}

void FileCommand::getFile() {
    if (!in)
        filename = getFilename();
    else {
        string bafer;
        while(getline(*in, bafer)) {
            filename = filename + bafer;
        }
    }
}
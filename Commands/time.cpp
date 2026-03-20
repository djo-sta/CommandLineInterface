#include "time.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Time::Time(Emulator* e)
    : TimeCommand(e) {}

void Time::process() {
    *out << t->tm_hour << ':' << t->tm_min << ':' << t->tm_sec << endl;
}

void Time::run() {
    setIn();
    setOut();
    process();
}
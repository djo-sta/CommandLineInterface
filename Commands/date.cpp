#include "date.hpp"
#include "../Emulator/emulator.hpp"
using namespace std;

Date::Date(Emulator* e)
    : TimeCommand(e) {}

void Date::process() {
    *out << t->tm_mday << ':' << t->tm_mon + 1 << ':' << t->tm_year + 1900 << endl;
}

void Date::run() {
    setIn();
    setOut();
    process();
}
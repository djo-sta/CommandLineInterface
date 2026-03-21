#ifndef EMULATOR_HPP
#define EMULATOR_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

class Emulator {
public:
    Emulator(std::istream* i = &std::cin, std::ostream* o = &std::cout);

    void eatSpaces();

    void createCommand();

    char get();

    char peek();

    void fillQ();

    void process();

    void reset();

    void errorHandling(int x);

    std::stringstream pipe;

    bool is_piping;

    std::string q;

    int position;

    std::string prompt_sign;

    std::istream* in;

    std::ostream* out;
};

bool iswordend(char c);

#endif
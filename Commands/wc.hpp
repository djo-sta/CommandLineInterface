#ifndef WC_HPP
#define WC_HPP
#include "../AbstractCommands/opt_command.hpp"

class Wc : public OptCommand {
public:
    Wc(Emulator* e);

    void process() override;

    void getOpt() override;

    void run() override;

    void wordCount();

    void charCount();
};

#endif
#include <iostream>
#include "Emulator/emulator.hpp"
using namespace std;


int main() {

    Emulator alacritty;
    
    while(1) {
        try {
            alacritty.process();
        }
        catch (int x) {
            if (x == 99) {
                break;
            }
            else {
                alacritty.errorHandling(x);
                alacritty.reset(); 
            }
        }
    }
    return 0;
}

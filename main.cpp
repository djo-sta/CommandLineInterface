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
            //ERROR HANDLE
            if (x == 99) 
                break;
            else
                alacritty.reset(); 
        }
    }
    return 0;
}

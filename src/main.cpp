#include "BlackjackGame.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

    #ifdef _WIN32
        // Code specific to Windows
        system("chcp 65001 > nul"); // Switch to UTF-8 to allow suit unicode characters
    #endif

    BlackjackGame BlackjackGame{6};
    BlackjackGame.start();

    while (true) {
        BlackjackGame.nextState();
    }

}
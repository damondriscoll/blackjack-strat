#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Blackjack.h"
#include <vector>
#include <string>
#include <stdlib.h>

class BlackjackGame {

public:
    BlackjackGame(int numDecks);
    void nextState();
    void start();
    void playDealerTurn();

private:
    Blackjack blackjack;
    int currentHand;
};

#endif
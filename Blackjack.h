#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"
#include <utility>

class Blackjack
{
public:
    Blackjack();
    Deck * getDeck();
    std::vector<int> possibleHandValues(std::vector<Card *> currentHand);
    bool inBoundsHand(int c);
    void playAgainCheck();
    void resetHands();

private:
    Deck * deck;
    std::vector<std::vector<Card*>> playerHands;
    std::vector<Card*> dealerHand;
    int numPlayerHands;
    
    bool running;

};

#endif
#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <random>

class Deck
{
public:
    Deck(int numberDecks);
    ~Deck();
    void refill();
    void shuffle();
    int size();
    Card * getTopCard();

private:
    int nDecks;
    std::vector<Card*> cardSet;
};

#endif
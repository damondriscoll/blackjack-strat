#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck
{
public:
    Deck(int numberDecks);
    void shuffleCards();
    Card * getTopCard();
    std::vector<Card*> getCardSet();

private:
    std::vector<Card*> cardSet;
};

#endif
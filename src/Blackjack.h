#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"

class Blackjack
{
public:
    Blackjack(int numDecks);
    ~Blackjack();

    int calculateHandValue(std::vector<Card *> hand);
    int getNumberPlayerHands();

    void hit(int handNum);
    bool split(int handNum);
    void hitDealer();

    std::vector<Card*> getDealerHand();
    std::vector<std::vector<Card*>> getPlayerHands();
    
    void displayDealerHand(bool hideFirstCard);
    void displayPlayerHands();
    void displayHand(const std::vector<Card *> &hand);
    void displayCard(const Card *card);

    void clearHands();
    void fillHands();

    Deck * getDeck();

private:
    Deck * deck;

    std::vector<std::vector<Card*>> playerHands;
    std::vector<Card*> dealerHand;

};

#endif
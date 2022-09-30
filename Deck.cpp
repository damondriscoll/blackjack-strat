#include "Deck.h"

#include <random>
#include <algorithm>

constexpr int DECK_SIZE = 52;

Deck::Deck(int numberDecks)
{
    for (int j = 0; j < numberDecks; j++)
    {
        for (int i = 0; i <= DECK_SIZE; i++)
        {
            Card * c = new Card{static_cast<Card::Rank>(i % 13), static_cast<Card::Suit>(i % 4)};
            cardSet.push_back(c);
        }
    }
};

void Deck::shuffleCards() {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::shuffle(cardSet.begin(), cardSet.end(), generator);
}

std::vector<Card*> Deck::getCardSet() {
    return cardSet;
}

Card * Deck::getTopCard() {
    Card * c = cardSet.back();
    cardSet.pop_back();
    return c;
}


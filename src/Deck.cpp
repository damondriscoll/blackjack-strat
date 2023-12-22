#include "Deck.h"

#include <algorithm>

constexpr int DECK_SIZE = 52;

Deck::Deck(int n) : nDecks(n)
{
    refill(); // Initial deck population
}

Deck::~Deck() {
    for (Card* card : cardSet) {
        delete card;
    }

    cardSet.clear();
}

void Deck::refill() {

    for (int j = 0; j < nDecks; j++)
    {
        for (int i = 0; i < DECK_SIZE; i++)
        {
            Card * c = new Card{static_cast<Card::Rank>(i % 13), static_cast<Card::Suit>(i % 4)};
            cardSet.push_back(c);
        }
    }
}

void Deck::shuffle() {
    std::default_random_engine generator;
    std::random_device rd;
    generator.seed(rd());
    std::shuffle(cardSet.begin(), cardSet.end(), generator);
}

int Deck::size() {
    return cardSet.size();
}

Card * Deck::getTopCard() {
    if (cardSet.empty()) {
        refill();
        shuffle();
    }

    Card * c = cardSet.back();
    cardSet.pop_back();
    return c;
}


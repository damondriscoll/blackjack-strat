#include "Card.h"

Card::Card(const Card::Rank &r, const Card::Suit &s) : rank{r}, suit{s} {}

Card::Card(const Card & c) : rank{c.rank}, suit{c.suit} {}

Card::Rank Card::getRank() const { return rank; }

Card::Suit Card::getSuit() const { return suit; }
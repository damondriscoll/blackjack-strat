#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
public:
    enum Rank
    {
        ACE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };

    enum Suit
    {
        SPADE,
        HEART,
        CLUB,
        DIAMOND
    };

    friend std::ostream &operator << ( std::ostream& strm, Rank r )
    {
        const std::string rankNames[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
        return strm << rankNames[r];
    };

    friend std::ostream &operator << ( std::ostream& strm, Suit s )
    {
        const std::string suitNames[] = { "Spades", "Hearts", "Clubs", "Diamonds" };
        return strm << suitNames[s];
    };

    Card(const Rank &r, const Suit &s);
    Card(const Card &c);

    Rank getRank() const;
    Suit getSuit() const;

private:
    Rank rank;
    Suit suit;
};

#endif
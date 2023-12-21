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
        const std::string rankNames[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
        return strm << rankNames[r];
    };

    friend std::ostream &operator << ( std::ostream& strm, Suit s )
    {
        const std::string suitNames[] = { "♧", "♡", "♤", "♢" };
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
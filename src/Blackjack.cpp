#include "Blackjack.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string>

Blackjack::Blackjack(int numDecks) : deck(new Deck(numDecks)) {}

Blackjack::~Blackjack() { clearHands(); }

void Blackjack::clearHands() {
    for (std::vector<Card*>& hand : playerHands) {
        for (Card* card : hand) {
            delete card;
        }
        hand.clear();
    }
    playerHands.clear();

    for (Card* card : dealerHand) {
        delete card;
    }
    dealerHand.clear();
}

void Blackjack::fillHands() {
    deck->shuffle();

    std::vector<Card *> newPlayerHand;
    newPlayerHand.push_back(deck->getTopCard());
    dealerHand.push_back(deck->getTopCard());
    newPlayerHand.push_back(deck->getTopCard());
    dealerHand.push_back(deck->getTopCard());
    playerHands.push_back(newPlayerHand);

}

Deck * Blackjack::getDeck() {
    return deck;
}

void Blackjack::hit(int handNum) {
    playerHands[handNum].push_back(deck->getTopCard());
}

bool Blackjack::split(int handNum) {
    if (playerHands[handNum].size() == 2 && playerHands[handNum][0]->getRank() == playerHands[handNum][1]->getRank()) {
        Card * secondCard = playerHands[handNum].back();
        playerHands[handNum].pop_back();
        playerHands[handNum].push_back(deck->getTopCard());

        std::vector<Card *> newHand;
        newHand.push_back(secondCard);
        newHand.push_back(deck->getTopCard());
        playerHands.insert(playerHands.begin() + handNum + 1, newHand);
        return true;
    }
    return false;
}

void Blackjack::hitDealer() {
    dealerHand.push_back(deck->getTopCard());
}

void Blackjack::displayDealerHand(bool hideFirstCard) {
    std::cout << "Dealer: ";
    if (hideFirstCard) {
        displayCard(dealerHand[1]);
        std::cout << "[??] ";
    } else {
        displayHand(dealerHand);
    }
    std::cout << std::endl;
}

void Blackjack::displayPlayerHands() {
    int n = 1;
    for ( auto hand : playerHands ) {
        std::cout << n << ") ";
        displayHand(hand);
        std::cout << std::endl;
        n++;
    }
}

void Blackjack::displayHand(const std::vector<Card *> &hand) {
    for (const auto &card : hand) {
        displayCard(card);
    }
}

void Blackjack::displayCard(const Card *card) {
    std::cout << '[' << card->getRank() << card->getSuit() << "] ";
}


int Blackjack::calculateHandValue(std::vector<Card *> hand)
{
    int value = 0;
    int numAces = 0;

    for (const auto &card : hand) {
        Card::Rank rank = card->getRank();

        if (rank == Card::Rank::ACE) {
            numAces++;
            value += 11;
        } else if (rank == Card::Rank::JACK || rank == Card::Rank::QUEEN || rank == Card::Rank::KING) {
            value += 10;
        } else {
            value += static_cast<int>(rank) + 1;
        }
    }

    while (value > 21 && numAces > 0) {
        value -= 10;
        numAces--;
    }

    return value;
}

int Blackjack::getNumberPlayerHands() {
    return playerHands.size();
}

std::vector<Card*> Blackjack::getDealerHand() {
    return dealerHand;
}

std::vector<std::vector<Card*>> Blackjack::getPlayerHands() {
    return playerHands;
}
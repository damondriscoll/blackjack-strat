#include "Blackjack.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <experimental/iterator>

const auto blackjackValue = 21;

Blackjack::Blackjack() : deck{new Deck{6}}, running{true}, numPlayerHands{0} {
    getDeck()->shuffleCards();
    resetHands();
    while (running) {
        std::cout << "Cards remaining in pile: " << getDeck()->getCardSet().size() << "\n\n";
        std::cout << "Dealer hand: " << dealerHand[0]->getRank() << " of " << dealerHand[0]->getSuit() << ", and a face down card" << std::endl;
        std::string numHand = playerHands.size() > 1 ? " " + std::to_string(playerHands.size()) : "";
        for ( auto ph : playerHands ) {
            std::cout << "Player hand" << numHand << ": ";
            for (auto iter = ph.begin(), end = ph.end(); iter != end; iter++) {
                if (iter != ph.begin()) std::cout << ", ";
                Card * c = *iter;
                std::cout << c->getRank() << " of " << c->getSuit();
            }
            std::cout << "\n\n";
        }
        
        

        std::vector<int> playerHandValues = possibleHandValues(playerHand);
        std::vector<int> dealerHandValues = possibleHandValues(dealerHand);
        bool playerBlackjack = std::count(playerHandValues.begin(), playerHandValues.end(), blackjackValue) > 0 ? true : false;
        bool dealerBlackjack = std::count(dealerHandValues.begin(), dealerHandValues.end(), blackjackValue) > 0 ? true : false;

        std::cout << "Option on player hand" << numHand << "(hit/stand/split) : ";
        std::string userChoice;
        std::cin >> userChoice;

        if ( userChoice == "hit" ) {
            playerHand.push_back(getDeck()->getTopCard());
        } else if ( userChoice == "stand" ) {
            while (dealerHandValues.size() != 0 && *std::max_element(dealerHandValues.begin(), dealerHandValues.end()) < 17) {
                dealerHand.push_back(getDeck()->getTopCard());
                dealerHandValues.clear();
                dealerHandValues = possibleHandValues(dealerHand);
            }
            if ( dealerHandValues.size() == 0 ) {
                std::cout << "Dealer busted." << std::endl;
            } else {
                //compare dealer vs player
            }
        } else if ( userChoice == "split" ) {

        } else {
            std::cout << "\nInvalid option!" << std::endl;
            break;
        }

        system("CLS");
    }
}

Deck * Blackjack::getDeck() {
    return deck;
}

bool Blackjack::inBoundsHand(int c)
{
    if ( c <= blackjackValue ) return true;
    return false;
}

void Blackjack::playAgainCheck() {
    char choice;
    std::cout << "Play again? (Y/N): ";
    std::cin >> choice;
    if ( choice == 'N' ) {
        running = false;
    } else {
        resetHands();
    }
}

void Blackjack::resetHands() {
    playerHands.clear();
    playerHands[0].push_back(getDeck()->getTopCard());
    playerHands[0].push_back(getDeck()->getTopCard());
    dealerHand.clear();
    dealerHand.push_back(getDeck()->getTopCard());
    dealerHand.push_back(getDeck()->getTopCard());
}

std::vector<int> Blackjack::possibleHandValues(std::vector<Card *> currentHand)
{
    std::vector<Card::Rank> currentHandRanks;
    for (auto card : currentHand) {
        currentHandRanks.push_back(card->getRank());
    }
    std::sort(currentHandRanks.begin(), currentHandRanks.end(), std::greater<int>());

    std::vector<int> handValues(1,0);
    for (auto cardRank : currentHandRanks)
    {
        std::vector<int> replaceValues;
        if ( cardRank == 0 ) {
            for ( auto hv : handValues ) {
                if (inBoundsHand(hv + 1)) replaceValues.push_back(hv + 1);
                if (inBoundsHand(hv + 11)) replaceValues.push_back(hv + 11);
            };
        } else {
            if ( cardRank / 10 > 0 ) cardRank = Card::Rank::TEN;
            for ( auto hv : handValues ) {
                if (inBoundsHand(hv + cardRank + 1)) replaceValues.push_back(hv + cardRank + 1);
            };
        }
        std::swap(handValues, replaceValues);   
    }
    return handValues;
}

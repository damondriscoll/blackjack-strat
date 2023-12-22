#include "BlackjackGame.h"
#include <iostream>
#include <algorithm>

constexpr int BLACKJACK_VALUE = 21;

BlackjackGame::BlackjackGame(int numDecks) : blackjack(numDecks), currentHand(1) {}

void BlackjackGame::start() {
    blackjack.fillHands();
}

void BlackjackGame::nextState() {
    std::cout << "--------------" << std::endl;
    blackjack.displayDealerHand(true);
    std::cout << std::endl;
    blackjack.displayPlayerHands();
    std::cout << std::endl << "Options on hand " << currentHand << ": Hit (h), Stand (s), Double Down (d), Split (p): ";

    std::string choice;
    std::cin >> choice;

    if (choice == "h") {
        blackjack.hit(currentHand-1);
        if (blackjack.calculateHandValue(blackjack.getPlayerHands()[currentHand-1]) >= BLACKJACK_VALUE) {
            currentHand++;
        }
    } else if (choice == "s") {
        currentHand++;
    } else if (choice == "d") {
        blackjack.hit(currentHand-1);
        currentHand++;
    } else if (choice == "p") {
        if (!blackjack.split(currentHand-1)) {
            std::cout << "Cannot split this hand." << std::endl;
        }
    } else {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }

    if (currentHand > blackjack.getNumberPlayerHands()) {
        playDealerTurn();
    }
}

void BlackjackGame::playDealerTurn() {
    std::cout << "~~~~~~~~~~~~~~\n";

    while (blackjack.calculateHandValue(blackjack.getDealerHand()) < 17) {
        blackjack.hitDealer();
    }

    int dealerValue = blackjack.calculateHandValue(blackjack.getDealerHand());

    blackjack.displayDealerHand(false);
    std::cout << '\n';

    int numHand = 1;
    for (auto hand : blackjack.getPlayerHands()) {
        std::cout << numHand << ") ";
        blackjack.displayHand(hand);
        std::cout << "// ";
        int playerValue = blackjack.calculateHandValue(hand);
        if (playerValue > BLACKJACK_VALUE) {
            std::cout << "Bust. Dealer wins.\n";
        } else if (dealerValue > BLACKJACK_VALUE) {
            std::cout << "Dealer busts! You win!\n";
        } else if (dealerValue == playerValue) {
            std::cout << "Push.\n";
        } else if (dealerValue > playerValue) {
            std::cout << "Dealer wins.\n";
        } else {
            std::cout << "You win!\n";
        }
        numHand++;
    }

    blackjack.clearHands();
    blackjack.fillHands();
    currentHand = 1;

}
cmake_minimum_required(VERSION 3.5.0)
project(blackjack)

set(SOURCES
    src/Card.cpp
    src/Deck.cpp
    src/Blackjack.cpp
    src/main.cpp
    src/BlackjackGame.cpp
)

set(HEADERS
    src/Card.h
    src/Deck.h
    src/Blackjack.h
    src/BlackjackGame.h
)

add_executable(blackjack ${SOURCES} ${HEADERS})

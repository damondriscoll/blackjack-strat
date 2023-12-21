cmake_minimum_required(VERSION 3.5.0)
project(blackjack)

set(SOURCES
    src/Card.cpp
    src/Deck.cpp
    src/Blackjack.cpp
    src/main.cpp
)

set(HEADERS
    src/Card.h
    src/Deck.h
    src/Blackjack.h
)

add_executable(blackjack ${SOURCES} ${HEADERS})

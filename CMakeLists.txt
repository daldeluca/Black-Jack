cmake_minimum_required(VERSION 3.29)
project(BlackJack)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlackJack main.cpp
        Game.h
        Deck.cpp
        Deck.h
        Hand.cpp
        Hand.h
        Card.cpp
        Card.h
        Game.cpp)

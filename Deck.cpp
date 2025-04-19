#include "Deck.h"
#include <algorithm>
#include <random>
#include <string>
#include <iostream>

Deck::Deck() {
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    vector<string> ranks = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "Jack", "Queen", "King", "Ace"
    };

    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            int value;

            if (rank == "Ace") value = 11;
            else if (rank == "King" || rank == "Queen" || rank == "Jack") value = 10;
            else value = std::stoi(rank); // convert "2"-"10" to int

            m_cardDeck.push_back(Card(suit, rank, value));
        }
    }
}
Card Deck::dealCard() {
    Card Card = m_cardDeck.back();
    m_cardDeck.pop_back();
    return Card;
}
void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_cardDeck.begin(), m_cardDeck.end(), g);
}

int Deck::getCount() const{
    return m_cardDeck.size();
}

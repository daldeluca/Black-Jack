//
// Created by administrator on 4/7/25.
//

#include "Hand.h"
#include <iostream>
#include <vector> // Include vector header
#include <string> // Use string library
using namespace std;

Hand::Hand() {}

void Hand::clearHand() {
    m_hand.clear();
}

void Hand::operator+=(const Card card) {
    m_hand.push_back(card);
}

Card Hand::displayCard(int index) {
    if (index >= 0 && index < m_hand.size()) {
        cout << m_hand[index].getCard() << endl;
        return m_hand[index]; // Added return statement
    }
    throw out_of_range("Invalid index"); // Added error handling
}

int Hand::getPoints() {
    int total = 0;
    int aceCount = 0;
    for (auto& card : m_hand) {
        total += card.getValue();
        if (card.getRank() == "A") aceCount++;
    }
    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }
    return total;
}

int Hand::cardCount() const {
    return m_hand.size();
}





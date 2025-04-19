//
// Created by administrator on 4/7/25.
//

#ifndef HAND_H
#define HAND_H
#include <vector>

#include "Card.h"
using namespace std;

class Hand {
private:
vector<Card> m_hand;
    public:
    Hand();
    void clearHand();
    void operator+=(Card);
    Card displayCard(int index);
    int getPoints();
    int cardCount() const;
};



#endif //HAND_H

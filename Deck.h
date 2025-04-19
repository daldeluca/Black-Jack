
#ifndef DECK_H
#define DECK_H
#include <vector>
using namespace std;
#include "Card.h"


class Deck {
private:
    vector<Card> m_cardDeck;
    public:
    Deck();
    Card dealCard();
    int getCount() const;
    void shuffleDeck();



};



#endif //DECK_H

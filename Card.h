//
// Created by administrator on 4/7/25.
//

#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;


class Card {
private:
    string m_suit;
    string m_rank;
    int m_value;
public:
    Card();
    Card(string suit, string rank, int value);
    string getRank();
    int getValue();
    string getCard() const;
};



#endif //CARD_H


#include "Card.h"
using namespace std;

Card::Card() {
    m_suit = "";
    m_rank = "";
    m_value = 0;
}
Card::Card(string suit, string rank, int value) {
    m_suit = suit;
    m_rank = rank;
    m_value = value;
}
string Card::getRank() {
    return m_rank;
}
int Card::getValue() {
    return m_value;
}
string Card::getCard() const{
    return m_rank + " of " + m_suit;
}
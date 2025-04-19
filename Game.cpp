//
// Created by administrator on 4/7/25.
//
#include "Game.h"
#include "Hand.h"
#include <iostream>
#include <limits>
using namespace std;

Game::Game() {
    m_deck.shuffleDeck();
}

Hand Game::getPlayerHand(Deck& deck, Hand& hand) {
    hand.clearHand();
    hand += deck.dealCard();
    hand += deck.dealCard();
    return hand;
}

Hand Game::getDealerHand(Deck& deck, Hand& hand) {
    hand.clearHand();
    hand += deck.dealCard();
    hand += deck.dealCard();
    return hand;
}

void Game::displayCards(Hand h, string who) {

    for (int i = 0; i < h.cardCount(); ++i) {
        h.displayCard(i);
    }
    cout << endl;
}

void Game::displayRound() {
    m_playerHand.clearHand();
    m_dealerHand.clearHand();
    m_playerHand = getPlayerHand(m_deck, m_playerHand);
    m_dealerHand = getDealerHand(m_deck, m_dealerHand);

    cout << "Dealer's Show Card: \n";
    m_dealerHand.displayCard(0).getCard();
    cout << "\n\n";

    cout << "Your Cards: \n";
    displayCards(m_playerHand, "");

    // Player turn
    char choice;
    while (m_playerHand.getPoints() < 21) {
        cout << "hit or stand? (h/s): ";
        cin >> choice;

        if (choice == 'h') {
            m_playerHand += m_deck.dealCard();
            cout << "\nYour Cards: \n";
            displayCards(m_playerHand, "");
        } else if (choice == 's') {
            break;
        } else {
            cout << "Invalid input. Please enter 'h' or 's'.\n";
        }
    }

    int playerPoints = m_playerHand.getPoints();
    if (playerPoints > 21) {
        cout << "Dealer's Cards: \n";
        displayCards(m_dealerHand, "");
        cout << "Your Points:     " << playerPoints << endl;
        cout << "Dealer's Points: " << m_dealerHand.getPoints() << endl;
        cout << "Sorry. You busted. You lose.\n";
        return;
    }

    // Dealer plays
    while (m_dealerHand.getPoints() < 17) {
        m_dealerHand += m_deck.dealCard();
    }

    int dealerPoints = m_dealerHand.getPoints();

    cout << "Dealer's Cards: \n";
    displayCards(m_dealerHand, "");

    cout << "Your Points:     " << playerPoints << endl;
    cout << "Dealer's Points: " << dealerPoints << endl;

    // Results
    if (dealerPoints > 21) {
        cout << "Yay! The dealer busted. You win!\n";
    } else if (playerPoints == 21 && m_playerHand.cardCount() == 2 &&
               !(dealerPoints == 21 && m_dealerHand.cardCount() == 2)) {
        cout << "Blackjack! You win!\n";
    } else if (dealerPoints == 21 && m_dealerHand.cardCount() == 2 &&
               !(playerPoints == 21 && m_playerHand.cardCount() == 2)) {
        cout << "Dealer has Blackjack. You lose.\n";
    } else if (playerPoints == dealerPoints) {
        cout << "It's a tie! You push.\n";
    } else if (playerPoints > dealerPoints) {
        cout << "Hooray! You win!\n";
    } else {
        cout << "Sorry. You lose.\n";
    }
}

void Game::playGame() {
    cout << "###########################\n";
    cout << "#  The Game of Blackjack  #\n";
    cout << "###########################\n\n";
    char again;
    do {
        if (m_deck.getCount() < 10) {
            cout << "\nShuffling a new deck...\n";
            m_deck = Deck();
            m_deck.shuffleDeck();
        }

        displayRound();

        cout << "\nplay another round? (y/n): ";
        cin >> again;
        cout << endl;

    } while (again == 'y' || again == 'Y');

    cout << "Thanks for playing!\n";
}

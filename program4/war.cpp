#include "war.h"

War::War() {
    createDecks();
    shuffleDecks();
    dealCards();
}

void War::play() {
    int round = 1;
    while (!playerDeck.empty() && !computerDeck.empty()) {
        cout << "Round " << round << ":\n";
        war();
        round++;

        if (playerDeck.size() >= 52 || computerDeck.size() <= 10) {
            cout << "Player wins!" << endl;
            break;
        }

        if (computerDeck.size() >= 52 || playerDeck.size() <= 10) {
            cout << "Computer wins!" << endl;
            break;
        }
        
        if (playerDeck.size() < 10) {
            cout << "Computer wins! Player doesn't have enough cards." << endl;
            break;
        }
        
        if (computerDeck.size() < 10) {
            cout << "Player wins! Computer doesn't have enough cards." << endl;
            break;
        }
    }
}


void War::createDecks() {
    for (int i = 1; i <= 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            deck.push_back(Card(i, suits[j]));
        }
    }
}

void War::shuffleDecks() {
    srand(time(0));
    random_shuffle(deck.begin(), deck.end());
}

void War::dealCards() {
    for (int i = 0; i < deck.size(); ++i) {
        if (i % 2 == 0) {
            playerDeck.push_back(deck[i]);
        } else {
            computerDeck.push_back(deck[i]);
        }
    }
}

void War::war() {
    if (playerDeck.empty() || computerDeck.empty()) return;

    Card playerCard = playerDeck.front();
    Card computerCard = computerDeck.front();

    playerDeck.erase(playerDeck.begin());
    computerDeck.erase(computerDeck.begin());

    playerHold.push_back(playerCard);
    computerHold.push_back(computerCard);

    cout << "Player card: " << playerCard.toString() << endl;
    cout << "Computer card: " << computerCard.toString() << endl;

    if (playerCard.getValue() > computerCard.getValue()) {
        cout << "Player wins this round" << endl;
        playerDeck.insert(playerDeck.end(), playerHold.begin(), playerHold.end());
        playerDeck.insert(playerDeck.end(), computerHold.begin(), computerHold.end());
    } else if (computerCard.getValue() > playerCard.getValue()) {
        cout << "Computer wins this round" << endl;
        computerDeck.insert(computerDeck.end(), playerHold.begin(), playerHold.end());
        computerDeck.insert(computerDeck.end(), computerHold.begin(), computerHold.end());
    } else {
        cout << "War initiated!" << endl;
        if (playerDeck.size() >= 3 && computerDeck.size() >= 3) {
            for (int i = 0; i < 3; ++i) {
                playerHold.push_back(playerDeck.front());
                playerDeck.erase(playerDeck.begin());

                computerHold.push_back(computerDeck.front());
                computerDeck.erase(computerDeck.begin());
            }
        } else if (playerDeck.size() < 3) {
            cout << "Player doesn't have enough cards to initiate war. Computer wins!" << endl;
            return;
        } else if (computerDeck.size() < 3) {
            cout << "Computer doesn't have enough cards to initiate war. Player wins!" << endl;
            return;
        }
        war();
    }

    playerHold.clear();
    computerHold.clear();
    cout << "Player deck count: " << playerDeck.size() << endl;
    cout << "Computer deck count: " << computerDeck.size() << endl;
    cout << "----------" << endl;
}


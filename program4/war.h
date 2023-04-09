#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

#include "card.h"

using namespace std;

class War {
public:
    War();
    void play();

private:
    vector<Card> playerDeck;
    vector<Card> computerDeck;
    vector<Card> playerHold;
    vector<Card> computerHold;
    vector<Card> deck;
    char suits[4] = {'C', 'D', 'H', 'S'};

    void createDecks();
    void shuffleDecks();
    void dealCards();
    void war();
};

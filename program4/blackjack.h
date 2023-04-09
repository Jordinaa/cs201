#pragma once

#include "card.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

class Blackjack {
public:
    void play();
private:
    vector<Card> createDeck();
    int getCardValue(const Card& card, int handTotal);
    string displayCard(const Card& card);
    int playHand(vector<Card>& deck, bool isPlayer);
};

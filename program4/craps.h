#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Craps {
public:
    Craps();
    void play();
private:
    int rollDice();
    int getBet();
    int getValidBet(int maxBet, int playerWorth);
    bool playRound(int point);
    int playerWorth = 50;
};

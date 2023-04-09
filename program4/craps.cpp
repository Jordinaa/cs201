#include "craps.h"

Craps::Craps() {
    srand(time(0));
}

void Craps::play() {
    while (playerWorth > 0) {
        cout << "You have $" << playerWorth << " remaining." << endl;
        int bet = getBet();
        int roll = rollDice();
        if (roll == 7 || roll == 11) {
            cout << "You win!" << endl;
            playerWorth += bet;
        } else if (roll == 2 || roll == 3 || roll == 12) {
            cout << "You lose!" << endl;
            playerWorth -= bet;
        } else {
            cout << "The point is " << roll << "." << endl;
            bool win = playRound(roll);
            if (win) {
                cout << "You win!" << endl;
                playerWorth += bet;
            } else {
                cout << "You lose!" << endl;
                playerWorth -= bet;
            }
        }
    }
    cout << "Game over! You ran out of money." << endl;
    cout << "Your final worth is $" << playerWorth << "." << endl;
}

int Craps::rollDice() {
    int die1 = rand() % 6 + 1;
    int die2 = rand() % 6 + 1;
    int sum = die1 + die2;
    cout << "Roll: " << die1 << " + " << die2 << " = " << sum << endl;
    return sum;
}

int Craps::getBet() {
    int maxBet = min(playerWorth, 50);
    cout << "Place your bet (max $" << maxBet << "): ";
    int bet;
    cin >> bet;
    bet = getValidBet(maxBet, bet);
    return bet;
}

int Craps::getValidBet(int maxBet, int playerBet) {
    while (playerBet < 1 || playerBet > maxBet) {
        cout << "Invalid bet. Place your bet (max $" << maxBet << "): ";
        cin >> playerBet;
    }
    return playerBet;
}

bool Craps::playRound(int point) {
    int roll = rollDice();
    while (roll != point && roll != 7) {
        roll = rollDice();
    }
    return (roll == point);
}

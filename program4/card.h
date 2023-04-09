#pragma once

#include <string>

using namespace std;

class Card {
public:
    Card(int value, char suit);
    int getValue() const;
    char getSuit() const;
    string toString() const;

private:
    int value;
    char suit;
};

#include "card.h"

Card::Card(int value, char suit) : value(value), suit(suit) {}

int Card::getValue() const {
    return value;
}

char Card::getSuit() const {
    return suit;
}

string Card::toString() const {
    string cardString;
    switch (value) {
        case 1:
            cardString = "A";
            break;
        case 11:
            cardString = "J";
            break;
        case 12:
            cardString = "Q";
            break;
        case 13:
            cardString = "K";
            break;
        default:
            cardString = to_string(value);
    }
    string color;
    string suitSymbol;
    switch (suit) {
        case 'H':
            color = "\033[31m";
            suitSymbol = "\xE2\x99\xA5"; // Heart
            break;
        case 'D':
            color = "\033[31m";
            suitSymbol = "\xE2\x99\xA6"; // Diamond
            break;
        case 'C':
            color = "\033[30m";
            suitSymbol = "\xE2\x99\xA3"; // Club
            break;
        case 'S':
            color = "\033[30m";
            suitSymbol = "\xE2\x99\xA0"; // Spade
            break;
        default:
            color = "\033[37m";
            suitSymbol = "?";
    }
    return color + std::to_string(value) + suitSymbol + "\033[0m";
}


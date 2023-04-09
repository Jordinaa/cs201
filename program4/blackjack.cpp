#include "blackjack.h"
#include "card.h"

using namespace std;

void Blackjack::play() {
    srand(time(0));
    char playAgain;

    do {
        vector<Card> deck = createDeck();
        int playerTotal = playHand(deck, true);
        int dealerTotal = playHand(deck, false);

        cout << "Player total: " << playerTotal << "\n";
        cout << "Dealer total: " << dealerTotal << "\n";

        if (playerTotal > 21) {
            cout << "Player busts! Dealer wins.\n";
        } else if (dealerTotal > 21) {
            cout << "Dealer busts! Player wins.\n";
        } else if (playerTotal > dealerTotal) {
            cout << "Player wins!\n";
        } else if (dealerTotal > playerTotal) {
            cout << "Dealer wins!\n";
        } else {
            cout << "It's a push!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}

vector<Card> Blackjack::createDeck() {
    vector<Card> deck;
    for (int i = 1; i <= 13; ++i) {
        deck.push_back(Card(i, 'C'));
        deck.push_back(Card(i, 'D'));
        deck.push_back(Card(i, 'H'));
        deck.push_back(Card(i, 'S'));
    }
    random_shuffle(deck.begin(), deck.end());
    return deck;
}

int Blackjack::getCardValue(const Card& card, int handTotal) {
    int value = card.getValue();
    if (value > 10) {
        value = 10;
    } else if (value == 1 && handTotal + 11 <= 21) {
        value = 11;
    }
    return value;
}

string Blackjack::displayCard(const Card& card) {
    return card.toString();
}


int Blackjack::playHand(vector<Card>& deck, bool isPlayer) {
    vector<Card> hand = {deck.back()};
    deck.pop_back();
    hand.push_back(deck.back());
    deck.pop_back();

    int total = getCardValue(hand[0], 0) + getCardValue(hand[1], getCardValue(hand[0], 0));

    if (isPlayer) {
        cout << "Your hand: ";
        cout << displayCard(hand[0]) << " ";
        cout << displayCard(hand[1]) << " ";
        cout << " (Total: " << total << ")\n";

        char choice;
        do {
            cout << "Do you want to hit? (y/n): ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                hand.push_back(deck.back());
                deck.pop_back();
                total += getCardValue(hand.back(), total);
                cout << "Your hand: ";
                for (const Card& card : hand) {
                    cout << displayCard(card) << " ";
                }
                cout << " (Total: " << total << ")\n";
            }

        } while ((choice == 'y' || choice == 'Y') && total <= 21);
    } else {
        while (total <= 17) {
            hand.push_back(deck.back());
            deck.pop_back();
            total += getCardValue(hand.back(), total);
        }
    }

    return total;
}

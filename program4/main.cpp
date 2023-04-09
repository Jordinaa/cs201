#include "blackjack.h"
#include "craps.h"
#include "hangman.h"
#include "tictactoe.h"
#include "war.h"

using namespace std;

int main() {
    char choice;

    cout << "Games List" << endl;
    cout << "B - Blackjack" << endl;
    cout << "C - Craps" << endl;
    cout << "H - Hangman" << endl;
    cout << "T - TicTacToe" << endl;
    cout << "W - War" << endl;
    cout << "Q - Quit" << endl;

    while (true) {
        cout << "What game would you like to play? ";
        cin >> choice;

        switch (choice) {
            case 'B': {
                Blackjack blackjackGame;
                blackjackGame.play();
                break;
            }
            case 'C': {
                Craps crapsGame;
                crapsGame.play();
                break;
            }
            case 'H': {
                Hangman game("words.txt");
                game.play();
                break;
            }
            case 'T': {
                TicTacToe ticTacToeGame;
                ticTacToeGame.play();
                break;
            }
            case 'W': {
                War warGame;
                warGame.play();
                break;
            }
            case 'Q':
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid selection. Please try again." << endl;
        }
    }

    return 0;
}

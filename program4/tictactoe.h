#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class TicTacToe {
public:
    TicTacToe();
    void play();

private:
    enum Player { HUMAN, COMPUTER };
    std::vector<char> board;

    void displayBoard();
    void humanMove();
    void computerMove();
    bool checkWin(char playerSymbol);
    bool isBoardFull();
    int machineRule1();
    int machineRule2();
    int machineRule3();
    int machineRule4();
    int machineRule5();
};

#include "tictactoe.h"

TicTacToe::TicTacToe() : board(9) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 9; ++i) {
        board[i] = '1' + i;
    }
}


void TicTacToe::displayBoard() {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0) {
            cout << endl;
        }
        cout << board[i] << " ";
    }
    cout << endl;
}


void TicTacToe::humanMove() {
    int position;
    do {
        cout << "What position does the human choose? (1-9): ";
        cin >> position;
        --position;
    } while (position < 0 || position >= 9 || (board[position] != '1' + position));
    board[position] = 'X';
}


void TicTacToe::computerMove() {
    int position = -1;

    if ((position = machineRule1()) != -1 ||
        (position = machineRule2()) != -1 ||
        (position = machineRule3()) != -1 ||
        (position = machineRule4()) != -1 ||
        (position = machineRule5()) != -1) {
        board[position] = 'O';
    }
}


bool TicTacToe::checkWin(char playerSymbol) {
    const int WINNING_COMBINATIONS[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
        {0, 4, 8}, {2, 4, 6}            // diagonals
    };

    for (int i = 0; i < 8; ++i) {
        if (board[WINNING_COMBINATIONS[i][0]] == playerSymbol &&
            board[WINNING_COMBINATIONS[i][1]] == playerSymbol &&
            board[WINNING_COMBINATIONS[i][2]] == playerSymbol) {
            return true;
        }
    }

    return false;
}

bool TicTacToe::isBoardFull() {
    for (const char &cell : board) {
        if (cell >= '1' && cell <= '9') {
            return false;
        }
    }
    return true;
}

int TicTacToe::machineRule1() {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == '1' + i) {
            board[i] = 'O';
            if (checkWin('O')) {
                return i;
            }
            board[i] = 'X';
            if (checkWin('X')) {
                board[i] = 'O';
                return i;
            }
            board[i] = '1' + i;
        }
    }
    return -1;
}

int TicTacToe::machineRule2() {
    if (board[4] == '-') {
        return 4;
    }
    return -1;
}

int TicTacToe::machineRule3() {
    const int CORNERS[4] = {0, 2, 6, 8};
    for (int i = 0; i < 4; ++i) {
        int opposite_corner = 8 - CORNERS[i];
        if (board[CORNERS[i]] == 'X' && board[opposite_corner] == '1' + opposite_corner) {
            return opposite_corner;
        }
    }
    return -1;
}

int TicTacToe::machineRule4() {
    const int CORNERS[4] = {0, 2, 6, 8};
    for (int i = 0; i < 4; ++i) {
        if (board[CORNERS[i]] == '-') {
            return CORNERS[i];
        }
    }
    return -1;
}

int TicTacToe::machineRule5() {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == '-') {
            return i;
        }
    }
    return -1;
}

void TicTacToe::play() {
    Player currentPlayer = (rand() % 2 == 0) ? HUMAN : COMPUTER;
    cout << (currentPlayer == HUMAN ? "Human" : "Computer") << " goes first." << endl;

    displayBoard();

    if (currentPlayer == COMPUTER) {
        computerMove();
    }

    while (!isBoardFull() && !checkWin('X') && !checkWin('O')) {
        if (currentPlayer == HUMAN) {
            humanMove();
            currentPlayer = COMPUTER;
        } else {
            computerMove();
            currentPlayer = HUMAN;
            displayBoard();
        }
    }

    if (checkWin('X')) {
        cout << "Human wins!" << endl;
    } else if (checkWin('O')) {
        cout << "Computer wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}



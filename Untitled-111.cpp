
#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void drawBoard() {
    cout << "-------------\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "| ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin() {
    for (int i = 0; i < SIZE; ++i) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove() {
    int move;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;
    move--; // Adjust for 0-indexed array

    int row = move / SIZE;
    int col = move % SIZE;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
    } else {
        cout << "Invalid move, try again.\n";
        makeMove();
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe!\n";
    drawBoard();

    while (true) {
        makeMove();
        drawBoard();

        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (checkDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}

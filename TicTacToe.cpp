#include <iostream>
using namespace std;

// Function prototypes
void printBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool isFull(char board[3][3]);

int main() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char currentPlayer = 'X';
    int choice;
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";
    printBoard(board);

    while (!gameOver) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> choice;

        // Map choice to board indices
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check if the move is valid
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;
        printBoard(board);

        // Check for a winner
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (isFull(board)) {
            cout << "It's a draw!\n";
            gameOver = true;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Thanks for playing!\n";
    return 0;
}

void printBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

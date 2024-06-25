#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<char> &board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}

bool isWin(const vector<char> &board, char player) {
    const vector<vector<int>> winPatterns = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
        {0, 4, 8}, {2, 4, 6}             // diagonals
    };

    for (const auto &pattern : winPatterns) {
        if (board[pattern[0]] == player &&
            board[pattern[1]] == player &&
            board[pattern[2]] == player) {
            return true;
        }
    }
    return false;
}

bool isDraw(const vector<char> &board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true;
}

void switchPlayer(char &player) {
    player = (player == 'X') ? 'O' : 'X';
}

void playGame() {
    vector<char> board(9);
    for (int i = 0; i < 9; ++i) {
        board[i] = '1' + i;
    }

    char currentPlayer = 'X';
    bool gameEnded = false;

    while (!gameEnded) {
        displayBoard(board);
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move - 1] = currentPlayer;

        if (isWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameEnded = true;
        } else if (isDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw!\n";
            gameEnded = true;
        } else {
            switchPlayer(currentPlayer);
        }
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Thanks for playing!\n";
    return 0;
}

#include <iostream>
#include <vector>

// Renders the current state of the 3x3 game board
void drawBoard(const std::vector<char>& board) {
    std::cout << "\n";
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
    std::cout << "\n";
}

// Scans predefined grid matching sequences to determine a victor
bool checkWin(const std::vector<char>& board, char player) {
    const int winConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };
    for (int i = 0; i < 8; ++i) {
        if (board[winConditions[i][0]] == player &&
            board[winConditions[i][1]] == player &&
            board[winConditions[i][2]] == player) {
            return true;
        }
    }
    return false;
}

// Verifies if all slots are filled without any winner
bool checkDraw(const std::vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = 'X';
    bool gameRunning = true;

    std::cout << "=== Command-Line Tic-Tac-Toe ===\n";

    while (gameRunning) {
        drawBoard(board);
        int choice;
        std::cout << "Player " << currentPlayer << ", enter a position (1-9): ";
        std::cin >> choice;

        // Validates input range and prevents overwriting existing placements
        if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            std::cout << "Invalid move! Try again.\n";
            continue;
        }

        board[choice - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            std::cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            gameRunning = false;
        } else if (checkDraw(board)) {
            drawBoard(board);
            std::cout << "It's a draw!\n";
            gameRunning = false;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Toggles turns
        }
    }
    return 0;
}

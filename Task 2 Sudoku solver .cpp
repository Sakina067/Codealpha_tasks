#include <iostream>
#include <vector>

using namespace std;

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            cout << "---------------------" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << "|" << endl;
        if (i % 3 == 2) {
            cout << "---------------------" << endl;
        }
    }
}

// Function to find an empty cell
pair<int, int> findEmptyCell(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // No empty cell found
}

// Function to check if a number is valid in a cell
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 box
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;
    for (int i = boxRowStart; i < boxRowStart + 3; i++) {
        for (int j = boxColStart; j < boxColStart + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Recursive function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<int>>& board) {
    pair<int, int> emptyCell = findEmptyCell(board);
    int row = emptyCell.first;
    int col = emptyCell.second;

    if (row == -1) {
        return true; // Puzzle is solved
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board)) {
                return true; // Solution found
            } else {
                board[row][col] = 0; // Backtrack
            }
        }
    }

    return false; // No solution found
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Sudoku Puzzle:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "\nSudoku Solution:" << endl;
        printBoard(board);
    } else {
        cout << "\nNo solution exists." << endl;
    }

    return 0;
}

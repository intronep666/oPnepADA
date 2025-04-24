#include <iostream>
#include <cmath>
using namespace std;

int totalQueens;
int board[100];

// Function to check if the queen can be safely placed at (row, col)
bool isSafe(int currentRow, int column) {
    for (int prevRow = 1; prevRow < currentRow; prevRow++) {
        if (board[prevRow] == column || abs(board[prevRow] - column) == abs(prevRow - currentRow)) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve N-Queens problem
void solveNQueens(int row) {
    for (int col = 1; col <= totalQueens; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (row == totalQueens) {
                for (int i = 1; i <= totalQueens; i++) {
                    cout << board[i] << " ";
                }
                cout << endl;
            } else {
                solveNQueens(row + 1);
            }
        }
    }
}

int main() {
    cout << "Enter the number of queens: ";
    cin >> totalQueens;
    solveNQueens(1);
    return 0;
}

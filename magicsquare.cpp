#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to construct an odd-order magic square
void generateMagicSquare(vector<vector<int>>& grid, int size) {
    int row = 0, col = size / 2;

    for (int num = 1; num <= size * size; num++) {
        grid[row][col] = num;

        int nextRow = (row - 1 + size) % size;
        int nextCol = (col + 1) % size;

        // If cell is already filled, move down from current row
        if (grid[nextRow][nextCol] != 0) {
            row = (row + 1) % size;
        } else {
            row = nextRow;
            col = nextCol;
        }
    }
}

int main() {
    int order;
    cout << "Enter an odd number for the order of the magic square: ";
    cin >> order;

    if (order % 2 == 0) {
        cout << "Only odd-sized magic squares are supported.\n";
        return 0;
    }

    vector<vector<int>> matrix(order, vector<int>(order, 0));
    generateMagicSquare(matrix, order);

    cout << "\nGenerated Magic Square of size " << order << ":\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << setw(4) << value;
        }
        cout << '\n';
    }

    return 0;
}

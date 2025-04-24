#include <bits/stdc++.h>
using namespace std;

// Helper function to identify row index with max value in a column
int getMaxRowInColumn(const vector<vector<int>>& matrix, int col) {
    int maxVal = INT_MIN;
    int rowIndex = -1;

    for (int row = 0; row < matrix.size(); row++) {
        if (matrix[row][col] > maxVal) {
            maxVal = matrix[row][col];
            rowIndex = row;
        }
    }
    return rowIndex;
}

// Function to find a peak element in 2D matrix
pair<int, int> locatePeakElement(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    int left = 0, right = cols - 1;

    while (left <= right) {
        int midCol = left + (right - left) / 2;
        int maxRow = getMaxRowInColumn(grid, midCol);

        bool leftCheck = (midCol == 0 || grid[maxRow][midCol] > grid[maxRow][midCol - 1]);
        bool rightCheck = (midCol == cols - 1 || grid[maxRow][midCol] > grid[maxRow][midCol + 1]);

        if (leftCheck && rightCheck) {
            return {maxRow, midCol};
        }

        if (midCol > 0 && grid[maxRow][midCol - 1] > grid[maxRow][midCol]) {
            right = midCol - 1;
        } else {
            left = midCol + 1;
        }
    }

    return {-1, -1}; // No peak found
}

int main() {
    vector<vector<int>> matrix = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    pair<int, int> peak = locatePeakElement(matrix);
    if (peak.first != -1)
        cout << "Peak element found: " << matrix[peak.first][peak.second] << endl;
    else
        cout << "No peak element found." << endl;

    return 0;
}

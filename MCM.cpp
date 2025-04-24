#include <bits/stdc++.h>
using namespace std;

// Function to display the optimal order of matrix multiplication
void displayOrder(const vector<vector<int>> &split, int start, int end) {
    if (start == end) {
        cout << "M" << start + 1;
    } else {
        cout << "(";
        displayOrder(split, start, split[start][end]);
        displayOrder(split, split[start][end] + 1, end);
        cout << ")";
    }
}

// Function to compute the minimum multiplication cost
void optimalMatrixChain(const vector<int> &dims) {
    int matrices = dims.size() - 1;
    vector<vector<int>> cost(matrices, vector<int>(matrices, 0));
    vector<vector<int>> splitIndex(matrices, vector<int>(matrices, 0));

    // l is the chain length
    for (int len = 2; len <= matrices; ++len) {
        for (int i = 0; i <= matrices - len; ++i) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                int currCost = cost[i][k] + cost[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (currCost < cost[i][j]) {
                    cost[i][j] = currCost;
                    splitIndex[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of scalar multiplications: " << cost[0][matrices - 1] << endl;
    cout << "Optimal parenthesization: ";
    displayOrder(splitIndex, 0, matrices - 1);
    cout << endl;
}

int main() {
    vector<int> dimensions = {5, 10, 15, 20, 25, 30};
    optimalMatrixChain(dimensions);
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

const int INF = -1; // Representing "no direct path"

void shortestPaths(vector<vector<int>>& matrix, int size) {
    // Apply Floyd-Warshall Algorithm
    for (int via = 0; via < size; ++via) {
        for (int src = 0; src < size; ++src) {
            for (int dest = 0; dest < size; ++dest) {
                if (matrix[src][via] != INF && matrix[via][dest] != INF) {
                    int newDist = matrix[src][via] + matrix[via][dest];
                    if (matrix[src][dest] == INF || newDist < matrix[src][dest]) {
                        matrix[src][dest] = newDist;
                    }
                }
            }
        }
    }
}

int main() {
    int nodes = 4;

    vector<vector<int>> costMatrix = {
        {0, 9, -4, -1},
        {6, 0, -1, 2},
        {-1, 5, 0, -1},
        {-1, -1, 1, 0}
    };

    shortestPaths(costMatrix, nodes);

    cout << "All-Pairs Shortest Path Matrix:\n";
    for (const auto& row : costMatrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << "\n";
    }

    return 0;
}

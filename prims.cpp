#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void primsNear(int n, vector<vector<int>> &cost) {
    vector<int> near(n, INT_MAX);  // Near array
    vector<pair<int, int>> MST;    // Store MST edges
    int minCost = 0;

    // Step 1: Find the first minimum cost edge
    int u = -1, v = -1, minEdge = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] < minEdge) {
                minEdge = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    MST.push_back({u, v});
    minCost += minEdge;
    
    // Step 2: Initialize Near Array
    for (int i = 0; i < n; i++) {
        if (cost[i][u] < cost[i][v]) {
            near[i] = u;
        } else {
            near[i] = v;
        }
    }
    near[u] = near[v] = -1; // Mark included vertices

    // Step 3: Add remaining n-2 edges
    for (int i = 1; i < n - 1; i++) {
        int next = -1, minVal = INT_MAX;

        // Find the next minimum cost edge
        for (int j = 0; j < n; j++) {
            if (near[j] != -1 && cost[j][near[j]] < minVal) {
                minVal = cost[j][near[j]];
                next = j;
            }
        }

        MST.push_back({next, near[next]});
        minCost += cost[next][near[next]];
        near[next] = -1; // Mark included vertex

        // Update Near Array
        for (int j = 0; j < n; j++) {
            if (near[j] != -1 && cost[j][next] < cost[j][near[j]]) {
                near[j] = next;
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree (MST):\n";
    for (int i = 0; i < MST.size(); i++) {
        cout << MST[i].first << " - " << MST[i].second << "\n";
    }
    cout << "Total Minimum Cost: " << minCost << endl;
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<int>> cost = {
        {INT_MAX, 2, INT_MAX, 6, INT_MAX},
        {2, INT_MAX, 3, 8, 5},
        {INT_MAX, 3, INT_MAX, INT_MAX, 7},
        {6, 8, INT_MAX, INT_MAX, 9},
        {INT_MAX, 5, 7, 9, INT_MAX}
    };

    primsNear(n, cost);
    return 0;
}

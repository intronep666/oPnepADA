#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void primUsingNearArray(int vertices, vector<vector<int>> &graph) {
    vector<int> nearest(vertices, numeric_limits<int>::max());  // Array to track nearest selected vertex
    vector<pair<int, int>> mstEdges;  // Stores edges in the MST
    int totalCost = 0;

    // Step 1: Identify the smallest edge to start the MST
    int start = -1, end = -1, smallestEdge = numeric_limits<int>::max();
    for (int i = 0; i < vertices; i++) {
        for (int j = i + 1; j < vertices; j++) {
            if (graph[i][j] < smallestEdge) {
                smallestEdge = graph[i][j];
                start = i;
                end = j;
            }
        }
    }

    mstEdges.emplace_back(start, end);
    totalCost += smallestEdge;

    // Step 2: Initialize nearest array
    for (int i = 0; i < vertices; i++) {
        if (graph[i][start] < graph[i][end])
            nearest[i] = start;
        else
            nearest[i] = end;
    }

    nearest[start] = nearest[end] = -1;  // Mark start and end as added to MST

    // Step 3: Add remaining edges to MST
    for (int count = 1; count < vertices - 1; count++) {
        int nextVertex = -1, minConnection = numeric_limits<int>::max();

        // Find the next closest vertex to the MST
        for (int i = 0; i < vertices; i++) {
            if (nearest[i] != -1 && graph[i][nearest[i]] < minConnection) {
                minConnection = graph[i][nearest[i]];
                nextVertex = i;
            }
        }

        mstEdges.emplace_back(nextVertex, nearest[nextVertex]);
        totalCost += graph[nextVertex][nearest[nextVertex]];
        nearest[nextVertex] = -1;

        // Update nearest array based on newly added vertex
        for (int i = 0; i < vertices; i++) {
            if (nearest[i] != -1 && graph[i][nextVertex] < graph[i][nearest[i]]) {
                nearest[i] = nextVertex;
            }
        }
    }

    // Output MST and its total cost
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto &edge : mstEdges) {
        cout << edge.first << " - " << edge.second << '\n';
    }
    cout << "Total Cost of MST: " << totalCost << '\n';
}

int main() {
    int numVertices = 5;
    vector<vector<int>> adjacencyMatrix = {
        {numeric_limits<int>::max(), 2, numeric_limits<int>::max(), 6, numeric_limits<int>::max()},
        {2, numeric_limits<int>::max(), 3, 8, 5},
        {numeric_limits<int>::max(), 3, numeric_limits<int>::max(), numeric_limits<int>::max(), 7},
        {6, 8, numeric_limits<int>::max(), numeric_limits<int>::max(), 9},
        {numeric_limits<int>::max(), 5, 7, 9, numeric_limits<int>::max()}
    };

    primUsingNearArray(numVertices, adjacencyMatrix);

    return 0;
}

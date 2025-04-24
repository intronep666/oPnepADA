#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Function to estimate the number of stages from source to destination
int getStageCount(vector<vector<int>>& adjMatrix) {
    int stage = 1;
    int current = 0;

    for (int next = current + 1; next < adjMatrix.size(); ++next) {
        if (adjMatrix[current][next] != INF) {
            current = next;
            stage++;
        }
    }

    return stage;
}

// Function to calculate shortest path using dynamic programming in multi-stage graph
void shortestPathMultiStage(vector<vector<int>>& graph, int stages) {
    int nodes = graph.size();
    vector<int> cost(nodes, INF); // cost[i]: min cost to reach final node from i
    vector<int> nextNode(nodes, -1); // nextNode[i]: best next step from i in the path

    cost[nodes - 1] = 0; // Final node has zero cost to itself

    // Bottom-up computation of cost[] and nextNode[]
    for (int i = nodes - 2; i >= 0; --i) {
        for (int j = i + 1; j < nodes; ++j) {
            if (graph[i][j] != INF && graph[i][j] != 0) {
                int potentialCost = graph[i][j] + cost[j];
                if (potentialCost < cost[i]) {
                    cost[i] = potentialCost;
                    nextNode[i] = j;
                }
            }
        }
    }

    // Constructing the path using nextNode[]
    vector<int> path(stages);
    path[0] = 1;           // 1-based indexing
    path[stages - 1] = nodes;

    for (int i = 1; i < stages - 1; ++i) {
        path[i] = nextNode[path[i - 1] - 1] + 1; // Convert from 0-based to 1-based
    }

    // Output the path and cost
    cout << "\nShortest Path (Minimum Cost Path): ";
    for (int i = 0; i < stages; ++i) {
        cout << path[i];
        if (i != stages - 1) cout << " -> ";
    }
    cout << "\nTotal Minimum Cost: " << cost[0] << endl;
}

int main() {
    int vertices;
    cout << "Enter total number of nodes: ";
    cin >> vertices;

    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, INF));

    // Initializing diagonal to 0
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i][i] = 0;
    }

    int edgeCount;
    cout << "Enter total number of edges: ";
    cin >> edgeCount;

    cout << "Provide edges in format (u v weight) using 1-based indexing:\n";
    for (int i = 0; i < edgeCount; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u - 1][v - 1] = w;
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix of Graph:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (adjMatrix[i][j] == INF)
                cout << "INF\t";
            else
                cout << adjMatrix[i][j] << "\t";
        }
        cout << endl;
    }

    int stages = getStageCount(adjMatrix);
    cout << "\nEstimated Number of Stages: " << stages << endl;

    shortestPathMultiStage(adjMatrix, stages);

    return 0;
}

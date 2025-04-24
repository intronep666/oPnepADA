#include <iostream>
#include <climits>
using namespace std;

const int NUM_VERTICES = 9;

// Selects the vertex with the minimum distance value
int selectMinVertex(int distance[], bool finalized[]) {
    int minValue = INT_MAX;
    int selectedVertex = -1;

    for (int i = 0; i < NUM_VERTICES; ++i) {
        if (!finalized[i] && distance[i] <= minValue) {
            minValue = distance[i];
            selectedVertex = i;
        }
    }

    return selectedVertex;
}

// Displays the final shortest distances from the source node
void displayResults(int distance[]) {
    cout << "Node\tDistance from Source" << endl;
    for (int i = 0; i < NUM_VERTICES; ++i) {
        cout << i << "\t\t" << distance[i] << endl;
    }
}

// Core function implementing Dijkstra's Algorithm
void runDijkstra(int adjMatrix[NUM_VERTICES][NUM_VERTICES], int source) {
    int distance[NUM_VERTICES];
    bool visited[NUM_VERTICES];

    for (int i = 0; i < NUM_VERTICES; ++i) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[source] = 0;

    for (int count = 0; count < NUM_VERTICES - 1; ++count) {
        int u = selectMinVertex(distance, visited);
        visited[u] = true;

        for (int v = 0; v < NUM_VERTICES; ++v) {
            if (!visited[v] && adjMatrix[u][v] != 0 && distance[u] != INT_MAX
                && distance[u] + adjMatrix[u][v] < distance[v]) {
                distance[v] = distance[u] + adjMatrix[u][v];
            }
        }
    }

    displayResults(distance);
}

int main() {
    int adjMatrix[NUM_VERTICES][NUM_VERTICES] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    int startVertex = 0;
    runDijkstra(adjMatrix, startVertex);

    return 0;
}

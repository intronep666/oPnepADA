#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Disjoint Set Union class with path compression and union by size
class UnionFind {
    vector<int> parent;

public:
    UnionFind(int size) {
        parent.assign(size, -1);
    }

    int findRoot(int x) {
        if (parent[x] < 0) return x;
        return parent[x] = findRoot(parent[x]);
    }

    bool merge(int a, int b) {
        int rootA = findRoot(a);
        int rootB = findRoot(b);

        if (rootA == rootB) return false; // Same component

        if (parent[rootA] < parent[rootB]) {
            parent[rootA] += parent[rootB];
            parent[rootB] = rootA;
        } else {
            parent[rootB] += parent[rootA];
            parent[rootA] = rootB;
        }

        return true;
    }
};

// Comparator for priority queue (min-heap based on edge weights)
struct EdgeComp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0]; // Lower weight gets higher priority
    }
};

// Kruskal's Minimum Spanning Tree Algorithm
void buildMST(int vertices, vector<vector<int>>& edgeList) {
    priority_queue<vector<int>, vector<vector<int>>, EdgeComp> pq(edgeList.begin(), edgeList.end());

    UnionFind uf(vertices);
    int totalCost = 0, connectedEdges = 0;

    while (!pq.empty() && connectedEdges < vertices - 1) {
        auto current = pq.top();
        pq.pop();

        int cost = current[0], from = current[1], to = current[2];

        if (uf.merge(from, to)) {
            cout << "Selected Edge: (" << from << " - " << to << ") Cost: " << cost << "\n";
            totalCost += cost;
            connectedEdges++;
        }
    }

    if (connectedEdges == vertices - 1)
        cout << "Total Minimum Cost to Connect All Nodes: " << totalCost << endl;
    else
        cout << "Failed to construct MST - Graph may be disconnected." << endl;
}

int main() {
    int numNodes = 5;
    vector<vector<int>> allEdges = {
        {2, 0, 1}, {3, 1, 2}, {7, 2, 4}, {5, 1, 4}, 
        {9, 3, 4}, {6, 0, 3}, {8, 1, 3}
    };

    buildMST(numNodes, allEdges);

    return 0;
}

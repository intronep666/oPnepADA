#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int>p;
    public:
    DSU(int n)
    {   p.resize(n);
        for(int i=0;i<n;i++)
        {
            p[i]=-1;
        }
    }

    int find(int u) {
        if (p[u] < 0) return u;  
        return p[u] = find(p[u]);  // Path compression
    }
    
    //Union by size
    bool unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
                
        if (rootU == rootV) return false; // Already connected

        if (p[rootU] < p[rootV]) {  // rootU ka size bada hai
            p[rootU] += p[rootV];
            p[rootV] = rootU;
        } else {
            p[rootV] += p[rootU];
            p[rootU] = rootV;
        }
        return true;
    }
};

// Custom Comparator for Min-Heap
struct Compare {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[0] > b[0]; // Min-Heap based on weight
    }
};


// Kruskal’s Algorithm for MST
void kruskalMST(int n,vector<vector<int>>&edges){
    priority_queue<vector<int>,vector<vector<int>>,Compare>minHeap(edges.begin(),edges.end());

    DSU dsu(n);
    int minCost =0, edgesUsed =0;

    while(!minHeap.empty()&&edgesUsed < n-1){
        auto edge = minHeap.top();
        minHeap.pop();

        int w = edge[0], u = edge[1], v = edge[2];

        if(dsu.unionSet(u,v)){ // If adding this edge doesn’t create a cycle
         minCost+=w;
         edgesUsed++;
         cout<< "Edges: (" << u <<"-"<<v<<") with cost:"<<w<<endl;
        }
    }
    if (edgesUsed == n - 1)
        cout << "Minimum Spanning Tree Cost: " << minCost << endl;
    else
        cout << "MST not possible!" << endl;
}


int main() {
    int n = 5; // Number of vertices
    vector<vector<int>> edges = {
        {2, 0, 1}, {3, 1, 2}, {7, 2, 4}, {5, 1, 4}, {9, 3, 4}, {6, 0, 3}, {8, 1, 3}
    };

    kruskalMST(n, edges);

    return 0;
}

//Time Complexity

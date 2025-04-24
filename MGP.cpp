#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int countStages(vector<vector<int>>&Graph){
int k = 1;//source node ka stage 1
int u =0;
for(int v = u+1;v<Graph.size();v++)
{
    if(Graph[u][v]!=INF){
        u = v;
        k++;
    }
}
return k;
}

void MGP(vector<vector<int>>&Graph,int k){
    int n = Graph.size();
    vector<int> fdist(n, INF); // Minimum cost from each node to final node ko initialize kar do infinity se
    vector<int> d(n, -1);     // Stores next node in shortest path ko initialize kar do -1 sw

    fdist[n-1] = 0; //final node ka cost 0 hoga
    for(int j = n-2;j>=0;j--)
    {
        for(int r=j+1;r<n;r++)
        {
            if (Graph[j][r] != INF && Graph[j][r] != 0)// Valid edge
             { 
                if (Graph[j][r] + fdist[r] < fdist[j]) {
                    fdist[j] = Graph[j][r] + fdist[r];
                    d[j] = r; // next node ko store kar do  shortest path me 
                }
            }
        }
    }
   
  // Find minimum-cost path using d[]
vector<int> p(k); // Path array
p[0] = 1;  // First node (1-based indexing)
p[k - 1] = n; // Last node (1-based indexing)

for (int j = 1; j < k - 1; j++) {
    p[j] = d[p[j - 1] - 1] + 1; // Convert 0-based to 1-based
}

// Output the minimum-cost path
cout << "\nMinimum-cost path: ";
for (int i = 0; i < k; i++) {
    cout << p[i] << (i == k - 1 ? "\n" : " -> ");
}


   cout << "Minimum cost: " << fdist[0] << endl;


}
int main()
{   const int INF = 1e9;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    // Graph initialization: Diagonal = 0, Others = INF
    vector<vector<int>> Graph(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        Graph[i][i] = 0; // Diagonal elements = 0
    }

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v cost) (1-based indexing):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        Graph[u - 1][v - 1] = cost; // Convert to 0-based index
    }

    // Displaying the Graph
    cout << "\nGraph Representation (Adjacency Matrix):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Graph[i][j] == INF)
                cout << "INF\t";
            else
                cout << Graph[i][j] << "\t";
        }
        cout << endl;
    }

   int k = countStages(Graph);
   cout<<"Number of Stages:"<<k<<endl;
   MGP(Graph,k);

   return 0;

}


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair; // (profit, weight)
void Traceback(int Px, int Wx, int n, vector<set<Pair>> &S, vector<int> &wt, vector<int> &val) {
    for(int i = n; i >= 1; i--) {
        int prevP = Px - val[i - 1];
        int prevW = Wx - wt[i - 1];

        if (S[i - 1].count({Px, Wx})) {
            cout << "x" << i << " = 0" << endl;  // item not taken
        } else if (S[i - 1].count({prevP, prevW})) {
            cout << "x" << i << " = 1" << endl;  // item taken
            Px = prevP;
            Wx = prevW;
        } else {
            cout << "Error: no matching previous state found for item " << i << endl;
        }
    }
}
set<Pair>mergePurge(set<Pair> &a,set<Pair> &b){
    set<Pair>combined = a;
    for(auto p :b){
        combined.insert(p);
    }

    set<Pair>result;
    int maxProfit = -1;
    for(auto p : combined){
      if(p.first > maxProfit){
        result.insert({p.first,p.second});
        maxProfit = p.first;
      }
    }
    return result;

}
void knapsack(vector<int> &wt,vector<int> &val,int W){
    int n = wt.size();
    vector<set<Pair>>S(n+1);
    S[0].insert({0,0});
    for(int i = 1;i<=n;i++){
        set<Pair>S1;
        for(auto p : S[i-1]){
            int newW = p.second + wt[i-1];
            int newP = p.first + val[i-1];
            if(newW <= W){
                S1.insert({newP,newW});
            }
        }
        S[i] = mergePurge(S[i-1],S1);
    }
    
    auto it = S[n].rbegin(); // last element in the set (max profit)
    int Px = it->first;
    int Wx = it->second;
    cout<<"Maximum profit is:"<<Px<<endl;
    Traceback(Px,Wx,n,S,wt,val);


}

int main()
{
    vector<int> wt = {5, 4, 6, 3};
    vector<int> val = {10, 40, 30, 50};
    int W = 10;

   knapsack(wt, val, W) ;
    return 0;
}



//Method -2
// int knapsack(vector<int>& wt, vector<int>& val, int W){
//     int n = wt.size();
//     vector<set<pair<int,int>>> S(n + 1);
//     S[0].insert({0, 0}); // (value, weight)

//     for(int i = 0; i < n; i++){
//         S[i+1] = S[i]; // Start with previous values
//         for(auto p : S[i]){
//             int new_val = p.first + val[i];
//             int new_wt = p.second + wt[i];
//             if(new_wt <= W){
//                 S[i+1].insert({new_val, new_wt});
//             }
//         }

//         // Prune dominated pairs
//         set<pair<int, int>> pruned;
//         int min_wt = INT_MAX;
//         for(auto it = S[i+1].rbegin(); it != S[i+1].rend(); ++it){
//             if(it->second < min_wt){
//                 pruned.insert(*it);
//                 min_wt = it->second;
//             }
//         }
//         S[i+1] = pruned;
//     }

//     // Find max value with weight <= W
//     int max_val = 0;
//     for(auto p : S[n]){
//         if(p.second <= W){
//             max_val = max(max_val, p.first);
//         }
//     }
//     return max_val;
// }
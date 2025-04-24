#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Trace back to find selected items
    int w = W;
    vector<int> selectedItems;

    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selectedItems.push_back(i - 1); // Item i-1 was taken
            w -= wt[i - 1];                 // Reduce capacity
        }
    }

    // Print results
    cout << "Maximum value: " << dp[n][W] << endl;
    cout << "Selected item indices : ";
    for (int idx : selectedItems) {
        cout << idx+1 << " ";
    }
    cout << endl;

    return dp[n][W];
}

int main() {
    vector<int> wt = {5, 4, 6,3};
    vector<int> p  = {10, 40, 30, 50};
    int W = 10;

    cout << "Maximum value: " << knapsack(wt, p, W) << endl;
  return 0;
}
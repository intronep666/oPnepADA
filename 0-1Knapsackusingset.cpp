#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>; // (value, weight)

// Function to reconstruct which items were selected
void Backtrack(int finalVal, int finalWt, int itemCount, vector<set<PII>> &states, vector<int> &weights, vector<int> &values) {
    for (int i = itemCount; i >= 1; --i) {
        int priorVal = finalVal - values[i - 1];
        int priorWt = finalWt - weights[i - 1];

        if (states[i - 1].count({finalVal, finalWt})) {
            cout << "x" << i << " = 0\n"; // item not chosen
        } else if (states[i - 1].count({priorVal, priorWt})) {
            cout << "x" << i << " = 1\n"; // item chosen
            finalVal = priorVal;
            finalWt = priorWt;
        } else {
            cout << "Trace error at item " << i << endl;
        }
    }
}

// Function to merge and filter states to avoid dominated ones
set<PII> combineAndPrune(set<PII> &setA, set<PII> &setB) {
    set<PII> merged = setA;
    for (const auto &entry : setB) {
        merged.insert(entry);
    }

    set<PII> pruned;
    int maxVal = -1;
    for (const auto &entry : merged) {
        if (entry.first > maxVal) {
            pruned.insert(entry);
            maxVal = entry.first;
        }
    }
    return pruned;
}

// Main knapsack algorithm
void solveKnapsack(vector<int> &weights, vector<int> &values, int capacity) {
    int n = weights.size();
    vector<set<PII>> dp(n + 1);
    dp[0].insert({0, 0});

    for (int i = 1; i <= n; ++i) {
        set<PII> newStates;
        for (const auto &state : dp[i - 1]) {
            int updatedWt = state.second + weights[i - 1];
            int updatedVal = state.first + values[i - 1];
            if (updatedWt <= capacity) {
                newStates.insert({updatedVal, updatedWt});
            }
        }
        dp[i] = combineAndPrune(dp[i - 1], newStates);
    }

    auto best = dp[n].rbegin();
    int bestVal = best->first;
    int bestWt = best->second;

    cout << "Maximum profit: " << bestVal << endl;
    Backtrack(bestVal, bestWt, n, dp, weights, values);
}

int main() {
    vector<int> weights = {5, 4, 6, 3};
    vector<int> values = {10, 40, 30, 50};
    int capacity = 10;

    solveKnapsack(weights, values, capacity);
    return 0;
}

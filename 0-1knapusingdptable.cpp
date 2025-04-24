#include <bits/stdc++.h>
using namespace std;

// Function to compute the optimal knapsack value
int findMaxValue(vector<int>& weights, vector<int>& values, int capacity) {
    int itemCount = weights.size();
    vector<vector<int>> table(itemCount + 1, vector<int>(capacity + 1, 0));

    // Build the table in bottom-up fashion
    for (int i = 1; i <= itemCount; ++i) {
        for (int cap = 0; cap <= capacity; ++cap) {
            if (weights[i - 1] <= cap) {
                int take = values[i - 1] + table[i - 1][cap - weights[i - 1]];
                int skip = table[i - 1][cap];
                table[i][cap] = max(take, skip);
            } else {
                table[i][cap] = table[i - 1][cap];
            }
        }
    }

    // Identify the items that were chosen
    vector<int> chosenItems;
    int remCapacity = capacity;

    for (int i = itemCount; i > 0 && remCapacity > 0; --i) {
        if (table[i][remCapacity] != table[i - 1][remCapacity]) {
            chosenItems.push_back(i - 1);
            remCapacity -= weights[i - 1];
        }
    }

    // Display the result
    cout << "Total Profit: " << table[itemCount][capacity] << "\n";
    cout << "Items selected (1-based indices): ";
    for (int idx : chosenItems) {
        cout << (idx + 1) << " ";
    }
    cout << endl;

    return table[itemCount][capacity];
}

int main() {
    vector<int> weights = {5, 4, 6, 3};
    vector<int> profits = {10, 40, 30, 50};
    int bagCapacity = 10;

    findMaxValue(weights, profits, bagCapacity);

    return 0;
}

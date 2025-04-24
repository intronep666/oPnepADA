#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to represent an object with value and weight
struct Object {
    int value;
    int weight;
};

// Custom comparator to sort objects by decreasing value-to-weight ratio
bool byRatio(const Object& x, const Object& y) {
    return (double)x.value / x.weight > (double)y.value / y.weight;
}

// Function to perform fractional knapsack
void solveKnapsack(const vector<Object>& objects, int maxWeight) {
    vector<Object> items = objects; // Copy input to avoid modifying original
    sort(items.begin(), items.end(), byRatio); // Sort items by value density

    double profitCollected = 0.0;
    int weightUsed = 0;

    cout << "Items taken:\n";

    for (const auto& obj : items) {
        if (weightUsed + obj.weight <= maxWeight) {
            // Take full item
            profitCollected += obj.value;
            weightUsed += obj.weight;
            cout << "  Value: " << obj.value << ", Weight: " << obj.weight << " [Full]\n";
        } else {
            // Take fractional item
            int spaceLeft = maxWeight - weightUsed;
            double partValue = obj.value * ((double)spaceLeft / obj.weight);
            profitCollected += partValue;
            cout << "  Value: " << partValue << ", Weight: " << spaceLeft << " [Partial]\n";
            break; // Knapsack is full
        }
    }

    cout << "Maximum Profit Obtained: " << profitCollected << endl;
}

int main() {
    vector<Object> data = {
        {25, 18},
        {24, 15},
        {15, 10}
    };

    int knapsackCapacity = 20;
    solveKnapsack(data, knapsackCapacity);

    return 0;
}

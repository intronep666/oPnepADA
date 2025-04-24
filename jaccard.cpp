#include <bits/stdc++.h>
using namespace std;

void jaccard(vector<int> arr1, vector<int> arr2) {
    // Convert arrays to sets for unique elements
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> set2(arr2.begin(), arr2.end());

    int intersect = 0;
    unordered_set<int> union_set = set1;

    // Count intersection
    for (int num : set2) {
        if (set1.count(num)) {
            intersect++;
        }
        union_set.insert(num); // Union of both sets
    }

    int uni = union_set.size(); // Total unique elements in both sets

    cout << "Jaccard Coefficient of Similarity = " << (double)intersect / uni << endl;
}

int main() {
    vector<int> arr1 = {0, 1, 2, 5, 6};
    vector<int> arr2 = {0, 2, 3, 4, 5, 7, 9};
    
    jaccard(arr1, arr2);
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to compute Jaccard similarity between two integer vectors
void computeJaccardSimilarity(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> uniqueA(a.begin(), a.end());
    unordered_set<int> uniqueB(b.begin(), b.end());
    unordered_set<int> combinedSet;

    int commonElements = 0;

    // Count common elements
    for (const int& element : uniqueB) {
        if (uniqueA.find(element) != uniqueA.end()) {
            ++commonElements;
        }
        combinedSet.insert(element);
    }

    // Add elements from the first set to complete the union
    for (const int& element : uniqueA) {
        combinedSet.insert(element);
    }

    int totalUnique = combinedSet.size();

    double jaccardIndex = static_cast<double>(commonElements) / totalUnique;

    cout << "Jaccard Similarity Coefficient = " << jaccardIndex << endl;
}

int main() {
    vector<int> list1 = {0, 1, 2, 5, 6};
    vector<int> list2 = {0, 2, 3, 4, 5, 7, 9};

    computeJaccardSimilarity(list1, list2);

    return 0;
}

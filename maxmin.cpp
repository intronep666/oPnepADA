#include <iostream>
using namespace std;

// Function to get max and min from a subarray using divide and conquer
pair<int, int> findExtremes(int data[], int start, int end) {
    // If only one element, it is both min and max
    if (start == end)
        return {data[start], data[start]};

    // Divide the array into two halves
    int middle = start + (end - start) / 2;

    // Recursive calls for both halves
    pair<int, int> left = findExtremes(data, start, middle);
    pair<int, int> right = findExtremes(data, middle + 1, end);

    // Combine results
    int maxVal = max(left.first, right.first);
    int minVal = min(left.second, right.second);

    return {maxVal, minVal};
}

int main() {
    int elements[] = {12, 7, 19, 5, 18, 3, 8, 11, 22, 10};
    int size = sizeof(elements) / sizeof(elements[0]);

    pair<int, int> result = findExtremes(elements, 0, size - 1);

    cout << "Highest Value: " << result.first << endl;
    cout << "Lowest Value: " << result.second << endl;

    return 0;
}

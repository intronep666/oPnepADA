#include <iostream>
using namespace std;

// Recursive function to perform binary search
bool searchBinary(int array[], int start, int end, int target) {
    if (start > end) {
        return false; // Target is not present
    }

    int middle = start + (end - start) / 2;

    if (array[middle] == target) {
        return true; // Target found
    }

    if (target < array[middle]) {
        return searchBinary(array, start, middle - 1, target); // Check left half
    } else {
        return searchBinary(array, middle + 1, end, target); // Check right half
    }
}

int main() {
    int data[] = {2, 3, 4, 10, 40};
    int size = sizeof(data) / sizeof(data[0]);
    int element = 10;

    bool found = searchBinary(data, 0, size - 1, element);

    if (found) {
        cout << "Element is present in the array." << endl;
    } else {
        cout << "Element is not present in the array." << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to locate a peak element using binary search
int findPeakElement(int arr[], int size) {
    // Edge cases: first and last elements
    if (size == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[size - 1] > arr[size - 2]) return size - 1;

    int start = 1, end = size - 2;

    while (start <= end) {
        int middle = start + (end - start) / 2;

        if (arr[middle] > arr[middle - 1] && arr[middle] > arr[middle + 1])
            return middle;

        // If right neighbor is greater, search right half
        if (arr[middle] < arr[middle + 1])
            start = middle + 1;
        else
            end = middle - 1;
    }

    return -1; // Should not be reached for valid input
}

int main() {
    int nums[] = {11, 13, 20, 25, 18};
    int len = sizeof(nums) / sizeof(nums[0]);

    int index = findPeakElement(nums, len);

    if (index != -1)
        cout << "Peak element found: " << nums[index] << endl;
    else
        cout << "No peak element found!" << endl;

    return 0;
}

#include <iostream>
using namespace std;

bool binarySearch(int arr[], int key, int s, int e) {
    if (s > e) 
        return false; // Base case: element not found

    int mid = s + (e - s) / 2;

    if (key == arr[mid]) 
        return true; // Base case: element found

    if (key < arr[mid]) 
        return binarySearch(arr, key, s, mid - 1); // Search in left half
    else 
        return binarySearch(arr, key, mid + 1, e); // Search in right half
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    bool ans = binarySearch(arr, key, 0, n - 1);

    if (ans) 
        cout << "Element found" << endl;
    else 
        cout << "Element not found" << endl;

    return 0;
}

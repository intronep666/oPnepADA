#include <bits/stdc++.h>
using namespace std;

// Function to perform merge operation
void combine(long int arr[], long int left, long int mid, long int right) {
    vector<long int> temp(right - left + 1);
    long int i = left, j = mid + 1, k = 0;

    // Merging the two halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (long int p = 0; p < temp.size(); p++)
        arr[left + p] = temp[p];
}

// Recursive merge sort implementation
void sortMerge(long int arr[], long int low, long int high) {
    if (low >= high) return;

    long int mid = low + (high - low) / 2;
    sortMerge(arr, low, mid);
    sortMerge(arr, mid + 1, high);
    combine(arr, low, mid, high);
}

int main() {
    long int size = 10000;
    int trials = 10;
    cout << "ArraySize, TimeTaken(sec)" << endl;

    for (int run = 0; run < trials; run++) {
        vector<long int> data(size);

        // Populate with random data
        for (int i = 0; i < size; i++) {
            data[i] = rand() % size + 1;
        }

        auto begin = chrono::high_resolution_clock::now();
        sortMerge(data.data(), 0, size - 1);
        auto finish = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = finish - begin;
        cout << size << ", " << elapsed.count() << endl;

        size += 10000;
    }

    return 0;
}

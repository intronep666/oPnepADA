#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

// Rearranges the array and returns the pivot index
int performPartition(long int data[], int start, int end) {
    long int pivot = data[start];
    int left = start;
    int right = end;

    while (left < right) {
        while (data[left] <= pivot && left <= end - 1) {
            left++;
        }
        while (data[right] > pivot && right >= start + 1) {
            right--;
        }
        if (left < right) {
            swap(data[left], data[right]);
        }
    }

    swap(data[start], data[right]);
    return right;
}

// Recursive implementation of quicksort
void executeQuickSort(long int data[], int start, int end) {
    if (start < end) {
        int pivotIndex = performPartition(data, start, end);
        executeQuickSort(data, start, pivotIndex - 1);
        executeQuickSort(data, pivotIndex + 1, end);
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Initialize random seed

    int size = 1000;
    while (size <= 25000) {
        double totalDuration = 0.0;

        for (int iteration = 0; iteration < 10; ++iteration) {
            long int dataset[size];

            // Populate the array with random values
            for (int i = 0; i < size; ++i) {
                dataset[i] = rand() % size + 1;
            }

            // Measure sorting time
            auto begin = chrono::high_resolution_clock::now();
            executeQuickSort(dataset, 0, size - 1);
            auto finish = chrono::high_resolution_clock::now();

            chrono::duration<double> elapsed = finish - begin;
            totalDuration += elapsed.count();
        }

        double averageTime = totalDuration / 10.0;
        cout << "Array Size: " << size << ", Average Time: " << averageTime << " seconds" << endl;

        size += 1000; // Increase size for next test
    }

    return 0;
}

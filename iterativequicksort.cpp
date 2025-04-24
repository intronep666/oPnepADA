#include <iostream>
#include <stack>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace chrono;

// Partition function using Lomuto-style logic but for iterative quicksort
int partitionIterative(long int array[], int low, int high) {
    long int pivot = array[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {
        while (left <= right && array[left] <= pivot) left++;
        while (left <= right && array[right] > pivot) right--;

        if (left < right) {
            swap(array[left], array[right]);
        }
    }

    swap(array[low], array[right]);
    return right;
}

// Iterative QuickSort using a stack and do-while loop
void iterativeQuickSort(long int array[], int start, int end) {
    stack<int> bounds;

    do {
        while (start < end) {
            int pivotIndex = partitionIterative(array, start, end);

            if (pivotIndex - start > end - pivotIndex) {
                bounds.push(start);
                bounds.push(pivotIndex - 1);
                start = pivotIndex + 1;
            } else {
                bounds.push(pivotIndex + 1);
                bounds.push(end);
                end = pivotIndex - 1;
            }
        }

        if (bounds.empty()) break;

        end = bounds.top(); bounds.pop();
        start = bounds.top(); bounds.pop();

    } while (true);
}

// Verify if the array is sorted
bool verifySorted(const long int arr[], int len) {
    for (int i = 1; i < len; ++i) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int size = 1000;

    while (size <= 10000) {
        double totalElapsedTime = 0;

        for (int trial = 0; trial < 10; ++trial) {
            long int* data = new long int[size];

            // Populate the array with random numbers
            for (int i = 0; i < size; ++i) {
                data[i] = rand() % size + 1;
            }

            auto begin = high_resolution_clock::now();
            iterativeQuickSort(data, 0, size - 1);
            auto finish = high_resolution_clock::now();

            chrono::duration<double> elapsed = finish - begin;
            totalElapsedTime += elapsed.count();

            if (!verifySorted(data, size)) {
                cout << "Error: Sorting failed at size " << size << endl;
                delete[] data;
                return -1;
            }

            delete[] data;
        }

        double averageDuration = totalElapsedTime / 10;
        cout << "Array Size: " << size << " | Avg Time: " << averageDuration << " seconds" << endl;

        size += 1000;
    }

    return 0;
}

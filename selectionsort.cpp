#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

// Selection sort algorithm: sorts array in ascending order
void performSelectionSort(long int data[], int length) {
    for (int current = 0; current < length - 1; ++current) {
        int smallest = current;

        // Find the index of the minimum element in the remaining array
        for (int next = current + 1; next < length; ++next) {
            if (data[next] < data[smallest]) {
                smallest = next;
            }
        }

        // Swap if the minimum is not at the current position
        if (smallest != current) {
            swap(data[current], data[smallest]);
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for randomness

    int arraySize = 1000;

    // Test selection sort for different sizes
    while (arraySize <= 25000) {
        double accumulatedTime = 0.0;

        for (int trial = 0; trial < 10; ++trial) {
            long int sample[arraySize];

            // Fill array with random integers
            for (int index = 0; index < arraySize; ++index) {
                sample[index] = rand() % arraySize + 1;
            }

            // Time the sorting operation
            auto begin = chrono::high_resolution_clock::now();
            performSelectionSort(sample, arraySize);
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double> timeSpan = end - begin;
            accumulatedTime += timeSpan.count();
        }

        double averageDuration = accumulatedTime / 10.0;
        cout << "Array Size: " << arraySize << ", Avg Time: " << averageDuration << " seconds" << endl;

        arraySize += 1000; // Step to next array size
    }

    return 0;
}

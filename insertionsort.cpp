#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

// Insertion sort implementation
void performInsertionSort(vector<int>& data) {
    int size = data.size();
    for (int i = 1; i < size; ++i) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}

// Function to generate random integers in a vector
vector<int> generateRandomArray(int size) {
    vector<int> result(size);
    for (int i = 0; i < size; ++i) {
        result[i] = rand();  // Random number generation
    }
    return result;
}

int main() {
    int arraySize = 1000;

    while (arraySize <= 10000) {
        long long accumulatedTime = 0;

        for (int iteration = 0; iteration < 10; ++iteration) {
            vector<int> testArray = generateRandomArray(arraySize);

            auto start = high_resolution_clock::now();
            performInsertionSort(testArray);
            auto end = high_resolution_clock::now();

            auto elapsed = duration_cast<microseconds>(end - start).count();
            accumulatedTime += elapsed;
        }

        double averageTimeMs = accumulatedTime / 10.0 / 1000.0;
        cout << "Array Length: " << arraySize << " | Average Time: " << averageTimeMs << " ms" << endl;

        arraySize += 1000;
    }

    return 0;
}

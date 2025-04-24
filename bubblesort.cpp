#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void performBubbleSort(long int* data, int length) {
    for (int pass = 0; pass < length - 1; ++pass) {
        for (int idx = 0; idx < length - pass - 1; ++idx) {
            if (data[idx] > data[idx + 1]) {
                swap(data[idx], data[idx + 1]);
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Initialize random seed

    int size = 1000;
    while (size <= 25000) {
        double accumulatedTime = 0.0;

        for (int trial = 0; trial < 10; ++trial) {
            long int* values = new long int[size];

            // Fill array with random integers
            for (int i = 0; i < size; ++i) {
                values[i] = rand() % size + 1;
            }

            auto begin = chrono::steady_clock::now();
            performBubbleSort(values, size);
            auto finish = chrono::steady_clock::now();

            chrono::duration<double> elapsed = finish - begin;
            accumulatedTime += elapsed.count();

            delete[] values;
        }

        double averageTime = accumulatedTime / 10.0;
        cout << "Array Size: " << size << " --> Average Time: " << averageTime << " seconds" << endl;

        size += 1000;
    }

    return 0;
}

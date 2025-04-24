#include <bits/stdc++.h>
using namespace std;

void magicsquare(vector<vector<int>> &a, int n) {
    int i = 0, j = n / 2; // Start at the middle of the first row

    for (int k = 1; k <= n * n; k++) {
        a[i][j] = k; // Place the number in the grid

        // Store current position before moving
        i = (i - 1 + n) % n; // Move up (wrap around using modulo)
        j = (j + 1) % n;     // Move right (wrap around using modulo)

        // If the new cell is already occupied, move down instead
        if (a[i][j] != 0) {
            i = (i + 1) % n; // Move down
        
        }
    } 
}

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "Magic square is only possible for odd numbers." << endl;
        return 1;
    }

    // Creating a 2D vector initialized with 0
    vector<vector<int>> a(n, vector<int>(n, 0));

    // Generate magic square
    magicsquare(a, n);

    // Display the magic square
    cout << "Magic Square of order " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << a[i][j]; // Print formatted numbers
        }
        cout << endl;
    }

    return 0;
}

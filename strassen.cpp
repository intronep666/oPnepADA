#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

// Function to add two matrices
Matrix addMatrix(const Matrix &A, const Matrix &B, int size) {
    Matrix result(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Function to subtract two matrices
Matrix subtractMatrix(const Matrix &A, const Matrix &B, int size) {
    Matrix result(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// Strassen’s Algorithm for matrix multiplication
Matrix strassenMultiply(Matrix A, Matrix B, int size) {
    if (size == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = size / 2;
    Matrix A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));

    // Dividing matrices into quadrants
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Computing Strassen's 7 multiplications
    Matrix P1 = strassenMultiply(A11, subtractMatrix(B12, B22, newSize), newSize);
    Matrix P2 = strassenMultiply(addMatrix(A11, A12, newSize), B22, newSize);
    Matrix P3 = strassenMultiply(addMatrix(A21, A22, newSize), B11, newSize);
    Matrix P4 = strassenMultiply(A22, subtractMatrix(B21, B11, newSize), newSize);
    Matrix P5 = strassenMultiply(addMatrix(A11, A22, newSize), addMatrix(B11, B22, newSize), newSize);
    Matrix P6 = strassenMultiply(subtractMatrix(A12, A22, newSize), addMatrix(B21, B22, newSize), newSize);
    Matrix P7 = strassenMultiply(subtractMatrix(A11, A21, newSize), addMatrix(B11, B12, newSize), newSize);

    // Computing the resultant quadrants
    Matrix C11 = addMatrix(subtractMatrix(addMatrix(P5, P4, newSize), P2, newSize), P6, newSize);
    Matrix C12 = addMatrix(P1, P2, newSize);
    Matrix C21 = addMatrix(P3, P4, newSize);
    Matrix C22 = subtractMatrix(subtractMatrix(addMatrix(P5, P1, newSize), P3, newSize), P7, newSize);

    // Combining the quadrants into a single matrix
    Matrix C(size, vector<int>(size, 0));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const Matrix &M) {
    for (const auto &row : M) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    int n = 4;  // Matrix size (should be a power of 2)
    Matrix A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Matrix B = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

    cout << "Matrix A:\n";
    printMatrix(A);
    cout << "\nMatrix B:\n";
    printMatrix(B);

    Matrix C = strassenMultiply(A, B, n);

    cout << "\nResultant Matrix (A * B):\n";
    printMatrix(C);

    return 0;
}

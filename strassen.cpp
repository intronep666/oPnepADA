#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

// Add two square matrices
Matrix add(const Matrix& matA, const Matrix& matB, int dim) {
    Matrix sum(dim, vector<int>(dim));
    for (int r = 0; r < dim; ++r)
        for (int c = 0; c < dim; ++c)
            sum[r][c] = matA[r][c] + matB[r][c];
    return sum;
}

// Subtract one matrix from another
Matrix subtract(const Matrix& matA, const Matrix& matB, int dim) {
    Matrix diff(dim, vector<int>(dim));
    for (int r = 0; r < dim; ++r)
        for (int c = 0; c < dim; ++c)
            diff[r][c] = matA[r][c] - matB[r][c];
    return diff;
}

// Recursive Strassen matrix multiplication
Matrix strassen(const Matrix& matA, const Matrix& matB, int dim) {
    if (dim == 1) return {{matA[0][0] * matB[0][0]}};

    int half = dim / 2;
    Matrix A11(half, vector<int>(half)), A12(half, vector<int>(half));
    Matrix A21(half, vector<int>(half)), A22(half, vector<int>(half));
    Matrix B11(half, vector<int>(half)), B12(half, vector<int>(half));
    Matrix B21(half, vector<int>(half)), B22(half, vector<int>(half));

    // Splitting the matrices
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = matA[i][j];
            A12[i][j] = matA[i][j + half];
            A21[i][j] = matA[i + half][j];
            A22[i][j] = matA[i + half][j + half];

            B11[i][j] = matB[i][j];
            B12[i][j] = matB[i][j + half];
            B21[i][j] = matB[i + half][j];
            B22[i][j] = matB[i + half][j + half];
        }
    }

    // 7 recursive multiplications
    Matrix M1 = strassen(add(A11, A22, half), add(B11, B22, half), half);
    Matrix M2 = strassen(add(A21, A22, half), B11, half);
    Matrix M3 = strassen(A11, subtract(B12, B22, half), half);
    Matrix M4 = strassen(A22, subtract(B21, B11, half), half);
    Matrix M5 = strassen(add(A11, A12, half), B22, half);
    Matrix M6 = strassen(subtract(A21, A11, half), add(B11, B12, half), half);
    Matrix M7 = strassen(subtract(A12, A22, half), add(B21, B22, half), half);

    // Compute resulting quadrants
    Matrix C11 = add(subtract(add(M1, M4, half), M5, half), M7, half);
    Matrix C12 = add(M3, M5, half);
    Matrix C21 = add(M2, M4, half);
    Matrix C22 = subtract(subtract(add(M1, M3, half), M2, half), M6, half);

    // Combine submatrices into the final matrix
    Matrix result(dim, vector<int>(dim));
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + half] = C12[i][j];
            result[i + half][j] = C21[i][j];
            result[i + half][j + half] = C22[i][j];
        }
    }

    return result;
}

// Display a matrix
void displayMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (int val : row) cout << val << " ";
        cout << '\n';
    }
}

int main() {
    int dim = 4;
    Matrix A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Matrix B = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

    cout << "Matrix A:\n";
    displayMatrix(A);
    cout << "\nMatrix B:\n";
    displayMatrix(B);

    Matrix C = strassen(A, B, dim);

    cout << "\nProduct of A and B using Strassen's Method:\n";
    displayMatrix(C);

    return 0;
}

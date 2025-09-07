#include <iostream>
using namespace std;

#define MAX 100

void readSparse(int mat[MAX][3]) {
    int rows, cols, nonZero;
    cout << "Enter rows, columns, and number of non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = nonZero;

    cout << "Enter row, column, value for each non-zero element:\n";
    for (int i = 1; i <= nonZero; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}

void printSparse(int mat[MAX][3]) {
    int n = mat[0][2];
    cout << "\nRow Col Value\n";
    for (int i = 0; i <= n; i++) {
        cout << mat[i][0] << "   " << mat[i][1] << "   " << mat[i][2] << endl;
    }
}

void transpose(int mat[MAX][3], int trans[MAX][3]) {
    int rows = mat[0][0], cols = mat[0][1], n = mat[0][2];
    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = n;

    int k = 1;
    for (int col = 0; col < cols; col++) {
        for (int i = 1; i <= n; i++) {
            if (mat[i][1] == col) {
                trans[k][0] = mat[i][1];
                trans[k][1] = mat[i][0];
                trans[k][2] = mat[i][2];
                k++;
            }
        }
    }
}

void addSparse(int a[MAX][3], int b[MAX][3], int sum[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible. Sizes differ.\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++; k++;
        }
        else {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
    }

    while (i <= a[0][2]) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++; k++;
    }

    while (j <= b[0][2]) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1;
}

void multiplySparse(int a[MAX][3], int b[MAX][3], int prod[MAX][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible. Sizes mismatch.\n";
        return;
    }

    int transB[MAX][3];
    transpose(b, transB);

    prod[0][0] = a[0][0];
    prod[0][1] = b[0][1];
    int k = 1;

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= transB[0][2]; j++) {
            if (a[i][1] == transB[j][1]) {
                int row = a[i][0];
                int col = transB[j][0];
                int value = a[i][2] * transB[j][2];

                bool found = false;
                for (int x = 1; x < k; x++) {
                    if (prod[x][0] == row && prod[x][1] == col) {
                        prod[x][2] += value;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    prod[k][0] = row;
                    prod[k][1] = col;
                    prod[k][2] = value;
                    k++;
                }
            }
        }
    }

    prod[0][2] = k - 1;
}

int main() {
    int a[MAX][3], b[MAX][3], result[MAX][3];

    cout << "Enter first sparse matrix:\n";
    readSparse(a);

    cout << "First matrix in triplet form:";
    printSparse(a);

    cout << "\nTranspose of first matrix:";
    transpose(a, result);
    printSparse(result);

    cout << "\nEnter second sparse matrix (same size for addition):\n";
    readSparse(b);

    cout << "Second matrix in triplet form:";
    printSparse(b);

    cout << "\nAddition of matrices:";
    addSparse(a, b, result);
    printSparse(result);

    cout << "\nMultiplication of matrices:";
    multiplySparse(a, b, result);
    printSparse(result);

    return 0;
}


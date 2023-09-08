#include <iostream>
#include <algorithm>
#include "stdio.h"

using namespace std;

// Функція для виводу матриці на екран
void printMatrix(int **matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Функція для виділення пам'яті під матрицю та заповнення її елементами
int** createAndFillMatrix(int N, int M) {
    int** matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[M];
        printf("Enter %d elements for %d line:\n", M, i+1);
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// Функція для звільнення пам'яті, виділеної для матриці
void deleteMatrix(int** matrix, int N) {
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Функція для порівняння рядків за першими елементами
bool compareRows(const int* row1, const int* row2) {
    return row1[0] < row2[0];
}

int main() {
    int N, M;

    cout << "Lines (N): ";
    cin >> N;
    cout << "Columns (M): ";
    cin >> M;

    int** matrix = createAndFillMatrix(N, M);

    sort(matrix, matrix + N, compareRows);

    cout << "Sorted:\n";
    printMatrix(matrix, N, M);

    deleteMatrix(matrix, N);

    return 0;
}


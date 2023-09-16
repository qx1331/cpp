#include "iostream"
#include "stdio.h"

using namespace std;
// Задано двовимірний масив цілих чисел 5 х 5, розмір якого задається з клавіатури. Знайти суму максимальних елементів кожного рядка матриці.

int main() {
    const int rows = 5;
    const int columns = 5;
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }


    cout << "Enter elements for matrix: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> matrix[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < rows; i++) {
        int max_element = matrix[i][0];
        for (int j = 1; j < columns; j++) {
            if (matrix[i][j] > max_element)
                max_element = matrix[i][j];
        }
        sum += max_element;
    }

    cout << sum;

    delete[] matrix;
    return 0;
}

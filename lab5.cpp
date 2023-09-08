#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stdio.h"

using namespace std;

/*
    Сухомлин Д, кнмс-22, лаба 5, вар 1
    Написати програму по обробці одновимірних масивів. Розміри масивів вводити з клавіатури
*/

int main() {
    int n;

    cout << "Введіть розмір масиву: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Оберіть спосіб заповнення масиву:\n";
    cout << "1. З клавіатури\n";
    cout << "2. Випадковими значеннями\n";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Введіть елементи масиву:\n";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }
            cout << "Ваш масив: ";
            for (int i=0; i<n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 2:
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;  // від 0 до 99
        }
        cout << "Згенерований масив: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        break;

        default:
            cout << "Невірний вибір.\n";
            return 1;
    }

    // Знаходимо мінімальний і максимальний елементи та їхні позиції
    int minElement = arr[0];
    int maxElement = arr[0];
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxIndex = i;
        }
    }

    // Знаходимо добуток елементів між мінімальним і максимальним елементами
    int product = 1;
    int startIndex = minIndex < maxIndex ? minIndex : maxIndex;
    int endIndex = minIndex < maxIndex ? maxIndex : minIndex;

    for (int i = startIndex + 1; i < endIndex; i++) {
        product *= arr[i];
    }

    printf("Мінімальний елемент: %d на позиції %d.\n"
           "Максимальний елемент: %d на позиції %d.\n"
           "Добуток елементів між мінімальним і максимальним: %d", minElement, minIndex+1, maxElement, maxIndex+1, product);

    delete[] arr;

    return 0;
}

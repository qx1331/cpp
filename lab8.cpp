#include <iostream>

using namespace std;

// Рекурсивна
int fibonacciRecursive(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

// Звичайна
int fibonacciDefault(int n) {
    int a = 0, b = 1;
    if (n == 0) {
        return a;
    } else if (n == 1) {
        return b;
    } else {
        for (int i = 2; i <= n; i++) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
}

int main() {
    int n;
    cout << "Введіть n: ";
    cin >> n;

    cout << "Результат (рекурсивної): " << fibonacciRecursive(n) << endl;
    cout << "Результат (звичайної): " << fibonacciDefault(n) << endl;

    return 0;
}

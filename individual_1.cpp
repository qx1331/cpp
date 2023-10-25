#include <iostream>

using namespace std;

class Int {
private:
    int value;

public:
    // Конструктор за замовчуванням, ініціалізує об'єкт нулем
    Int() : value(0) {}

    // Конструктор з параметром для ініціалізації об'єкта цілим числом
    Int(int val) : value(val) {}

    // Метод для виводу значення на екран
    void display() const {
        cout << value << endl;
    }

    // Операція додавання
    Int operator+(const Int &other) {
        return {value + other.value};
    }

    // Операція віднімання
    Int operator-(const Int &other) {
        return {value - other.value};
    }

    // Операція множення
    Int operator*(const Int &other) {
        return {value * other.value};
    }

    // Операція ділення
    Int operator/(const Int &other) {
        if (other.value == 0) {
            cerr << "Error: Division zero" << endl;
            return {};
        }
        return {value / other.value};
    }
};

int main() {
    int value_a, value_b;
    cout << "Enter values: " << endl;
    cin >> value_a; cin >> value_b;
    Int a(value_a);
    Int b(value_b);

    cout << "a = ";
    a.display();

    cout << "b = ";
    b.display();

    Int sum = a + b;
    cout << "a + b = ";
    sum.display();

    Int diff = a - b;
    cout << "a - b = ";
    diff.display();

    Int product = a * b;
    cout << "a * b = ";
    product.display();

    Int quotient = a / b;
    cout << "a / b = ";
    quotient.display();

    return 0;
}

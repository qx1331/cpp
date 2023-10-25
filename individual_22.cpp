#include <iostream>

class Fraction {
public:
    int numerator;
    int denominator;

    // Конструктор за замовчуванням (створює дріб 0/1)
    Fraction() : numerator(0), denominator(1) {}

    // Конструктор з параметрами (створює дріб з чисельником і знаменником)
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            std::cerr << "err: denominator cant be zero." << std::endl;
            numerator = 0;
            denominator = 1;
        }
    }

    // Операція віднімання
    Fraction operator-(const Fraction& other) const {
        int commonDenom = denominator * other.denominator;
        int resultNum = (numerator * other.denominator) - (other.numerator * denominator);
        return Fraction(resultNum, commonDenom);
    }

    // Операція множення
    Fraction operator*(const Fraction& other) const {
        int resultNum = numerator * other.numerator;
        int resultDenom = denominator * other.denominator;
        return Fraction(resultNum, resultDenom);
    }

    // Оператор порівняння (менше)
    bool operator<(const Fraction& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }
};

int main() {
    int f_num, f_denom, s_num, s_denom;
    std::cout << "Enter num and denom for the first frac: " << std::endl;
    std::cin >> f_num; std::cin >> f_denom;
    std::cout << "Enter num and denom for the second frac: " << std::endl;
    std::cin >> s_num; std::cin >> s_denom;
    Fraction a(f_num, f_denom);
    Fraction b(s_num, s_denom);

    // Віднімання дробів
    Fraction subtraction = a - b;
    std::cout << "Різниця a - b: " << subtraction.numerator << "/" << subtraction.denominator << std::endl;

    // Множення дробів
    Fraction multiplication = a * b;
    std::cout << "Добуток a * b: " << multiplication.numerator << "/" << multiplication.denominator << std::endl;

    // Порівняння дробів
    if (a < b) {
        std::cout << "a менше b" << std::endl;
    } else {
        std::cout << "a більше або дорівнює b" << std::endl;
    }

    return 0;
}

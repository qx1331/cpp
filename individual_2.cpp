#include <iostream>
#include <cmath>

double round_value(double num, int precision) {
    if (precision < 0) {
        std::cerr << "error: enter precision >0" << std::endl;
        return num;
    }

    double multiplier = std::pow(10.0, precision);
    double rounded = std::round(num * multiplier) / multiplier;

    return rounded;
}

int main() {
    // e.g. PI
    double value = 3.14159;

    int precision;
    std::cout << "Enter precision: " << std::endl;
    std::cin >> precision;

    double roundedValue = round_value(value, precision);

    std::cout << "first value: " << value << std::endl;
    std::cout << "final value: " << roundedValue << std::endl;

    return 0;
}

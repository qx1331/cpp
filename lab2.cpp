#include <iostream>
#include "cmath"

using namespace std;

/*
 * Сухомлин Д, кнмс-22, лаба 2, вар 13 - Створити програму обчислення вказаної величини
*/

int main() {
    double x = 17.421, y = 10.365, z = 0.828;

    double numerator = pow(y + (cbrt(x) - 1), 1.0/4.0);
    double denominator = (abs(x - y)) * (pow(sin(z), 2.0) + tan(z));
    cout << numerator/denominator;

    return 0;
}

#include <iostream>
#include "cmath"

using namespace std;

int main() {
    double x = 17.421, y = 10.365, z = 0.828;

    double numerator = pow(y + cbrt(x - 1.), 1./4.);
    double denominator = (abs(x-y)) * (pow(sin(z), 2.) + tan(z));
    cout << numerator/denominator;

    return 0;
}

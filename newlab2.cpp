#include "iostream"
#include "stdio.h"

using namespace std;

int main() {
    double money, percent;
    int years = 5;
    int months = years*12;
    cout << "Deposit: ";
    cin >> money;
    cout << "Percentage: ";
    cin >> percent;

    for (int i=0; i<=months; i++) {
        double income = (money*percent/100)/12;
        printf("Місяць %d: %f грн\n", i, income);
        money +=income;
    }
    printf("%.2f грн ви отримаєте в кінці", money);
    return 0;
}

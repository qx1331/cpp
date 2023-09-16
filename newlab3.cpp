#include "iostream"
#include "stdio.h"

using namespace std;

int main() {
    const int students = 30;
    int heights[students] = {165, 172, 175, 180, 168, 173, 176, 169, 178, 174,
                    170, 179, 171, 177, 181, 182, 183, 167, 166, 185,
                    188, 186, 187, 176, 177, 178, 172, 173, 182, 181};
    int count = 0;
    for (int i; i<students; i++) {
        int height = heights[i];
        if (height>=170 && height<=180) {
            count++;
        }
    }
    printf("%d студентів знаходиться в заданому діапазоні", count);
    return 0;
}

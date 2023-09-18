#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <fstream>

using namespace std;

struct Sportsman {
    string lastName;
    int championshipCount{};
    string teamName;
    int points{};
};

void printSportsman(Sportsman &s) {
    cout << "Прізвище: " << s.lastName << endl;
    cout << "Кількість чемпіонатів: " << s.championshipCount << endl;
    cout << "Назва команди: " << s.teamName << endl;
    cout << "Кількість балів: " << s.points << endl;
    cout << "-----------------------------" << endl;
}

void saveDataToFile(const string &filename, Sportsman *sportsmen, int n) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Не вдалося відкрити файл для запису." << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        outFile << sportsmen[i].lastName << " "
                << sportsmen[i].championshipCount << " "
                << sportsmen[i].teamName << " "
                << sportsmen[i].points << endl;
    }

    outFile.close();
}

void loadDataFromFile(const string &filename, Sportsman *sportsmen, int n) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Не вдалося відкрити файл для зчитування." << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        inFile >> sportsmen[i].lastName
               >> sportsmen[i].championshipCount
               >> sportsmen[i].teamName
               >> sportsmen[i].points;
    }

    inFile.close();
}

int main() {
    int n;
    cout << "Введіть кількість спортсменів: ";
    cin >> n;

    auto *sportsmen = new Sportsman[n];

    for (int i = 0; i < n; ++i) {
        printf("Спортсмен #%i:\n", i+1);
        cout << "Прізвище: ";
        cin >> sportsmen[i].lastName;
        cout << "Кількість чемпіонатів: ";
        cin >> sportsmen[i].championshipCount;
        cout << "Назва команди: ";
        cin >> sportsmen[i].teamName;
        cout << "Кількість балів: ";
        cin >> sportsmen[i].points;
    }

    saveDataToFile("sportsmen.txt", sportsmen, n);
    loadDataFromFile("sportsmen.txt", sportsmen, n);

    // сортування
    int choice;
    printf("\nФормат порядкування спортсменів:\n1. За прізвищем\n2. По зростанню кількості балів\n");
    cin >> choice;

    if (choice == 1) {
        for (int j = 0; j < n-1; j++) {
            for (int i = 0; i < n - j - 1; ++i) {
                if (sportsmen[i].lastName > sportsmen[i + 1].lastName) {
                    swap(sportsmen[i], sportsmen[i + 1]);
                }
            }
        }
    } else if (choice == 2) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; j++) {
                if (sportsmen[j].points > sportsmen[j + 1].points) {
                    swap(sportsmen[j], sportsmen[j + 1]);
                }
            }
        }
    }

    cout << "Інформація про всіх спортсменів:\n" << endl;
    for (int i = 0; i < n; ++i) {
        printSportsman(sportsmen[i]);
    }

    string searchTeam;
    cout << "Введіть назву команди для пошуку: ";
    cin >> searchTeam;

    bool teamFound = false;
    cout << "\nІнформація про спортсменів з команди " << searchTeam << ":" << endl;
    for (int i = 0; i < n; ++i) {
        if (sportsmen[i].teamName == searchTeam) {
            printSportsman(sportsmen[i]);
            teamFound = true;
        }
    }

    if (!teamFound) {
        cout << "Спортсмени з команди " << searchTeam << " не знайдені." << endl;
    }

    delete[] sportsmen;

    return 0;
}

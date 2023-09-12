#include <iostream>
#include <fstream>
#include <string>
#include "stdio.h"

using namespace std;

struct Student {
    string lastname_initials;
    int year;
    string group;
    int physics_grade;
    int maths_grade;
    int it_grade;
    int chemistry_grade;
    double avgGrade;
};

double calculateAvgScore(int physics, int maths, int it, int chemistry) {
    return (physics+maths+it+chemistry / 4.0);
}

int main() {
    ofstream outFile("students.txt");

    if (!outFile){
        cerr << "File not found" << endl;
        return 1;
    }

    int numOfStudents;
    cout << "Count of students: ";
    cin >> numOfStudents;

//    outFile << "Last name and initials, Year of birth, Group, Physics grade, Maths grade, IT grade, Chemistry grade, Average grade" << endl;

    Student *students = new Student[numOfStudents];

    for (int i=0; i<numOfStudents; i++){
        printf("\nData for the student #%d: \n", i+1);
        cout << "Last name and initials: ";
        cin.ignore();
        getline(cin, students[i].lastname_initials);
        cout << "Year of birth: ";
        cin >> students[i].year;
        cout << "Group: ";
        cin >> students[i].group;
        cout << "Physics grade: ";
        cin >> students[i].physics_grade;
        cout << "Maths grade: ";
        cin >> students[i].maths_grade;
        cout << "IT grade: ";
        cin >> students[i].it_grade;
        cout << "Chemistry grade: ";
        cin >> students[i].chemistry_grade;

        students[i].avgGrade = calculateAvgScore(
                students[i].physics_grade, students[i].maths_grade,
                students[i].it_grade, students[i].chemistry_grade
                );
        

        outFile << students[i].lastname_initials << ", " << students[i].year << ", " << students[i].group
        << ", " << students[i].physics_grade << ", " << students[i].maths_grade << ", " << students[i].it_grade << ", "
        << students[i].chemistry_grade << ", " << students[i].avgGrade << endl;
    }
    
    outFile.close();

    char startLetter;
    cout << "\nEnter the letter with which the line should begin: ";
    cin >> startLetter;

    ifstream inFile("students.txt");
    if (!inFile){
        cerr << "File not found" << endl;
        return 1;
    }

    printf("List of excellent students with lastnames which starting with a letter %c: \n", startLetter);
    string line;
    getline(inFile, line);

    while (getline(inFile, line)) {
        string lastName = line.substr(0, line.find(','));
        if (lastName[0] == startLetter) {
            cout << line << endl;
        }
    }

    inFile.close();

    delete[] students;

    return 0;
}

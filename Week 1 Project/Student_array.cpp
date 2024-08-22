#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    const int numStudents = 53;

    string names[numStudents];
    int ages[numStudents];
    double gpas[numStudents];

    ifstream infile("arr_data.txt");
    if (!infile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int i = 0;
    while (getline(infile, line) && i < numStudents) {
        istringstream iss(line);
        iss >> names[i] >> ages[i] >> gpas[i];
        i++;
    }
    infile.close();

    // Calculate average GPA
    double sumGPA = 0;
    for (int i = 0; i < numStudents; i++) {
        sumGPA += gpas[i];
    }
    double averageGPA = sumGPA / numStudents;
    cout << "Average GPA: " << averageGPA << endl;

    // Find the highest GPA
    double highestGPA = gpas[0];
    for (int i = 1; i < numStudents; i++) {
        if (gpas[i] > highestGPA) {
            highestGPA = gpas[i];
        }
    }

    cout << "Highest GPA: ";
    bool first = true;
    for (int i = 0; i < numStudents; i++) {
        if (gpas[i] == highestGPA) {
            if (!first) {
                cout << ", ";
            }
            cout << names[i];
            first = false;
        }
    }
    cout << " (" << highestGPA << ")" << endl;

    // Find the oldest and youngest students
    int oldestAge = ages[0];
    int youngestAge = ages[0];
    for (int i = 1; i < numStudents; i++) {
        if (ages[i] > oldestAge) {
            oldestAge = ages[i];
        }
        if (ages[i] < youngestAge) {
            youngestAge = ages[i];
        }
    }

    cout << "Oldest Students: ";
    bool firstOldest = true;
    for (int i = 0; i < numStudents; i++) {
        if (ages[i] == oldestAge) {
            if (!firstOldest) {
                cout << ", ";
            }
            cout << names[i];
            firstOldest = false;
        }
    }
    cout << " (" << oldestAge << " years)" << endl;

    cout << "Youngest Students: ";
    bool firstYoungest = true;
    for (int i = 0; i < numStudents; i++) {
        if (ages[i] == youngestAge) {
            if (!firstYoungest) {
                cout << ", ";
            }
            cout << names[i];
            firstYoungest = false;
        }
    }
    cout << " (" << youngestAge << " years)" << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
    const int numStudents = 53;

    string names[numStudents] = {"John", "Jane", "Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Hank",
                                 "Ivy", "Jack", "Karen", "Leo", "Mona", "Nina", "Oscar", "Paul", "Quinn", "Rita",
                                 "Sam", "Tina", "Uma", "Vince", "Walt", "Xena", "Yara", "Zane", "Amy", "Ben",
                                 "Cindy", "Derek", "Elena", "Fred", "Gina", "Hugo", "Isla", "Jake", "Lara", "Mike",
                                 "Nora", "Omar", "Pia", "Quinn", "Ralph", "Sara", "Troy", "Una", "Vera", "Will",
                                 "Xander", "Yvonne", "Zack"};
    
    int ages[numStudents] = {20, 22, 19, 21, 23, 20, 22, 24, 21, 22,
                             20, 23, 19, 22, 21, 20, 23, 24, 22, 21,
                             20, 23, 24, 21, 22, 20, 23, 24, 21, 22,
                             20, 23, 24, 21, 22, 23, 24, 21, 22, 20,
                             23, 24, 21, 22, 23, 24, 21, 22, 23};
    
    double gpas[numStudents] = {3.5, 3.8, 3.7, 3.2, 3.9, 3.6, 3.4, 3.1, 3.7, 3.3,
                                3.8, 3.5, 3.9, 3.6, 3.4, 3.7, 3.8, 3.2, 3.9, 3.6,
                                3.4, 3.7, 3.5, 3.3, 3.8, 3.9, 3.7, 3.5, 3.6, 3.9,
                                3.4, 3.7, 3.8, 3.6, 3.3, 3.9, 3.7, 3.4, 3.5, 3.2,
                                3.3, 3.9, 3.7, 3.5, 3.8, 3.6, 3.9, 3.8, 3.6, 3.9,
                                3.3, 3.7, 3.9};

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
    cout << " (" << (youngestAge == 0 ? 19 : youngestAge) << " years)" << endl;

    return 0;
}
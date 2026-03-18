#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

struct Student {
    int id;
    string name;
    string course;
    float gpa;
};

string getAcademicStanding(float gpa) {
    if (gpa >= 90) return "Excellent";
    else if (gpa >= 80) return "Very Good";
    else if (gpa >= 70) return "Good";
    else if (gpa >= 60) return "Passing";
    else return "Failed";
}

bool isDuplicate(Student arr[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (arr[i].id == id)
            return true;
    }
    return false;
}

void displayStudents(Student arr[], int n) {

    cout << "\nStudent Records:\n\n";

    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(20) << "Course"
         << setw(10) << "GPA"
         << setw(15) << "Standing" << endl;

    cout << string(75, '-') << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << arr[i].id
             << setw(20) << arr[i].name
             << setw(20) << arr[i].course
             << setw(10) << fixed << setprecision(2) << arr[i].gpa
             << setw(15) << getAcademicStanding(arr[i].gpa) << endl;
    }
}

int main() {
    int n;
    char choice;

    do {
        system("cls");
        cout << "Enter number of students: ";
        cin >> n;


        Student students[n];

        for (int i = 0; i < n; i++) {
            cout << "\nStudent " << i + 1 << endl;

            do {
                cout << "ID: ";
                cin >> students[i].id;

                if (isDuplicate(students, i, students[i].id))
                    cout << "ID already exists! Try again.\n\n";
                else break;

            } while (true);

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Name: ";
            getline(cin, students[i].name);

            cout << "Course: ";
            getline(cin, students[i].course);

            cout << "GPA: ";
            cin >> students[i].gpa;
        }

        displayStudents(students, n);

        cout << "\nTry again? (y/n): ";
        cin >> choice;

    } while (tolower(choice) == 'y');
        return 0;
}

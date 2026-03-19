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


            bool duplicate;
            do {
                duplicate = false;

                cout << "ID: ";
                cin >> students[i].id;

                for (int j = 0; j < i; j++) {
                    if (students[j].id == students[i].id) {
                        duplicate = true;
                        cout << "ID already exists! Try again.\n\n";
                        break;
                    }
                }

            } while (duplicate);

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Name: ";
            getline(cin, students[i].name);

            cout << "Course: ";
            getline(cin, students[i].course);

            cout << "GPA: ";
            cin >> students[i].gpa;
        }


        cout << "\nStudent Records:\n\n";

        cout << left << setw(10) << "ID"
             << setw(20) << "Name"
             << setw(20) << "Course"
             << setw(10) << "GPA"
             << setw(15) << "Standing" << endl;

        cout << string(75, '-') << endl;

        for (int i = 0; i < n; i++) {

            string standing;

            if (students[i].gpa >= 90) standing = "Excellent";
            else if (students[i].gpa >= 80) standing = "Very Good";
            else if (students[i].gpa >= 70) standing = "Good";
            else if (students[i].gpa >= 60) standing = "Passing";
            else standing = "Failed";

            cout << left << setw(10) << students[i].id
                 << setw(20) << students[i].name
                 << setw(20) << students[i].course
                 << setw(10) << fixed << setprecision(2) << students[i].gpa
                 << setw(15) << standing << endl;
        }

        cout << "\nTry again? (y/n): ";
        cin >> choice;

    } while (tolower(choice) == 'y');

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    string names[n];
    int marks[n][3];
    int total[n];

    int topperIndex = 0;
    int highestTotal = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin >> names[i];

        total[i] = 0;
        cout << "Enter marks for 3 subjects:\n";
        for (int j = 0; j < 3; j++) {
            cin >> marks[i][j];
            total[i] += marks[i][j];
        }

        if (total[i] > highestTotal) {
            highestTotal = total[i];
            topperIndex = i;
        }
    }


    cout << "\n========== STUDENT RESULTS ==========\n";
    for (int i = 0; i < n; i++) {
        cout << "\nName: " << names[i];
        cout << "\nTotal Marks: " << total[i];

        bool pass = true;
        cout << "\nStatus: ";
        for (int j = 0; j < 3; j++) {
            if (marks[i][j] < 40) {
                pass = false;
            }
        }

        if (pass)
            cout << "PASS";
        else
            cout << "FAIL";

        cout << "\nSubject-wise Weakness: ";
        bool weak = false;
        for (int j = 0; j < 3; j++) {
            if (marks[i][j] < 40) {
                cout << "Subject " << j + 1 << " ";
                weak = true;
            }
        }
        if (!weak)
            cout << "None";

        cout << "\n------------------------------------";
    }

    cout << "\n\n?? CLASS TOPPER ??";
    cout << "\nName: " << names[topperIndex];
    cout << "\nTotal Marks: " << highestTotal << endl;

    return 0;
}


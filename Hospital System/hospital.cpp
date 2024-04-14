#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int PATIENTS = 5, SPECIALIZATION = 20;

vector<vector<string>> specializations(SPECIALIZATION);

void menu() {
    cout << "Enter your choice:\n";
    cout << "1) Add new patient.\n";
    cout << "2) Print all patients.\n";
    cout << "3) Get next patients.\n";
    cout << "4) Exit.\n";
}

int getSpecialization() {
    int specialization;
    do {
        cout << "Enter specialization number (1 - " << SPECIALIZATION << "):\n";
        cin >> specialization;
        specialization--;

        if (specialization < 0 || specialization >= SPECIALIZATION) {
            cout << "Invalid specialization number. Please try again.\n";
        }
    } while (specialization < 0 || specialization >= SPECIALIZATION);

    return specialization;
}

void addPatient(int specialization) {
    if (specializations[specialization].size() >= PATIENTS) {
        cout << "Sorry, no available spots for this specialization.\n";
        return;
    }

    string name;
    cout << "Pleas enter patient name: \n";
    cin >> name;

    int status;
    cout << "Please enter patient status (0 for regular, 1 for urgent): \n";
    cin >> status;
    string patient_info = name + " (" + (status == 1 ? "urgent" : "regular") + ").";

    if (status == 1)
        specializations[specialization].insert(specializations[specialization].begin(), patient_info);
    else
        specializations[specialization].push_back(patient_info);

}

void printPatients() {
    for (int i = 0; i < SPECIALIZATION; ++i) {

        if (!specializations[i].empty()) {

            cout << "There are " << specializations[i].size() << " patients in specialization " << i + 1 << ":\n";

            for (const auto &patient: specializations[i]) {
                cout << patient << '\n';
            }

            cout << '\n';
        }

    }
}

void getPatient(int specialization) {
    if (specializations[specialization].empty()) {
        cout << "No patients for this specialization.\n";
        return;
    }

    cout << specializations[specialization].front().substr(0, specializations[specialization].front().find('('))
         << "Please go with the doctor.\n";

    specializations[specialization].erase(specializations[specialization].begin());
}

int main() {
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient(getSpecialization());
                break;
            case 2:
                printPatients();
                break;
            case 3:
                getPatient(getSpecialization());
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
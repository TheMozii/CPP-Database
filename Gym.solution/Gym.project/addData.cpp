#include "addData.h"
#include "addFunctions.h"
#include <iostream>

using namespace std;

void addDataMenu() {
    while (true) {
        cout << "\nADD DATA MENU" << endl
            << "----------------------------" << endl
            << "1 - Add Instructor" << endl
            << "2 - Add Session" << endl
            << "3 - Add Client" << endl
            << "4 - Add Exercise Machine" << endl
            << "5 - Add Equipment" << endl
            << "6 - Return to Main Menu" << endl
            << "----------------------------" << endl
            << "Your choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\nInvalid input! Please enter a number between 1 and 6." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            addInstructor();
            break;
        case 2:
            addSession();
            break;
        case 3:
            addClient();
            break;
        case 4:
            addExerciseMachine();
            break;
        case 5:
            addEquipment();
            break;
        case 6:
            return;
        default:
            cerr << "\nInvalid choice! Please try again." << endl;
        }
    }
}


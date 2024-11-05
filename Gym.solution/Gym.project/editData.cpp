#include "editData.h"
#include "editFunctions.h"
#include <iostream>

using namespace std;

void editDataMenu() {
    while (true) {
        cout << "\nEDIT DATA MENU" << endl
            << "----------------------------" << endl
            << "1 - Edit Instructor" << endl
            << "2 - Edit Session" << endl
            << "3 - Edit Client" << endl
            << "4 - Edit Exercise Machine" << endl
            << "5 - Edit Equipment" << endl
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
            editInstructor();
            break;
        case 2:
            editSession();
            break;
        case 3:
            editClient();
            break;
        case 4:
            editExerciseMachine();
            break;
        case 5:
            editEquipment();
            break;
        case 6:
            return;
        default:
            cerr << "\nInvalid choice! Please try again." << endl;
        }
    }
}


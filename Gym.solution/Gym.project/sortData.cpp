#include "sortData.h"
#include "sortById.h"
#include "sortByName.h"
#include "sortSessionsByTime.h"
#include <iostream>

using namespace std;

void sortDataMenu() {
    while (true) {
        cout << "\nSORT DATA MENU" << endl
            << "----------------------------" << endl
            << "1 - Sort All Records by ID" << endl
            << "2 - Sort All Records by Name (A-Z)" << endl
            << "3 - Sort Sessions by Start Time" << endl
            << "4 - Return to Main Menu" << endl
            << "----------------------------" << endl
            << "Your choice: ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\nInvalid input! Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            sortById();
            break;
        case 2:
            sortByName();
            break;
        case 3:
            sortSessionsByTime();
            break;
        case 4:
            return;
        default:
            cerr << "\nInvalid choice! Please try again." << endl;
        }
    }
}
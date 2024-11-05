#include "searchData.h"
#include "searchByID.h"
#include "searchByText.h"
#include "searchByDateRange.h"
#include <iostream>

using namespace std;

void searchDataMenu() {
    while (true) {
        cout << "\nSEARCH DATA MENU" << endl
            << "----------------------------" << endl
            << "1 - Search by ID" << endl
            << "2 - Search by Name/Surname" << endl
            << "3 - Search by Session Date Range" << endl
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
            searchByID();
            break;
        case 2:
            searchByText();
            break;
        case 3:
           searchByDateRange();
            break;
        case 4:
            return;
        default:
            cerr << "\nInvalid choice! Please try again." << endl;
        }
    }
}
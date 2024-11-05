#include "calculData.h"
#include "countAllRecords.h"
#include "countRecordsByFile.h"
#include "countSameNamesAcrossFiles.h"
#include "calculateTimeLeftForSessions.h"
#include <iostream>

using namespace std;

void calculMenu() {
    while (true) {
        cout << "\nCALCULATIONS MENU" << endl
            << "----------------------------" << endl
            << "1 - Count All Records" << endl
            << "2 - Count Records by File" << endl
            << "3 - Count Same Names Across Files" << endl
            << "4 - Calculate Time Left for Sessions" << endl
            << "5 - Return to Main Menu" << endl
            << "----------------------------" << endl
            << "Your choice: ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\nInvalid input! Please enter a number between 1 and 5." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            countAllRecords();
            break;
        case 2:
            countRecordsByFile();
            break;
        case 3:
            countSameNamesAcrossFiles();
            break;
        case 4:
            calculateTimeLeftForSessions();
            break;
        case 5:
            return;
        default:
            cerr << "\nInvalid choice! Please try again." << endl;
        }
    }
}


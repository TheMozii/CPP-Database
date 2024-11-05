#include "deleteData.h"
#include "DataStructures.h"  
#include "displayDataInfo.h"
#include "deleteByID.h"
#include "yesNoConform.h"
#include "deleteSortedBy.h"
#include <iostream>

using namespace std;

void deleteDataMenu() {
    while (true) {
        cout << "\nDELETE DATA MENU" << endl
            << "----------------------------" << endl
            << "1 - Delete by ID" << endl
            << "2 - Delete all records of a type" << endl
            << "3 - Delete data sorted by criteria" << endl
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
            deleteRecordById();
            break;
        case 2:
            deleteAllRecordsMenu();
            break;
        case 3:
            deleteDataSortedByMenu();
            break;
        case 4:
            return;
        default:
            cerr << "\nInvalid choice! Please try again." << endl;
        }
    }
}

void deleteDataSortedByMenu() {

    while (true) {
        cout << "\n--- Delete Sorted Data By ---" << endl
            << "----------------------------" << endl
            << "1 - Name" << endl
            << "2 - Surname" << endl
            << "3 - Training Type" << endl
            << "4 - Return to Delete Data Menu" << endl
            << "----------------------------" << endl
            << "Your choice: ";

        int delDataSortByChoice;
        cin >> delDataSortByChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\nInvalid input! Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (delDataSortByChoice) {
        case 1:
            deleteByName();
            break;
        case 2:
            deleteBySurname();
            break;
        case 3:
            deleteByTrainingType();
            break;
        case 4:
            return;
        default:
            cerr << "\nInvalid choice! Please try again." << endl;
        }
    }
}

#include "DataStructures.h"  
#include "displayDataInfo.h"
#include "yesNoConform.h"
#include "deleteAllByType.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

void deleteAllRecordsMenu() {
    while (true) {
        cout << "\nDELETE ALL RECORDS MENU" << endl
            << "----------------------------" << endl
            << "1 - Delete All Instructors" << endl
            << "2 - Delete All Sessions" << endl
            << "3 - Delete All Clients" << endl
            << "4 - Delete All Exercise Machines" << endl
            << "5 - Delete All Equipment" << endl
            << "6 - Return to Delete Data Menu" << endl
            << "----------------------------" << endl
            << "Your choice: ";
        int subChoice;
        cin >> subChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\nInvalid input! Please enter a number between 1 and 6." << endl;
            continue;
        }

        switch (subChoice) {
        case 1:
            deleteAllInstructors();
            break;
        case 2:
            deleteAllSessions();
            break;
        case 3:
            deleteAllClients();
            break;
        case 4:
            deleteAllExerciseMachines();
            break;
        case 5:
            deleteAllEquipment();
            break;
        case 6:
            return;
        default:
            cerr << "\nInvalid choice! Please try again." << endl;
        }
    }
}

void deleteAllInstructors() {
    cout << "\n--- Delete All Instructors ---" << endl;

    displayInstructors();

    bool confirm = getYesNoConfirmation("\nAre you sure you want to delete ALL instructors? (Y/N): ");
    if (!confirm) {
        cout << "\nOperation cancelled." << endl;
        return;
    }

    ofstream outfile("instructors.txt", ios::trunc);
    if (!outfile) {
        cerr << "\nError opening instructors.txt for writing." << endl;
        return;
    }

    outfile.close();

    cout << "\nAll instructors deleted successfully!" << endl << endl;

    displayInstructors();
}

void deleteAllSessions() {
    cout << "\n--- Delete All Sessions ---" << endl;

    displaySessions();

    bool confirm = getYesNoConfirmation("\nAre you sure you want to delete ALL instructors? (Y/N): ");
    if (!confirm) {
        cout << "\nOperation cancelled." << endl;
        return;
    }

    ofstream outfile("sessions.txt", ios::trunc);
    if (!outfile) {
        cerr << "\nError opening sessions.txt for writing." << endl;
        return;
    }

    outfile.close();

    cout << "\nAll sessions deleted successfully!" << endl << endl;

    displaySessions();
}

void deleteAllClients() {
    cout << "\n--- Delete All Clients ---" << endl;

    displayClients();

    bool confirm = getYesNoConfirmation("\nAre you sure you want to delete ALL instructors? (Y/N): ");
    if (!confirm) {
        cout << "\nOperation cancelled." << endl;
        return;
    }

    ofstream outfile("clients.txt", ios::trunc);
    if (!outfile) {
        cerr << "\nError opening clients.txt for writing." << endl;
        return;
    }

    outfile.close();

    cout << "\nAll clients deleted successfully!" << endl << endl;

    displayClients();
}

void deleteAllExerciseMachines() {
    cout << "\n--- Delete All Exercise Machines ---" << endl;

    displayExerciseMachines();

    bool confirm = getYesNoConfirmation("\nAre you sure you want to delete ALL instructors? (Y/N): ");
    if (!confirm) {
        cout << "\nOperation cancelled." << endl;
        return;
    }

    ofstream outfile("exerciseMachines.txt", ios::trunc);
    if (!outfile) {
        cerr << "\nError opening exerciseMachines.txt for writing." << endl;
        return;
    }

    outfile.close();

    cout << "\nAll exercise machines deleted successfully!" << endl << endl;

    displayExerciseMachines();
}

void deleteAllEquipment() {
    cout << "\n--- Delete All Equipment ---" << endl;

    displayEquipment();

    bool confirm = getYesNoConfirmation("\nAre you sure you want to delete ALL instructors? (Y/N): ");
    if (!confirm) {
        cout << "\nOperation cancelled." << endl;
        return;
    }

    ofstream outfile("equipment.txt", ios::trunc);
    if (!outfile) {
        cerr << "\nError opening equipment.txt for writing." << endl;
        return;
    }

    outfile.close();

    cout << "\nAll equipment deleted successfully!" << endl << endl;

    displayEquipment();
}
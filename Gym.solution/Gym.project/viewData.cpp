#include "viewData.h"
#include "displayDataInfo.h"
#include <iostream>    

using namespace std;


void viewDataMenu() {
	while (true) {
		cout << "\nVIEW DATA MENU" << endl
			<< "----------------------------" << endl
			<< "1 - View All Data" << endl
			<< "2 - View Part of Data" << endl
			<< "3 - Return to Main Menu" << endl
			<< "----------------------------" << endl
			<< "Your choice: ";

		int viewChoice;
		cin >> viewChoice;


		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "\nInvalid input! Please enter a number between 1 and 3." << endl;
			continue;
		}

		switch (viewChoice) {
		case 1:
			displayAllData();
			break;
		case 2:
			viewPartialData();
			break;
		case 3:
			return;
		default:
			cerr << "\nInvalid choice! Please try again." << endl;
		}
	}
}

void viewPartialData() {
	while (true) {
		cout << "\nVIEW PART OF DATA" << endl
			<< "----------------------------" << endl
			<< "1 - Instructors" << endl
			<< "2 - Sessions" << endl
			<< "3 - Clients" << endl
			<< "4 - Exercise Machines" << endl
			<< "5 - Equipment" << endl
			<< "6 - Return to View Data Menu" << endl
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
			displayInstructors();
			break;
		case 2:
			displaySessions();
			break;
		case 3:
			displayClients();
			break;
		case 4:
			displayExerciseMachines();
			break;
		case 5:
			displayEquipment();
			break;
		case 6:
			return;
		default:
			cerr << "\nInvalid choice! Please try again." << endl;
		}
	}
}

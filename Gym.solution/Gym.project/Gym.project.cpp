#include "viewData.h"
#include "addData.h"
#include "editData.h"
#include "deleteData.h"
#include "searchData.h"
#include "sortData.h"
#include "calculData.h"
#include <iostream>

using namespace std;

enum Options { VIEW = 1, ADD, EDIT, DELETE, SEARCH, SORT, CALCUL, EXIT };

int mainMenu()
{
    cout << "\n MAIN MENU" << endl
        << "----------------------------" << endl
        << "1 - View data" << endl
        << "2 - Add data" << endl
        << "3 - Edit data" << endl
        << "4 - Delete data" << endl
        << "5 - Search" << endl
        << "6 - Sort data" << endl
        << "7 - Calculations" << endl
        << "8 - Exit" << endl
        << "----------------------------" << endl
        << "Your choice: ";

    int mainMenuOp;
    cin >> mainMenuOp;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\nInvalid input! Please enter a number between 1 and 6." << endl;
        return mainMenu();
    }

    return mainMenuOp;
}

int main(int argc, char** argv) {
    int choice;

    while (1) {
        choice = mainMenu();
        if (choice == EXIT)
            break;

        switch (choice) {
        case VIEW:
            viewDataMenu();
            break;
        case ADD:
            addDataMenu();
            break;
        case EDIT:
            editDataMenu();
            break;
        case DELETE:
            deleteDataMenu();
            break;
        case SEARCH:
            searchDataMenu();
            break;
        case SORT:
            sortDataMenu();
            break;
        case CALCUL:
            calculMenu();
            break;
        default:
            cerr << "\nInvalid choice! Please try again." << endl;
            break;
        }
    }

    cout << "\nExiting the application. Goodbye!" << endl;
    return 0;
}

#include "yesNoConform.h"
#include <iostream>

using namespace std;

bool getYesNoConfirmation(const string& prompt) {
    while (true) {
        cout << prompt;
        char input;
        cin >> input;
        input = tolower(input);
        if (input == 'y') {
            return true;
        }
        else if (input == 'n') {
            return false;
        }
        else {
            cout << "\nInvalid input! Please enter Y or N.\n" << endl;
        }
    }
}

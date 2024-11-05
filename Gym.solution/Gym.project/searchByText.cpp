#include "DataStructures.h"  
#include "displayDataInfo.h"
#include "searchByText.h"
#include "split.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

void searchByText() {
    cout << "\n--- Search by Name/Surnam ---" << endl;
    cout << "Choose the field to search by:" << endl
        << "1 - Name" << endl
        << "2 - Surname" << endl
        << "Your choice: ";
    int fieldChoice;
    cin >> fieldChoice;

    if (cin.fail() || (fieldChoice != 1 && fieldChoice != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\nInvalid input! Please enter 1 or 2." << endl;
        return;
    }

    cin.ignore();

    string searchTerm;
    if (fieldChoice == 1) {
        cout << "Enter the Name to search: ";
        getline(cin, searchTerm);
        while (searchTerm.empty()) {
            cout << "Name cannot be empty. Please enter Name: ";
            getline(cin, searchTerm);
        }
    }
    else {
        cout << "Enter the Surname to search: ";
        getline(cin, searchTerm);
        while (searchTerm.empty()) {
            cout << "Surname cannot be empty. Please enter Surname: ";
            getline(cin, searchTerm);
        }
    }

    bool anyFound = false;

    ifstream infileInstructors("instructors.txt");
    if (infileInstructors) {
        string line;
        vector<Instructor> instructorsFound;

        while (getline(infileInstructors, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ',');
            if (tokens.size() < 4) continue;

            Instructor instr;
            try {
                instr.id = stoi(tokens[0]);
            }
            catch (...) { continue; }
            instr.surname = tokens[1];
            instr.name = tokens[2];
            instr.trainingType = tokens[3];

            if ((fieldChoice == 1 && instr.name == searchTerm) ||
                (fieldChoice == 2 && instr.surname == searchTerm)) {
                instructorsFound.push_back(instr);
            }
        }
        infileInstructors.close();

        if (!instructorsFound.empty()) {
            cout << "\n--- Instructors Matching " <<
                (fieldChoice == 1 ? "Name" : "Surname") << " '" << searchTerm << "' ---" << endl;
            cout << left
                << setw(10) << "Code"
                << setw(20) << "Surname"
                << setw(20) << "Name"
                << setw(25) << "Training Type" << endl;
            cout << string(75, '-') << endl;

            for (const auto& instr : instructorsFound) {
                cout << left
                    << setw(10) << instr.id
                    << setw(20) << instr.surname
                    << setw(20) << instr.name
                    << setw(25) << instr.trainingType << endl;
            }
            anyFound = true;
        }
    }
    else {
        cout << "Error opening instructors.txt." << endl;
    }

    ifstream infileSessions("sessions.txt");
    if (infileSessions) {
        string line;
        vector<Session> sessionsFound;

        while (getline(infileSessions, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ',');
            if (tokens.size() < 5) continue;

            Session sess;
            try {
                sess.id = stoi(tokens[0]);
            }
            catch (...) { continue; }
            sess.name = tokens[1];
            sess.startDateTime = tokens[2];
            sess.endDateTime = tokens[3];
            sess.trainer = tokens[4];

            if (fieldChoice == 1 && sess.trainer == searchTerm) {
                sessionsFound.push_back(sess);
            }
        }
        infileSessions.close();

        if (!sessionsFound.empty()) {
            cout << "\n--- Sessions Matching " <<
                (fieldChoice == 1 ? "Name" : "Surname") << " '" << searchTerm << "' ---" << endl;
            cout << left
                << setw(10) << "ID"
                << setw(25) << "Name"
                << setw(25) << "Start Date/Time"
                << setw(25) << "End Date/Time"
                << setw(20) << "Trainer" << endl;
            cout << string(105, '-') << endl;

            for (const auto& sess : sessionsFound) {
                cout << left
                    << setw(10) << sess.id
                    << setw(25) << sess.name
                    << setw(25) << sess.startDateTime
                    << setw(25) << sess.endDateTime
                    << setw(20) << sess.trainer << endl;
            }
            anyFound = true;
        }
    }
    else {
        cout << "Error opening sessions.txt." << endl;
    }

    ifstream infileClients("clients.txt");
    if (infileClients) {
        string line;
        vector<Client> clientsFound;

        while (getline(infileClients, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ',');
            if (tokens.size() < 3) continue;

            Client client;
            try {
                client.id = stoi(tokens[0]);
            }
            catch (...) { continue; }
            client.surname = tokens[1];
            client.name = tokens[2];

            if ((fieldChoice == 1 && client.name == searchTerm) ||
                (fieldChoice == 2 && client.surname == searchTerm)) {
                clientsFound.push_back(client);
            }
        }
        infileClients.close();

        if (!clientsFound.empty()) {
            cout << "\n--- Clients Matching " <<
                (fieldChoice == 1 ? "Name" : "Surname") << " '" << searchTerm << "' ---" << endl;
            cout << left
                << setw(10) << "ID"
                << setw(20) << "Surname"
                << setw(20) << "Name" << endl;
            cout << string(50, '-') << endl;

            for (const auto& client : clientsFound) {
                cout << left
                    << setw(10) << client.id
                    << setw(20) << client.surname
                    << setw(20) << client.name << endl;
            }
            anyFound = true;
        }
    }
    else {
        cout << "Error opening clients.txt." << endl;
    }

    ifstream infileMachines("exerciseMachines.txt");
    if (infileMachines) {
        string line;
        vector<ExerciseMachine> machinesFound;

        while (getline(infileMachines, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ',');
            if (tokens.size() < 3) continue;

            ExerciseMachine machine;
            try {
                machine.id = stoi(tokens[0]);
            }
            catch (...) { continue; }
            machine.name = tokens[1];
            machine.type = tokens[2];

            if ((fieldChoice == 1 && machine.name == searchTerm) ||
                (fieldChoice == 2 && machine.type == searchTerm)) {
                machinesFound.push_back(machine);
            }
        }
        infileMachines.close();

        if (!machinesFound.empty()) {
            cout << "\n--- Exercise Machines Matching " <<
                (fieldChoice == 1 ? "Name" : "Type") << " '" << searchTerm << "' ---" << endl;
            cout << left
                << setw(10) << "ID"
                << setw(25) << "Name"
                << setw(20) << "Type" << endl;
            cout << string(55, '-') << endl;

            for (const auto& machine : machinesFound) {
                cout << left
                    << setw(10) << machine.id
                    << setw(25) << machine.name
                    << setw(20) << machine.type << endl;
            }
            anyFound = true;
        }
    }
    else {
        cout << "Error opening exerciseMachines.txt." << endl;
    }

    ifstream infileEquipment("equipment.txt");
    if (infileEquipment) {
        string line;
        vector<Equipment> equipmentsFound;

        while (getline(infileEquipment, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ',');
            if (tokens.size() < 3) continue;

            Equipment eq;
            try {
                eq.id = stoi(tokens[0]);
            }
            catch (...) { continue; }
            eq.name = tokens[1];
            eq.type = tokens[2];

            if ((fieldChoice == 1 && eq.name == searchTerm) ||
                (fieldChoice == 2 && eq.type == searchTerm)) {
                equipmentsFound.push_back(eq);
            }
        }
        infileEquipment.close();

        if (!equipmentsFound.empty()) {
            cout << "\n--- Equipment Matching " <<
                (fieldChoice == 1 ? "Name" : "Type") << " '" << searchTerm << "' ---" << endl;
            cout << left
                << setw(10) << "ID"
                << setw(25) << "Name"
                << setw(20) << "Type" << endl;
            cout << string(55, '-') << endl;

            for (const auto& eq : equipmentsFound) {
                cout << left
                    << setw(10) << eq.id
                    << setw(25) << eq.name
                    << setw(20) << eq.type << endl;
            }
            anyFound = true;
        }
    }
    else {
        cout << "Error opening equipment.txt." << endl;
    }

    if (!anyFound) {
        cout << "\nNo records found matching the search criteria." << endl;
    }
}
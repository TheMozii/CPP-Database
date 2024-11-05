#include "displayDataInfo.h"
#include "split.h" 
#include "DataStructures.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void displayInstructors(){
    cout << "\n--- Instructors ---\n" << endl;
    ifstream infileInstructors("instructors.txt");
    if (infileInstructors) {
        string line;
        bool hasData = false;

        cout << left
            << setw(10) << "ID"
            << setw(20) << "Surname"
            << setw(20) << "Name"
            << setw(25) << "Training Type" << endl;
        cout << string(75, '-') << endl;

        while (getline(infileInstructors, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ',');
            if (tokens.size() < 4) continue;

            Instructor instr;
            instr.id = stoi(tokens[0]);
            instr.surname = tokens[1];
            instr.name = tokens[2];
            instr.trainingType = tokens[3];

            cout << left
                << setw(10) << instr.id
                << setw(20) << instr.surname
                << setw(20) << instr.name
                << setw(25) << instr.trainingType << endl;
            hasData = true;
        }

        if (!hasData) {
            cout << "No instructors found." << endl;
        }
        infileInstructors.close();
    }
    else {
        cout << "Error opening instructors.txt." << endl;
    }
}

void displaySessions(){
cout << "\n--- Sessions ---\n" << endl;
ifstream infileSessions("sessions.txt");
if (infileSessions) {
    string line;
    bool hasData = false;

    cout << left
        << setw(10) << "ID"
        << setw(25) << "Name"
        << setw(25) << "Start Date/Time"
        << setw(25) << "End Date/Time"
        << setw(20) << "Trainer" << endl;
    cout << string(105, '-') << endl;

    while (getline(infileSessions, line)) {
        if (line.empty()) continue;
        vector<string> tokens = split(line, ',');
        if (tokens.size() < 5) continue;

        Session sess;
        sess.id = stoi(tokens[0]);
        sess.name = tokens[1];
        sess.startDateTime = tokens[2];
        sess.endDateTime = tokens[3];
        sess.trainer = tokens[4];

        cout << left
            << setw(10) << sess.id
            << setw(25) << sess.name
            << setw(25) << sess.startDateTime
            << setw(25) << sess.endDateTime
            << setw(20) << sess.trainer << endl;
        hasData = true;
    }

    if (!hasData) {
        cout << "No sessions found." << endl;
    }
    infileSessions.close();
}
else {
    cout << "Error opening sessions.txt." << endl;
}
}
void displayClients(){
    cout << "\n--- Clients ---\n" << endl;
    ifstream infileClients("clients.txt");
    if (infileClients) {
        string line;
        bool hasData = false;

        cout << left
            << setw(10) << "ID"
            << setw(20) << "Surname"
            << setw(20) << "Name" << endl;
        cout << string(50, '-') << endl;

        while (getline(infileClients, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ',');
            if (tokens.size() < 3) continue;

            Client client;
            client.id = stoi(tokens[0]);
            client.surname = tokens[1];
            client.name = tokens[2];

            cout << left
                << setw(10) << client.id
                << setw(20) << client.surname
                << setw(20) << client.name << endl;
            hasData = true;
        }

        if (!hasData) {
            cout << "No clients found." << endl;
        }
        infileClients.close();
    }
    else {
        cout << "Error opening clients.txt." << endl;
    }
}
void displayExerciseMachines(){
    cout << "\n--- Exercise Machines ---\n" << endl;
    ifstream infileMachines("exerciseMachines.txt");
    if (infileMachines) {
        string line;
        bool hasData = false;

        cout << left
            << setw(10) << "ID"
            << setw(25) << "Name"
            << setw(20) << "Training Type" << endl;
        cout << string(55, '-') << endl;

        while (getline(infileMachines, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ',');
            if (tokens.size() < 3) continue;

            ExerciseMachine machine;
            machine.id = stoi(tokens[0]);
            machine.name = tokens[1];
            machine.type = tokens[2];

            cout << left
                << setw(10) << machine.id
                << setw(25) << machine.name
                << setw(20) << machine.type << endl;
            hasData = true;
        }

        if (!hasData) {
            cout << "No exercise machines found." << endl;
        }
        infileMachines.close();
    }
    else {
        cout << "Error opening exerciseMachines.txt." << endl;
    }
}
void displayEquipment(){
    cout << "\n--- Equipment ---\n" << endl;
    ifstream infileEquipment("equipment.txt");
    if (infileEquipment) {
        string line;
        bool hasData = false;

        cout << left
            << setw(10) << "ID"
            << setw(25) << "Name"
            << setw(20) << "Training Type" << endl;
        cout << string(55, '-') << endl;

        while (getline(infileEquipment, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ',');
            if (tokens.size() < 3) continue;

            Equipment eq;
            eq.id = stoi(tokens[0]);
            eq.name = tokens[1];
            eq.type = tokens[2];

            cout << left
                << setw(10) << eq.id
                << setw(25) << eq.name
                << setw(20) << eq.type << endl;
            hasData = true;
        }

        if (!hasData) {
            cout << "No equipment found." << endl;
        }
        infileEquipment.close();
    }
    else {
        cout << "\nError opening equipment.txt.\n" << endl;
    }
}

void displayAllData() {
    cout << "\n*** ALL DATA ***" << endl;
    displayInstructors();
    displaySessions();
    displayClients();
    displayExerciseMachines();
    displayEquipment();
    cout << "\n*** End of All Data ***\n" << endl;
}


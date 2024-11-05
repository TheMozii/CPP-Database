#include "addFunctions.h"
#include "DataStructures.h"
#include "validation.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int getNextId(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        return 1;
    }

    string line;
    int lastId = 0;
    while (getline(infile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        int currentId = stoi(token);
        if (currentId > lastId) {
            lastId = currentId;
        }
    }
    infile.close();
    return lastId + 1;
}

void addInstructor() {
    Instructor instr;
    cout << "\n--- Add New Instructor ---" << endl;

    instr.id = getNextId("instructors.txt");
    cout << "Assigned Code: " << instr.id << endl;

    cout << "Enter Surname: ";
    cin.ignore();
    getline(cin, instr.surname);
    while (instr.surname.empty() || containsNumber(instr.surname)) {
        cout << "Surname cannot be empty or contain numbers. Please enter a valid Surname: ";
        getline(cin, instr.surname);
    }

    cout << "Enter Name: ";
    getline(cin, instr.name);
    while (instr.name.empty() || containsNumber(instr.name)) {
        cout << "Name cannot be empty or contain numbers. Please enter a valid Name: ";
        getline(cin, instr.name);
    }

    cout << "Enter Training Type: ";
    getline(cin, instr.trainingType);
    while (instr.trainingType.empty() || containsNumber(instr.trainingType)) {
        cout << "Training Type cannot be empty or contain numbers. Please enter a valid Training Type: ";
        getline(cin, instr.trainingType);
    }

    ofstream outfile("instructors.txt", ios::app);
    if (!outfile) {
        cerr << "Error opening instructors.txt for writing." << endl;
        return;
    }

    outfile << instr.id << ","
        << instr.surname << ","
        << instr.name << ","
        << instr.trainingType << endl;

    outfile.close();

    cout << "Instructor added successfully!" << endl;
}

void addSession() {
    Session sess;
    cout << "\n--- Add New Session ---" << endl;

    sess.id = getNextId("sessions.txt");
    cout << "Assigned ID: " << sess.id << endl;

    cout << "Enter Session Name: ";
    cin.ignore();
    getline(cin, sess.name);
    while (sess.name.empty() || containsNumber(sess.name)) {
        cout << "Session Name cannot be empty. Please enter Session Name: ";
        getline(cin, sess.name);
    }

    cout << "Enter Start Date and Time (YYYY-MM-DD HH:MM): ";
    getline(cin, sess.startDateTime);
    while (!isValidDateTime(sess.startDateTime)) {
        cout << "Invalid format. Please enter Start Date/Time in the format YYYY-MM-DD HH:MM: ";
        getline(cin, sess.startDateTime);
    }

    cout << "Enter End Date and Time (YYYY-MM-DD HH:MM): ";
    getline(cin, sess.endDateTime);
    while (!isValidDateTime(sess.endDateTime) || sess.endDateTime <= sess.startDateTime) {
        cout << "Invalid format or end time is before start time. Please enter End Date/Time in the format YYYY-MM-DD HH:MM: ";
        getline(cin, sess.endDateTime);
    }

    cout << "Enter Trainer's Surname: ";
    getline(cin, sess.trainer);
    while (sess.trainer.empty() || containsNumber(sess.trainer)) {
        cout << "Trainer's Surname cannot be empty or contain numbers. Please enter a valid Surname: ";
        getline(cin, sess.trainer);
    }

    ofstream outfile("sessions.txt", ios::app);
    if (!outfile) {
        cerr << "Error opening sessions.txt for writing." << endl;
        return;
    }

    outfile << sess.id << ","
        << sess.name << ","
        << sess.startDateTime << ","
        << sess.endDateTime << ","
        << sess.trainer << endl;

    outfile.close();

    cout << "Session added successfully!" << endl;
}

void addClient() {
    Client client;
    cout << "\n--- Add New Client ---" << endl;

    client.id = getNextId("clients.txt");
    cout << "Assigned ID: " << client.id << endl;

    cout << "Enter Surname: ";
    cin.ignore();
    getline(cin, client.surname);
    while (client.surname.empty() || containsNumber(client.surname)) {
        cout << "Surname cannot be empty or contain numbers. Please enter a valid Surname: ";
        getline(cin, client.surname);
    }

    cout << "Enter Name: ";
    getline(cin, client.name);
    while (client.name.empty() || containsNumber(client.name)) {
        cout << "Name cannot be empty or contain numbers. Please enter a valid Name: ";
        getline(cin, client.name);
    }

    ofstream outfile("clients.txt", ios::app);
    if (!outfile) {
        cerr << "Error opening clients.txt for writing." << endl;
        return;
    }

    outfile << client.id << ","
        << client.surname << ","
        << client.name << endl;

    outfile.close();

    cout << "Client added successfully!" << endl;
}

void addExerciseMachine() {
    ExerciseMachine machine;
    cout << "\n--- Add New Exercise Machine ---" << endl;

    machine.id = getNextId("exerciseMachines.txt");
    cout << "Assigned ID: " << machine.id << endl;

    cout << "Enter Machine Name: ";
    cin.ignore();
    getline(cin, machine.name);
    while (machine.name.empty()) {
        cout << "Machine Name cannot be empty. Please enter a valid Machine Name: ";
        getline(cin, machine.name);
    }

    cout << "Enter Machine Type: ";
    getline(cin, machine.type);
    while (machine.type.empty()) {
        cout << "Machine Type cannot be empty. Please enter a valid Machine Type: ";
        getline(cin, machine.type);
    }

    ofstream outfile("exerciseMachines.txt", ios::app);
    if (!outfile) {
        cerr << "Error opening exerciseMachines.txt for writing." << endl;
        return;
    }

    outfile << machine.id << ","
        << machine.name << ","
        << machine.type << endl;

    outfile.close();

    cout << "Exercise Machine added successfully!" << endl;
}

void addEquipment() {
    Equipment eq;
    cout << "\n--- Add New Equipment ---" << endl;

    eq.id = getNextId("equipment.txt");
    cout << "Assigned ID: " << eq.id << endl;

    cout << "Enter Equipment Name: ";
    cin.ignore();
    getline(cin, eq.name);
    while (eq.name.empty()) {
        cout << "Equipment Name cannot be empty. Please enter a valid Equipment Name: ";
        getline(cin, eq.name);
    }

    cout << "Enter Equipment Type: ";
    getline(cin, eq.type);
    while (eq.type.empty()) {
        cout << "Equipment Type cannot be empty. Please enter a valid Equipment Type: ";
        getline(cin, eq.type);
    }

    ofstream outfile("equipment.txt", ios::app);
    if (!outfile) {
        cerr << "Error opening equipment.txt for writing." << endl;
        return;
    }

    outfile << eq.id << ","
        << eq.name << ","
        << eq.type << endl;

    outfile.close();

    cout << "Equipment added successfully!" << endl;
}

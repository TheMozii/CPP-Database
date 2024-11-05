#include "split.h" 
#include "DataStructures.h"
#include "displayDataInfo.h"
#include "editFunctions.h"
#include "validation.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void editInstructor() {
    cout << "\n--- Edit Instructor ---" << endl;

    displayInstructors();

    cout << "\nEnter Instructor ID to edit: ";
    int id;
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\nInvalid input! Instructor ID must be a number." << endl;
        return;
    }

    ifstream infile("instructors.txt");
    if (!infile) {
        cerr << "Error opening instructors.txt" << endl;
        return;
    }

    vector<Instructor> instructors;
    string line;
    bool found = false;
    Instructor instr;

    while (getline(infile, line)) {
        if (line.empty()) continue;
        vector<string> tokens = split(line, ',');
        if (tokens.size() < 4) continue;

        Instructor current;
        current.id = stoi(tokens[0]);
        current.surname = tokens[1];
        current.name = tokens[2];
        current.trainingType = tokens[3];

        if (current.id == id) {
            found = true;
            instr = current;
        }
        instructors.push_back(current);
    }
    infile.close();

    if (!found) {
        cout << "Instructor with ID " << id << " not found." << endl;
        return;
    }

    cout << "\nCurrent Details:" << endl;
    cout << "ID: " << instr.id << endl;
    cout << "Surname: " << instr.surname << endl;
    cout << "Name: " << instr.name << endl;
    cout << "Training Type: " << instr.trainingType << endl;

    cin.ignore();

    string input;

    cout << "\nEnter new Surname (or press Enter to keep \"" << instr.surname << "\"): ";
    getline(cin, input);
    if (!input.empty()) {
        while (containsNumber(input)) {
            cout << "Surname cannot contain numbers. Please enter a valid Surname or press Enter to skip: ";
            getline(cin, input);
        }
        instr.surname = input;
    }
  
    cout << "Enter new Name (or press Enter to keep \"" << instr.name << "\"): ";
    getline(cin, input);
    if (!input.empty()) {
        while (containsNumber(input)) {
            cout << "Name cannot contain numbers. Please enter a valid Name or press Enter to skip: ";
            getline(cin, input);
        }
        instr.name = input;
    }

    cout << "Enter new Training Type (or press Enter to keep \"" << instr.trainingType << "\"): ";
    getline(cin, input);
    if (!input.empty()) {
        while (containsNumber(input)) {
            cout << "Training type cannot contain numbers. Please enter a valid Training type or press Enter to skip: ";
            getline(cin, input);
        }
        instr.trainingType = input;
    }

    for (auto& item : instructors) {
        if (item.id == id) {
            item = instr;
            break;
        }
    }

    ofstream outfile("instructors.txt", ios::trunc);
    if (!outfile) {
        cerr << "Error opening instructors.txt for writing." << endl;
        return;
    }

    for (const auto& item : instructors) {
        outfile << item.id << ","
            << item.surname << ","
            << item.name << ","
            << item.trainingType << endl;
    }
    outfile.close();

    cout << "\nInstructor updated successfully!" << endl;
}

void editSession() {
    cout << "\n--- Edit Session ---" << endl;

    displaySessions();

    cout << "\nEnter Session ID to edit: ";
    int id;
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\nInvalid input! Session ID must be a number." << endl;
        return;
    }

    ifstream infile("sessions.txt");
    if (!infile) {
        cerr << "Error opening sessions.txt" << endl;
        return;
    }

    vector<Session> sessions;
    string line;
    bool found = false;
    Session sess;

    while (getline(infile, line)) {
        if (line.empty()) continue;
        vector<string> tokens = split(line, ',');
        if (tokens.size() < 5) continue;

        Session current;
        current.id = stoi(tokens[0]);
        current.name = tokens[1];
        current.startDateTime = tokens[2];
        current.endDateTime = tokens[3];
        current.trainer = tokens[4];

        if (current.id == id) {
            found = true;
            sess = current;
        }
        sessions.push_back(current);
    }
    infile.close();

    if (!found) {
        cout << "Session with ID " << id << " not found." << endl;
        return;
    }

    cout << "\nCurrent Details:" << endl;
    cout << "ID: " << sess.id << endl;
    cout << "Name: " << sess.name << endl;
    cout << "Start Date/Time: " << sess.startDateTime << endl;
    cout << "End Date/Time: " << sess.endDateTime << endl;
    cout << "Trainer: " << sess.trainer << endl;

    cin.ignore();

    string input;

    cout << "\nEnter new Name (or press Enter to keep \"" << sess.name << "\"): ";
    getline(cin, input);
    if (!input.empty()) {
        while (containsNumber(input)) {
            cout << "Name cannot contain numbers. Please enter a valid Name or press Enter to skip: ";
            getline(cin, input);
        }
        sess.name = input;
    }

    cout << "Enter new Start Date/Time (YYYY-MM-DD HH:MM) (or press Enter to keep \"" << sess.startDateTime << "\"): ";
    getline(cin, input);
    if (!input.empty()) {
        while (!isValidDateTime(input)) {
            cout << "Invalid date format. Please enter Start Date/Time in the format YYYY-MM-DD HH:MM or press Enter to skip: ";
            getline(cin, input);
        }
        sess.startDateTime = input;
    }

    cout << "Enter new End Date/Time (YYYY-MM-DD HH:MM) (or press Enter to keep \"" << sess.endDateTime << "\"): ";
    getline(cin, input);
    if (!input.empty()) {
        while (!isValidDateTime(input) || input <= sess.startDateTime) {
            cout << "Invalid format or end time must be after start time. Please enter End Date/Time in the format YYYY-MM-DD HH:MM or press Enter to skip: ";
            getline(cin, input);
        }
        sess.endDateTime = input;
    }

    cout << "Enter new Trainer's Surname (or press Enter to keep \"" << sess.trainer << "\"): ";
    getline(cin, input);
    if (!input.empty()) {
        while (containsNumber(input)) {
            cout << "Trainer's Surname cannot contain numbers. Please enter a valid Surname or press Enter to skip: ";
            getline(cin, input);
        }
        sess.trainer = input;
    }

    for (auto& item : sessions) {
        if (item.id == id) {
            item = sess;
            break;
        }
    }

    ofstream outfile("sessions.txt", ios::trunc);
    if (!outfile) {
        cerr << "Error opening sessions.txt for writing." << endl;
        return;
    }

    for (const auto& item : sessions) {
        outfile << item.id << ","
            << item.name << ","
            << item.startDateTime << ","
            << item.endDateTime << ","
            << item.trainer << endl;
    }
    outfile.close();

    cout << "\nSession updated successfully!" << endl;
}

void editClient() {
    cout << "\n--- Edit Client ---" << endl;

    displayClients();

    cout << "\nEnter Client ID to edit: ";
    int id;
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\nInvalid input! Client ID must be a number." << endl;
        return;
    }

    ifstream infile("clients.txt");
    if (!infile) {
        cerr << "Error opening clients.txt" << endl;
        return;
    }

    vector<Client> clients;
    string line;
    bool found = false;
    Client client;

    while (getline(infile, line)) {
        if (line.empty()) continue;
        vector<string> tokens = split(line, ',');
        if (tokens.size() < 3) continue;

        Client current;
        current.id = stoi(tokens[0]);
        current.surname = tokens[1];
        current.name = tokens[2];

        if (current.id == id) {
            found = true;
            client = current;
        }
        clients.push_back(current);
    }
    infile.close();

    if (!found) {
        cout << "Client with ID " << id << " not found." << endl;
        return;
    }

    cout << "\nCurrent Details:" << endl;
    cout << "ID: " << client.id << endl;
    cout << "Surname: " << client.surname << endl;
    cout << "Name: " << client.name << endl;

    cin.ignore();

    string input;

    cout << "\nEnter new Surname (or press Enter to keep \"" << client.surname << "\"): ";
    getline(cin, input);
    if (!input.empty()) {
        while (containsNumber(input)) {
            cout << "Surname cannot contain numbers. Please enter a valid Surname or press Enter to skip: ";
            getline(cin, input);
        }
        client.surname = input;
    }


    cout << "Enter new Name (or press Enter to keep \"" << client.name << "\"): ";
    getline(cin, input);
    if (!input.empty()) {
        while (containsNumber(input)) {
            cout << "Name cannot contain numbers. Please enter a valid Name or press Enter to skip: ";
            getline(cin, input);
        }
        client.name = input;
    }

    for (auto& item : clients) {
        if (item.id == id) {
            item = client;
            break;
        }
    }

    ofstream outfile("clients.txt", ios::trunc);
    if (!outfile) {
        cerr << "Error opening clients.txt for writing." << endl;
        return;
    }

    for (const auto& item : clients) {
        outfile << item.id << ","
            << item.surname << ","
            << item.name << endl;
    }
    outfile.close();

    cout << "\nClient updated successfully!" << endl;
}

void editExerciseMachine() {
    cout << "\n--- Edit Exercise Machine ---" << endl;

    displayExerciseMachines();

    cout << "\nEnter Exercise Machine ID to edit: ";
    int id;
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\nInvalid input! Machine ID must be a number." << endl;
        return;
    }

    ifstream infile("exerciseMachines.txt");
    if (!infile) {
        cerr << "Error opening exerciseMachines.txt" << endl;
        return;
    }

    vector<ExerciseMachine> machines;
    string line;
    bool found = false;
    ExerciseMachine machine;

    while (getline(infile, line)) {
        if (line.empty()) continue;
        vector<string> tokens = split(line, ',');
        if (tokens.size() < 3) continue;

        ExerciseMachine current;
        current.id = stoi(tokens[0]);
        current.name = tokens[1];
        current.type = tokens[2];

        if (current.id == id) {
            found = true;
            machine = current;
        }
        machines.push_back(current);
    }
    infile.close();

    if (!found) {
        cout << "Exercise Machine with ID " << id << " not found." << endl;
        return;
    }

    cout << "\nCurrent Details:" << endl;
    cout << "ID: " << machine.id << endl;
    cout << "Name: " << machine.name << endl;
    cout << "Type: " << machine.type << endl;

    cin.ignore();

    string input;

    cout << "\nEnter new Name (or press Enter to keep \"" << machine.name << "\"): ";
    getline(cin, input);
    if (!input.empty()) machine.name = input;

    cout << "Enter new Type (or press Enter to keep \"" << machine.type << "\"): ";
    getline(cin, input);
    if (!input.empty()) machine.type = input;

    for (auto& item : machines) {
        if (item.id == id) {
            item = machine;
            break;
        }
    }

    ofstream outfile("exerciseMachines.txt", ios::trunc);
    if (!outfile) {
        cerr << "Error opening exerciseMachines.txt for writing." << endl;
        return;
    }

    for (const auto& item : machines) {
        outfile << item.id << ","
            << item.name << ","
            << item.type << endl;
    }
    outfile.close();

    cout << "\nExercise Machine updated successfully!" << endl;
}

void editEquipment() {
    cout << "\n--- Edit Equipment ---" << endl;

    displayEquipment();

    cout << "\nEnter Equipment ID to edit: ";
    int id;
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\nInvalid input! Equipment ID must be a number." << endl;
        return;
    }

    ifstream infile("equipment.txt");
    if (!infile) {
        cerr << "Error opening equipment.txt" << endl;
        return;
    }

    vector<Equipment> equipments;
    string line;
    bool found = false;
    Equipment eq;

    while (getline(infile, line)) {
        if (line.empty()) continue;
        vector<string> tokens = split(line, ',');
        if (tokens.size() < 3) continue;

        Equipment current;
        current.id = stoi(tokens[0]);
        current.name = tokens[1];
        current.type = tokens[2];

        if (current.id == id) {
            found = true;
            eq = current;
        }
        equipments.push_back(current);
    }
    infile.close();

    if (!found) {
        cout << "Equipment with ID " << id << " not found." << endl;
        return;
    }

    cout << "\nCurrent Details:" << endl;
    cout << "ID: " << eq.id << endl;
    cout << "Name: " << eq.name << endl;
    cout << "Type: " << eq.type << endl;

    cin.ignore();

    string input;

    cout << "\nEnter new Name (or press Enter to keep \"" << eq.name << "\"): ";
    getline(cin, input);
    if (!input.empty()) eq.name = input;

    cout << "Enter new Type (or press Enter to keep \"" << eq.type << "\"): ";
    getline(cin, input);
    if (!input.empty()) eq.type = input;

    for (auto& item : equipments) {
        if (item.id == id) {
            item = eq;
            break;
        }
    }

    ofstream outfile("equipment.txt", ios::trunc);
    if (!outfile) {
        cerr << "Error opening equipment.txt for writing." << endl;
        return;
    }

    for (const auto& item : equipments) {
        outfile << item.id << ","
            << item.name << ","
            << item.type << endl;
    }
    outfile.close();

    cout << "\nEquipment updated successfully!" << endl;
}

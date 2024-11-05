#include "DataStructures.h"  
#include "displayDataInfo.h"
#include "yesNoConform.h"
#include "deleteSortedBy.h"
#include "split.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



bool deleteFromFile(const string& filename, const string& type,
    int fieldIndex, const string& value) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening " << filename << "." << endl;
        return false;
    }

    string line;
    vector<string> records;
    bool recordFound = false;

    while (getline(infile, line)) {
        if (line.empty()) continue;
        vector<string> tokens = split(line, ',');
        if (tokens.size() <= fieldIndex) continue;

        string fieldValue = tokens[fieldIndex];
        if (fieldValue == value) {
            recordFound = true;
            continue;
        }

        records.push_back(line);
    }
    infile.close();

    if (recordFound) {
        string fieldName;
        if (type == "Instructor") {
            if (fieldIndex == 1) fieldName = "Surname";
            else if (fieldIndex == 2) fieldName = "Name";
            else if (fieldIndex == 3) fieldName = "Training Type";
        }
        else if (type == "Session") {
            if (fieldIndex == 1) fieldName = "Name";
            else if (fieldIndex == 4) fieldName = "Trainer";
        }
        else if (type == "Client") {
            if (fieldIndex == 1) fieldName = "Surname";
            else if (fieldIndex == 2) fieldName = "Name";
        }
        else if (type == "Exercise Machine") {
            if (fieldIndex == 1) fieldName = "Name";
            else if (fieldIndex == 2) fieldName = "Training Type";
        }
        else if (type == "Equipment") {
            if (fieldIndex == 1) fieldName = "Name";
            else if (fieldIndex == 2) fieldName = "Type";
        }

        string prompt = "\nAre you sure you want to delete all " + type +
            " records where " + fieldName + " is '" + value + "'? (Y/N): ";
        bool confirm = getYesNoConfirmation(string(prompt));
        if (!confirm) {
            cout << "\nOperation cancelled." << endl;
            return false;
        }

        ofstream outfile(filename, ios::trunc);
        if (!outfile) {
            cerr << "Error opening " << filename << " for writing." << endl;
            return false;
        }

        for (const auto& rec : records) {
            outfile << rec << endl;
        }
        outfile.close();

        cout << "\nAll " << type << " records with " << fieldName << " '" << value << "' deleted successfully!" << endl;
        return true;
    }

    return false;
}

void deleteByName() {
    cout << "\n--- Delete Records by Name ---" << endl;
    cin.ignore();
    displayAllData();
    string name;
    cout << "Enter the Name to delete: ";
    getline(cin, name);

    while (name.empty()) {
        cout << "Name cannot be empty. Please enter Name: ";
        getline(cin, name);
    }

    bool anyDeleted = false;

    anyDeleted |= deleteFromFile("instructors.txt", "Instructor", 2, name);

    anyDeleted |= deleteFromFile("sessions.txt", "Session", 4, name);

    anyDeleted |= deleteFromFile("clients.txt", "Client", 2, name);

    anyDeleted |= deleteFromFile("exerciseMachines.txt", "Exercise Machine", 1, name);

    anyDeleted |= deleteFromFile("equipment.txt", "Equipment", 1, name);

    if (!anyDeleted) {
        cout << "\nNo records found with Name '" << name << "'." << endl;
    }

    displayAllData();
}

void deleteBySurname() {
    cout << "\n--- Delete Records by Surname ---" << endl;
    cin.ignore();
    string surname;
    cout << "Enter the Surname to delete: ";
    getline(cin, surname);

    while (surname.empty()) {
        cout << "Surname cannot be empty. Please enter Surname: ";
        getline(cin, surname);
    }

    bool anyDeleted = false;

    anyDeleted |= deleteFromFile("instructors.txt", "Instructor", 1, surname);

    anyDeleted |= deleteFromFile("sessions.txt", "Session", 4, surname);

    anyDeleted |= deleteFromFile("clients.txt", "Client", 1, surname);

    if (!anyDeleted) {
        cout << "\nNo records found with Surname '" << surname << "'." << endl;
    }
}

void deleteByTrainingType() {
    cout << "\n--- Delete Records by Training Type ---" << endl;
    cin.ignore();
    string trainingType;
    cout << "Enter the Training Type to delete: ";
    getline(cin, trainingType);

    while (trainingType.empty()) {
        cout << "Training Type cannot be empty. Please enter Training Type: ";
        getline(cin, trainingType);
    }

    bool anyDeleted = false;

    anyDeleted |= deleteFromFile("instructors.txt", "Instructor", 3, trainingType);

    anyDeleted |= deleteFromFile("exerciseMachines.txt", "Exercise Machine", 2, trainingType);

    anyDeleted |= deleteFromFile("equipment.txt", "Equipment", 2, trainingType);

    if (!anyDeleted) {
        cout << "\nNo records found with Training Type '" << trainingType << "'." << endl;
    }
}
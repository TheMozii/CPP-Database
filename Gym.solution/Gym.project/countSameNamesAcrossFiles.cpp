#include "split.h"
#include "DataStructures.h"
#include "readAllRecords.h"
#include "countSameNamesAcrossFiles.h"
#include "toLowerCase.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void countSameNamesAcrossFiles() {
    cout << "\n--- Count Same Names Across Files ---" << endl;

    cout << "Enter the name to search: ";
    string targetName;
    cin.ignore();
    getline(cin, targetName);
    targetName = toLowerCase(targetName);

    vector<string> dataFiles = {
        "instructors.txt",
        "sessions.txt",
        "clients.txt",
        "exerciseMachines.txt",
        "equipment.txt"
    };

    int count = 0;

    for (const auto& filename : dataFiles) {
        vector<string> records = readAllRecords(filename);
        for (const auto& record : records) {
            vector<string> tokens = split(record, ',');
            for (const auto& token : tokens) {
                if (toLowerCase(token) == targetName) {
                    count++;
                }
            }
        }
    }

    cout << "The name \"" << targetName << "\" appears " << count << " times across all files." << endl;
}

#include "sortFunctions.h"
#include "DataStructures.h"
#include "displayDataInfo.h"
#include "readAllRecords.h"
#include "sortFunctions.h"
#include "split.h"
#include "sortById.h"
#include "writeSortedDataBack.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sortById() {
    cout << "\n--- Sort All Records by ID ---" << endl;

    vector<string> dataFiles = {
        "instructors.txt",
        "sessions.txt",
        "clients.txt",
        "exerciseMachines.txt",
        "equipment.txt"
    };

    auto compareById = [](const string& a, const string& b) -> bool {
        vector<string> tokensA = split(a, ',');
        vector<string> tokensB = split(b, ',');

        if (tokensA.empty() || tokensB.empty()) return false;

        try {
            int idA = stoi(tokensA[0]);
            int idB = stoi(tokensB[0]);
            return idA < idB;
        }
        catch (...) {
  
            return false;
        }
        };

    for (const auto& filename : dataFiles) {
        vector<string> records = readAllRecords(filename);
        if (records.empty()) continue;

        numbersSort(records, compareById);

        writeAllRecords(filename, records);
        

        cout << "Sorted " << filename << " by ID successfully." << endl;
    }

    cout << "All records sorted by ID successfully!" << endl;

    displayAllData();
}

#include "sortFunctions.h"
#include "DataStructures.h"
#include "displayDataInfo.h"
#include "readAllRecords.h"
#include "sortFunctions.h"
#include "split.h"
#include "sortByName.h"
#include "writeSortedDataBack.h"
#include "toLowerCase.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sortByName() {
    cout << "\n--- Sort All Records by Name (A-Z) ---" << endl;

    vector<string> dataFiles = {
        "instructors.txt",
        "sessions.txt",
        "clients.txt",
        "exerciseMachines.txt",
        "equipment.txt"
    };

    auto compareByName = [](const string& a, const string& b) -> bool {
        vector<string> tokensA = split(a, ',');
        vector<string> tokensB = split(b, ',');

        if (tokensA.size() < 2 || tokensB.size() < 2) {

            return false;
        }

        string nameA = tokensA[1];
        string nameB = tokensB[1];

        string lowerA = toLowerCase(nameA);
        string lowerB = toLowerCase(nameB);

        return lowerA < lowerB;
        };

    for (const auto& filename : dataFiles) {
        vector<string> records = readAllRecords(filename);
        if (records.empty()) continue;

        stringSort(records, compareByName);

        writeAllRecords(filename, records);

        cout << "Sorted " << filename << " by Name successfully." << endl;
    }

    cout << "All records sorted by Name successfully!" << endl;

    displayAllData();
}

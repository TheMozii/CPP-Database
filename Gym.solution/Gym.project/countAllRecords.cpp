#include "DataStructures.h"
#include "readAllRecords.h"
#include "countAllRecords.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void countAllRecords() {
    cout << "\n--- Count All Records ---" << endl;

    vector<string> dataFiles = {
        "instructors.txt",
        "sessions.txt",
        "clients.txt",
        "exerciseMachines.txt",
        "equipment.txt"
    };

    int totalCount = 0;

    for (const auto& filename : dataFiles) {
        vector<string> records = readAllRecords(filename);
        totalCount += records.size();
    }

    cout << "Total number of records across all files: " << totalCount << endl;
}

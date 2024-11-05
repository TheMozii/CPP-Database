#include "DataStructures.h"
#include "readAllRecords.h"
#include "countRecordsByFile.h"
#include <iostream>
#include <vector>
#include <string>


using namespace std;

void countRecordsByFile() {
    cout << "\n--- Count Records by File ---" << endl;

    vector<string> dataFiles = {
        "instructors.txt",
        "sessions.txt",
        "clients.txt",
        "exerciseMachines.txt",
        "equipment.txt"
    };

    for (const auto& filename : dataFiles) {
        vector<string> records = readAllRecords(filename);
        cout << filename << ": " << records.size() << " records" << endl;
    }
}

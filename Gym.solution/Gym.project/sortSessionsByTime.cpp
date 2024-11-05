#include "sortFunctions.h"
#include "DataStructures.h"
#include "displayDataInfo.h"
#include "readAllRecords.h"
#include "sortFunctions.h"
#include "split.h"
#include "sortByName.h"
#include "writeSortedDataBack.h"
#include "toLowerCase.h"
#include "sortSessionsByTime.h"
#include <iostream>
#include <vector>
#include <string>


using namespace std;

void sortSessionsByTime() {
    cout << "\n--- Sort Sessions by Start Time ---" << endl;

    string filename = "sessions.txt";
    vector<string> records = readAllRecords(filename);
    if (records.empty()) {
        cout << "No sessions to sort." << endl;
        return;
    }

    auto compareByStartTime = [](const string& a, const string& b) -> bool {
        vector<string> tokensA = split(a, ',');
        vector<string> tokensB = split(b, ',');

        if (tokensA.size() < 5 || tokensB.size() < 5) return false;

        string startA = tokensA[2]; 
        string startB = tokensB[2];

        return startA < startB;
        };

    numbersSort(records, compareByStartTime);

    writeAllRecords(filename, records);

    cout << "Sorted " << filename << " by Start Time successfully." << endl;
    cout << "All sessions sorted by Start Time successfully!" << endl;

    displaySessions();
}

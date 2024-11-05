#include "readAllRecords.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> readAllRecords(const string& filename) {
    vector<string> records;
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening " << filename << "." << endl;
        return records;
    }

    string line;
    while (getline(infile, line)) {
        if (!line.empty()) {
            records.push_back(line);
        }
    }
    infile.close();
    return records;
}

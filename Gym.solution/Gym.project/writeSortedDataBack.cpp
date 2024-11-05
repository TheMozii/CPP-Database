#include "writeSortedDataBack.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

 
using namespace std;

void writeAllRecords(const string& filename, const vector<string>& records) {
    ofstream outfile(filename, ios::trunc);
    if (!outfile) {
        cerr << "Error opening " << filename << " for writing." << endl;
        return;
    }

    for (const auto& record : records) {
        outfile << record << endl;
    }
    outfile.close();
}

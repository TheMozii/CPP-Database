#include "sortFunctions.h"
#include "DataStructures.h"
#include "displayDataInfo.h"
#include <vector>
#include <string>

using namespace std;

void numbersSort(vector<string>& records, bool (*compare)(const string&, const string&)) {
    int n = records.size();
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (compare(records[j], records[min])) {
                min = j;
            }
        }
        if (min != i) {
            string temp = records[i];
            records[i] = records[min];
            records[min] = temp;
        }
    }
}

void stringSort(vector<string>& records, bool (*compare)(const string&, const string&)) {
    int n = records.size();
    for (int i = 1; i < n; ++i) {
        string key = records[i];
        int j = i - 1;
        while (j >= 0 && compare(key, records[j])) {
            records[j + 1] = records[j];
            j = j - 1;
        }
        records[j + 1] = key;
    }
}

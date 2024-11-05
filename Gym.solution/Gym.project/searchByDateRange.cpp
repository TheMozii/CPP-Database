#include "DataStructures.h"  
#include "searchByDateRange.h"
#include "split.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void searchByDateRange() {
    cout << "\n--- Search Sessions by Date Range ---" << endl;
    cout << "Enter the start date (YYYY-MM-DD): ";
    string startDate;
    cin >> startDate;

    cout << "Enter the end date (YYYY-MM-DD): ";
    string endDate;
    cin >> endDate;

    auto isValidDate = [](const string& date) -> bool {
        if (date.size() != 10) return false;
        if (date[4] != '-' || date[7] != '-') return false;
        for (int i = 0; i < date.size(); ++i) {
            if (i == 4 || i == 7) continue;
            if (!isdigit(date[i])) return false;
        }
        return true;
        };

    if (!isValidDate(startDate) || !isValidDate(endDate)) {
        cerr << "\nInvalid date format! Please use YYYY-MM-DD." << endl;
        return;
    }

    auto convertDate = [](const string& date) -> int {
        string numericDate = "";
        for (char c : date) {
            if (c != '-') numericDate += c;
        }
        return stoi(numericDate);
        };

    int start = convertDate(startDate);
    int end = convertDate(endDate);

    if (start > end) {
        cerr << "\nStart date cannot be after end date." << endl;
        return;
    }

    bool anyFound = false;

    ifstream infileSessions("sessions.txt");
    if (infileSessions) {
        string line;
        vector<Session> sessionsFound;

        while (getline(infileSessions, line)) {
            if (line.empty()) continue;
            vector<string> tokens = split(line, ',');
            if (tokens.size() < 5) continue;

            Session sess;
            try {
                sess.id = stoi(tokens[0]);
            }
            catch (...) { continue; }
            sess.name = tokens[1];
            sess.startDateTime = tokens[2];
            sess.endDateTime = tokens[3];
            sess.trainer = tokens[4];

            if (sess.startDateTime.size() < 10) continue;
            string sessDateStr = sess.startDateTime.substr(0, 10);
            if (!isValidDate(sessDateStr)) continue;
            int sessDate = convertDate(sessDateStr);

            if (sessDate >= start && sessDate <= end) {
                sessionsFound.push_back(sess);
            }
        }
        infileSessions.close();

        if (!sessionsFound.empty()) {
            cout << "\n--- Sessions Between " << startDate << " and " << endDate << " ---" << endl;
            cout << left
                << setw(10) << "ID"
                << setw(25) << "Name"
                << setw(25) << "Start Date/Time"
                << setw(25) << "End Date/Time"
                << setw(20) << "Trainer" << endl;
            cout << string(105, '-') << endl;

            for (const auto& sess : sessionsFound) {
                cout << left
                    << setw(10) << sess.id
                    << setw(25) << sess.name
                    << setw(25) << sess.startDateTime
                    << setw(25) << sess.endDateTime
                    << setw(20) << sess.trainer << endl;
            }
            anyFound = true;
        }
    }
    else {
        cout << "Error opening sessions.txt." << endl;
    }

    if (!anyFound) {
        cout << "\nNo sessions found within the specified date range." << endl;
    }
}
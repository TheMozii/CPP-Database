#include "split.h"
#include "DataStructures.h"
#include "readAllRecords.h"
#include "calculateTimeLeftForSessions.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream> 

using namespace std;

void calculateTimeLeftForSessions() {
    cout << "\n--- Calculate Time Left for Sessions ---" << endl;

    vector<string> sessions = readAllRecords("sessions.txt");
    if (sessions.empty()) {
        cout << "No sessions found." << endl;
        return;
    }

    time_t now = time(0);
    tm localtm;

    if (localtime_s(&localtm, &now) != 0) {
        cerr << "Error converting time." << endl;
        return;
    }

    for (const auto& session : sessions) {
        vector<string> tokens = split(session, ',');
        if (tokens.size() < 3) continue;

        string startTime = tokens[2];

        tm startTm = {};
        istringstream ss(startTime);
        ss >> get_time(&startTm, "%Y-%m-%d %H:%M");
        time_t startEpoch = mktime(&startTm);

        double secondsLeft = difftime(startEpoch, now);
        if (secondsLeft > 0) {
            int daysLeft = static_cast<int>(secondsLeft) / (3600 * 24);
            int hoursLeft = (static_cast<int>(secondsLeft) % (3600 * 24)) / 3600;
            int minutesLeft = (static_cast<int>(secondsLeft) - (daysLeft * 24 * 3600) - (hoursLeft * 3600)) / 60;

            if (daysLeft > 0) {
                cout << "Session \"" << tokens[1] << "\" starts in " << daysLeft << " day(s), " << hoursLeft << " hour(s), and " << minutesLeft << " minute(s)." << endl;
            }
            else {
                cout << "Session \"" << tokens[1] << "\" starts in " << hoursLeft << " hour(s) and " << minutesLeft << " minute(s)." << endl;
            }
        }
        else {
            cout << "Session \"" << tokens[1] << "\" has already started or is in progress." << endl;
        }
    }
}

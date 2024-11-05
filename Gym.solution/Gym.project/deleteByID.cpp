#include "split.h"
#include "DataStructures.h" 
#include "displayDataInfo.h"
#include "deleteByID.h"
#include "yesNoConform.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void deleteRecordById() {
    cout << "\n--- Delete Record by ID ---" << endl;

    displayAllData();

    cout << "\nEnter the ID of the record you want to delete: ";
    int id;
    cin >> id;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "\nInvalid input! ID must be a number." << endl;
        return;
    }

    bool found = false;
    string dataType;

    {
        ifstream infile("instructors.txt");
        if (infile) {
            string line;
            vector<Instructor> instructors;
            while (getline(infile, line)) {
                if (line.empty()) continue;
                vector<string> tokens = split(line, ',');
                if (tokens.size() < 4) continue;

                Instructor instr;
                instr.id = stoi(tokens[0]);
                instr.surname = tokens[1];
                instr.name = tokens[2];
                instr.trainingType = tokens[3];

                if (instr.id == id) {
                    found = true;
                    dataType = "Instructor";
                    continue;
                }

                instructors.push_back(instr);
            }
            infile.close();

            if (found) {
                bool confirm = getYesNoConfirmation("\nAre you sure you want to delete this? (Y/N): ");
                if (!confirm) {
                    cout << "\nOperation cancelled." << endl;
                    return;
                }

                ofstream outfile("instructors.txt", ios::trunc);
                if (!outfile) {
                    cerr << "\nError opening instructors.txt for writing." << endl;
                    return;
                }

                for (const auto& instr : instructors) {
                    outfile << instr.id << ","
                        << instr.surname << ","
                        << instr.name << ","
                        << instr.trainingType << endl;
                }
                outfile.close();

                cout << endl << dataType << " with ID " << id << " deleted successfully!" << endl;

                displayInstructors();

                return;
            }
        }
    }

    {
        ifstream infile("sessions.txt");
        if (infile) {
            string line;
            vector<Session> sessions;
            while (getline(infile, line)) {
                if (line.empty()) continue;
                vector<string> tokens = split(line, ',');
                if (tokens.size() < 5) continue;

                Session sess;
                sess.id = stoi(tokens[0]);
                sess.name = tokens[1];
                sess.startDateTime = tokens[2];
                sess.endDateTime = tokens[3];
                sess.trainer = tokens[4];

                if (sess.id == id) {
                    found = true;
                    dataType = "Session";
                    continue;
                }

                sessions.push_back(sess);
            }
            infile.close();

            if (found) {
                bool confirm = getYesNoConfirmation("\nAre you sure you want to delete this? (Y/N): ");
                if (!confirm) {
                    cout << "\nOperation cancelled." << endl;
                    return;
                }

                ofstream outfile("sessions.txt", ios::trunc);
                if (!outfile) {
                    cerr << "\nError opening sessions.txt for writing." << endl;
                    return;
                }

                for (const auto& sess : sessions) {
                    outfile << sess.id << ","
                        << sess.name << ","
                        << sess.startDateTime << ","
                        << sess.endDateTime << ","
                        << sess.trainer << endl;
                }
                outfile.close();

                cout << endl << dataType << " with ID " << id << " deleted successfully!" << endl;
                
                displaySessions();

                return;
            }
        }
    }

    {
        ifstream infile("clients.txt");
        if (infile) {
            string line;
            vector<Client> clients;
            while (getline(infile, line)) {
                if (line.empty()) continue;
                vector<string> tokens = split(line, ',');
                if (tokens.size() < 3) continue;

                Client client;
                client.id = stoi(tokens[0]);
                client.surname = tokens[1];
                client.name = tokens[2];

                if (client.id == id) {
                    found = true;
                    dataType = "Client";
                    continue;
                }

                clients.push_back(client);
            }
            infile.close();

            if (found) {
                bool confirm = getYesNoConfirmation("\nAre you sure you want to delete this? (Y/N): ");
                if (!confirm) {
                    cout << "\nOperation cancelled." << endl;
                    return;
                }

                ofstream outfile("clients.txt", ios::trunc);
                if (!outfile) {
                    cerr << "\nError opening clients.txt for writing." << endl;
                    return;
                }

                for (const auto& client : clients) {
                    outfile << client.id << ","
                        << client.surname << ","
                        << client.name << endl;
                }
                outfile.close();

                cout << endl << dataType << " with ID " << id << " deleted successfully!" << endl;
                
                displayClients();

                return;
            }
        }
    }

    {
        ifstream infile("exerciseMachines.txt");
        if (infile) {
            string line;
            vector<ExerciseMachine> machines;
            while (getline(infile, line)) {
                if (line.empty()) continue;
                vector<string> tokens = split(line, ',');
                if (tokens.size() < 3) continue;

                ExerciseMachine machine;
                machine.id = stoi(tokens[0]);
                machine.name = tokens[1];
                machine.type = tokens[2];

                if (machine.id == id) {
                    found = true;
                    dataType = "Exercise Machine";
                    continue;
                }

                machines.push_back(machine);
            }
            infile.close();

            if (found) {
                bool confirm = getYesNoConfirmation("\nAre you sure you want to delete this? (Y/N): ");
                if (!confirm) {
                    cout << "\nOperation cancelled." << endl;
                    return;
                }

                ofstream outfile("exerciseMachines.txt", ios::trunc);
                if (!outfile) {
                    cerr << "\nError opening exerciseMachines.txt for writing." << endl;
                    return;
                }

                for (const auto& machine : machines) {
                    outfile << machine.id << ","
                        << machine.name << ","
                        << machine.type << endl;
                }
                outfile.close();

                cout << endl << dataType << " with ID " << id << " deleted successfully!" << endl;
               
                displayExerciseMachines();
                
                return;
            }
        }
    }

    {
        ifstream infile("equipment.txt");
        if (infile) {
            string line;
            vector<Equipment> equipments;
            while (getline(infile, line)) {
                if (line.empty()) continue;
                vector<string> tokens = split(line, ',');
                if (tokens.size() < 3) continue;

                Equipment eq;
                eq.id = stoi(tokens[0]);
                eq.name = tokens[1];
                eq.type = tokens[2];

                if (eq.id == id) {
                    found = true;
                    dataType = "Equipment";
                    continue;
                }

                equipments.push_back(eq);
            }
            infile.close();

            if (found) {
                bool confirm = getYesNoConfirmation("\nAre you sure you want to delete this? (Y/N): ");
                if (!confirm) {
                    cout << "\nOperation cancelled." << endl;
                    return;
                }

                ofstream outfile("equipment.txt", ios::trunc);
                if (!outfile) {
                    cerr << "\nError opening equipment.txt for writing." << endl;
                    return;
                }

                for (const auto& eq : equipments) {
                    outfile << eq.id << ","
                        << eq.name << ","
                        << eq.type << endl;
                }
                outfile.close();

                cout << endl << dataType << " with ID " << id << " deleted successfully!" << endl;
                
                displayEquipment();
                
                return;
            }
        }
    }

    if (!found) {
        cout << "\nNo record found with ID " << id << "." << endl;
    }
}

#include "toLowerCase.h"

using namespace std;

string toLowerCase(const string& str) {
    string lowerStr = str;
    for (auto& c : lowerStr) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return lowerStr;
}

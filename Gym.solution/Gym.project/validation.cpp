#include "validation.h"
#include <regex>
#include <string>

using namespace std;


bool containsNumber(const string& input) {
    return any_of(input.begin(), input.end(), ::isdigit);
}

bool isValidDateTime(const string& dateTime) {
    regex dateTimePattern(R"(^\d{4}-\d{2}-\d{2} \d{2}:\d{2}$)");
    return regex_match(dateTime, dateTimePattern);
}
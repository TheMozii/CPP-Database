#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H

#include <vector>
#include <string>

void numbersSort(std::vector<std::string>& records, bool (*compare)(const std::string&, const std::string&));
void stringSort(std::vector<std::string>& records, bool (*compare)(const std::string&, const std::string&));

#endif // SORTFUNCTIONS_H
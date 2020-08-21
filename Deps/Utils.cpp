//
// Created by Nazar Potipaka on 21.08.2020.
//

#include "Utils.h"

// trim from start (in place)
void Utils::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
void Utils::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
std::string Utils::trim(std::string &s) {
    ltrim(s);
    rtrim(s);

    return s;
}
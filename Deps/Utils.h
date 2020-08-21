//
// Created by Nazar Potipaka on 21.08.2020.
//

#ifndef CSERVER_UTILS_H
#define CSERVER_UTILS_H

#include <string>

class Utils {
public:
    static void ltrim(std::string &s);
    static void rtrim(std::string &s);
    static std::string trim(std::string &s);
};


#endif //CSERVER_UTILS_H

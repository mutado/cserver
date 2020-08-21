//
// Created by Nazar Potipaka on 21.08.2020.
//

#ifndef CSERVER_REQUEST_H
#define CSERVER_REQUEST_H

#include <string>
#include <map>
#include <vector>
#include <iostream>

class Request {
private:
    std::map<std::string,std::string> headers;
    std::string body;
public:
    explicit Request(std::string request_str);


    std::vector<std::string> split(std::string s, std::string delimeter);
    std::string GetHeader(const std::string& key);
};


#endif //CSERVER_REQUEST_H

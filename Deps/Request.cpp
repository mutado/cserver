//
// Created by Nazar Potipaka on 21.08.2020.
//

#include "Request.h"
#include "Utils.h"

using  namespace std;

Request::Request(std::string request_str) {
    this->headers = std::map<std::string,std::string>();

    auto rows = split(request_str, "\r\n");

    //Get the first row of request
    auto first_row = split(rows[0]," ");
    rows.erase(rows.begin());

    //Get the last row of request
    body = rows.back();
    rows.pop_back();


    this->headers.insert(pair<string,string>("Method",Utils::trim(first_row[0])));
    this->headers.insert(pair<string,string>("URL",Utils::trim(first_row[1])));
    this->headers.insert(pair<string,string>("Protocol",Utils::trim(first_row[2])));

    for(string & row : rows){
        auto res = split(row,":");
        this->headers.insert(pair<string,string>(Utils::trim(res[0]),Utils::trim(res[1])));
    }

    cout<<"\nHeaders"<<endl;
    for(auto & header : this->headers){
        std::cout<<"\t"<<header.first<<'\t'<<header.second<<'\n';
    }

    cout<<"\n\nBody:\n"<<body;
}

std::vector<std::string> Request::split(std::string s, std::string delimeter) {
    size_t pos_start = 0, pos_end, delim_len = delimeter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimeter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        if (token.length() == 0){
            // Blank line in request
            // Body in next row
            // Returning
            res.push_back (s.substr (pos_start));
            return res;
        }
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

std::string Request::GetHeader(const std::string& key) {
    return this->headers[key];
}
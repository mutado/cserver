//
// Created by Nazar Potipaka on 31.08.2020.
//

#ifndef CSERVER_ROUTER_H
#define CSERVER_ROUTER_H


#include <map>
#include <functional>
#include "Response.h"
#include "Request.h"

class Router {
private:
    static std::map<std::string,std::function<Response(Request)>> routes;

public:
    Router();

    void RegisterRoute(std::string path, std::function<Response(Request)> function);
    Response ExecuteRoute(std::string path);

};


#endif //CSERVER_ROUTER_H

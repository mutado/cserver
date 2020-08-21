//
// Created by Nazar Potipaka on 10.08.2020.
//

#include <cstdio>
#include <cstring>
#include <zconf.h>
#include <iostream>
#include <arpa/inet.h>
#include "Kernel.h"
#include "../Deps/Request.h"


#define VERSION "0.001"


Kernel::Kernel() : Kernel::Kernel(80) {
}

Kernel::Kernel(int PORT) {
    this->PORT = PORT;
    server_fd = -1;
    std::cout << "Setting up server...";

    try {
        this->setup();
    }
    catch (std::exception &ex) {
        std::cout<< ex.what()<<std::endl;
    }
    std::cout << "done" << std::endl;

}

bool Kernel::run() {
    std::cout << "Running server on port: "<< this->PORT << std::endl;
    if (listen(server_fd, 3) < 0) {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int new_socket;
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        struct sockaddr_in * pV4Addr = (struct sockaddr_in*)&address;
        struct in_addr ipAddr = pV4Addr->sin_addr;
        char ip_str[INET_ADDRSTRLEN];
        inet_ntop( AF_INET, &ipAddr, ip_str, INET_ADDRSTRLEN );
        std::cout << "\n--Incoming connection from "<<ip_str<<"--\n";

        char buffer[30000] = {0};
        read(new_socket, buffer, 30000);

        Request h = Request(buffer);

        std::string response_text = "";

        std::string url = h.GetHeader("URL");

        if (url == "/"){

        }
        else if (url == "/info"){
            response_text = "cserver v"+std::string(VERSION)+ " on PORT "+std::to_string(PORT) + "\n\n";
            response_text+="Raw Request \n" + std::string(buffer);
        }




        std::string response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: "+std::to_string(response_text.length())+"\n\n"+response_text;

        write(new_socket, response.c_str(), response.length());
        close(new_socket);
        std::cout<<"\n---Connection closed---\n";
    }
}

bool Kernel::setup() {
    addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        throw "Error occured while creating socket";
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("Bind failed");
        this->PORT++;
        setup();
    }

    return true;
}



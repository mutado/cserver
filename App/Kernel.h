//
// Created by Nazar Potipaka on 10.08.2020.
//

#ifndef CSERVER_KERNEL_H
#define CSERVER_KERNEL_H


#include <netinet/in.h>
#include <stdexcept>

class Kernel {
private:
    int server_fd;
    int PORT;
    struct sockaddr_in address;
    int addrlen;

    bool setup();
public:
    Kernel();
    Kernel(int);

    bool run();
};


#endif //CSERVER_KERNEL_H

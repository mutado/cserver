#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <zconf.h>
#include "App/Kernel.h"

int main() {
    Kernel kernel = Kernel(80);
    kernel.run();
    return 0;
}

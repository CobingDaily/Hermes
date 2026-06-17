#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include "hermes.h"


int main(int argc, char** argv) {
    uint32_t port;
    HMZ_Extract_port(argc, argv, &port);

    int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {
        .sin_family = PF_INET,
    };

    while (true) {
        printf("Hello, World! [port=%d]\n", port);
        sleep(1);
        // accept();
    }

    return EXIT_SUCCESS;
}

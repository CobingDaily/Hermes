#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include "hermes.h"


#define DEFAULT_PORT 8080

void HMS_Extract_port(int argc, char** argv, uint16_t* port) {
    if (argc == 1) {
        *port = DEFAULT_PORT;
    }
    else if (argc == 2) {
        *port = atoi(argv[1]);
    }
    else if (argc > 2) {
        fprintf(stderr, "Incorrect usage:\n");
        fprintf(stderr, "  Expected: `./server <port-number>`\n");
        exit(EXIT_FAILURE);
    }
    if (*port == 0) {
        printf("[WARNING] port set to 0.\n");
    }
    return;
}

void HMS_Init_server(int* serverSocket, uint16_t* port) {
    *serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr = {
        .sin_family = PF_INET,
        .sin_port = htons(*port),
        .sin_addr.s_addr = INADDR_ANY,
    };

    bind(*serverSocket, (struct sockaddr *)&addr, sizeof(addr));

    listen(*serverSocket, 10);

    return;
}

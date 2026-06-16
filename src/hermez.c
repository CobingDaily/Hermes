#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

#include "hermez.h"


#define DEFAULT_PORT 8080

void HMZ_Extract_port(int argc, char** argv, uint32_t* port) {
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


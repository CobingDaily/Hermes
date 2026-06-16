#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

#define DEFAULT_PORT 8080

void extract_port(int argc, char** argv, uint32_t* port) {
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
    if (port == 0) {
        printf("[WARNING] port set to 0.\n");
    }
    return;
}

int main(int argc, char** argv) {
    uint32_t port;
    extract_port(argc, argv, &port);

    while (true) {
        printf("Hello, World! [port=%d]\n", port);
        sleep(1);
    }

    return EXIT_SUCCESS;
}

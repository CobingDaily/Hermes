#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

#include "hermez.h"


int main(int argc, char** argv) {
    uint32_t port;
    HMZ_Extract_port(argc, argv, &port);

    while (true) {
        printf("Hello, World! [port=%d]\n", port);
        sleep(1);
    }

    return EXIT_SUCCESS;
}

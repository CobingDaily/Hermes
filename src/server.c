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
#include "html.h"


int main(int argc, char** argv) {
    uint16_t port;
    HMS_Extract_port(argc, argv, &port);

    int serverSocket;
    HMS_Init_server(&serverSocket, &port);

    struct sockaddr_in clientAddr;
    socklen_t clientLen = sizeof(clientAddr);

    while (true) {
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientLen);
        if (clientSocket < 0) {
            perror("accept");
            continue;
        }

        serve_html(clientSocket);
        close(clientSocket);
    }

    return EXIT_SUCCESS;
}

#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "html.h"

void serve_html(int clientSocket) {
    const char *html = 
        "<!DOCTYPE html>"
        "<html><body>"
        "<h1>Hello from C!</h1>"
        "</body></html>";

    char response[1024];
    int len = snprintf(response, sizeof(response),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: %zu\r\n"
        "Connection: close\r\n"
        "\r\n"
        "%s",
        strlen(html), html
    );

    write(clientSocket, response, len);
}
